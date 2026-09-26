#include <stdio.h>
#include <sys/syscall.h>      /* Definition of SYS_* constants */
#include <unistd.h>

#define BIN_SH "/bin/sh"

const char *bin_sh = "/bin/sh";

    __attribute__((noinline))
    void gadget(void)
{
    asm volatile (
        "pop %rax\n"
        "syscall\n"
        "ret\n"
    );
}

int main(int argc, char **argv) {
    char buff[8];
    fgets(buff,500,stdin);
    // syscall(SYS_rt_sigreturn);
    return 0;
}
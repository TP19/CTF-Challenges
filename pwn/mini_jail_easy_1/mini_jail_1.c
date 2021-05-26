#define _GNU_SOURCE 1
#include <sys/sendfile.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char **argv)
{
    printf("[+] Welcome to %s!\n", argv[0]);

    puts("[+] As you might have figured out, this program will put you in a jail.");
    puts("[+] You must read the flag out of it, but who knows, maybe there is also");
    puts("[+] something inside. Good luck!\n");


    assert(strstr(argv[1], "flag") == NULL);

    int fd = open(argv[1], O_NOFOLLOW);

    char jail_path[] = "/tmp/jail-XXXXXX";
    assert(mkdtemp(jail_path) != NULL);

    assert(chroot(jail_path) == 0);

    assert(chdir("/") == 0);

    int fffd = open("/flag", O_WRONLY | O_CREAT);
    write(fffd, "FLAG{haha_it_is_fake!!!}", 30);
    close(fffd);

    void *shellcode_addr = mmap((void *)0x1337000, 0x1000, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANON, 0, 0);
    assert((unsigned char *)shellcode_addr == (unsigned char *)0x1337000);

    int actual_size = read(0, shellcode_addr, 0x1000);

    ((void(*)())shellcode_addr)();
}

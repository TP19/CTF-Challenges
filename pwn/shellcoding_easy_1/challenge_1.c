#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>

void *shellcode_mem;
size_t shellcode_size;

int main(int argc, char **argv, char **envp)
{
    assert(argc > 0);

    printf("Welcome to %s!\n", argv[0]);
    printf("\n");
    printf("You will need to make this program give you the flag. Good Luck!\n");

    for (int i = 3; i < 500; i++) close(i);
    for (char **a = argv; *a != NULL; a++) memset(*a, 0, strlen(*a));
    for (char **a = envp; *a != NULL; a++) memset(*a, 0, strlen(*a));

    shellcode_mem = mmap((void *) 0x18011000, 0x500, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANON, 0, 0);

    assert(shellcode_mem == (void *) 0x18011000);

    shellcode_size = read(0, shellcode_mem, 0x500);
    if (shellcode_size < 2) {
	printf("Why so empty? ;_;\n");
}
    else {
    puts("Executing the payload!\n");
    ((void(*)())shellcode_mem)();
}
}

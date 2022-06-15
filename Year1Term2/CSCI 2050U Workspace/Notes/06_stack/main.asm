extern printf
extern scanf
extern exit

global main

section .text

add5:
  mov rax, [rsp+8]  ; 5
  mov rax, [rsp+16]  ; 4
  mov rax, [rsp+24]  ; 3
  mov rax, [rsp+32]  ; 2
  mov rax, [rsp+40]  ; 1

  ret 40  ; mov rip, [rsp]

main:

  mov rax, 1  ; push 1 onto the stack
  push rax
  mov rax, 2  ; push 2 onto the stack
  push rax
  mov rax, 3  ; push 3 onto the stack
  push rax
  mov rax, 4  ; push 4 onto the stack
  push rax
  mov rax, 5  ; push 5 onto the stack
  push rax

  call add5

  ;  the sum is in rax

  
  ; printf("The sum is %d.\n", sum);
  mov rdi, resultFormat
  mov rsi, rax
  mov rax, 0
  push rbx
  call printf
  pop rbx



section .data
  prompt db "Enter a message: ", 0
  inputFormat db "%s", 0
  resultFormat db "The result is %s.", 0ah, 0dh, 0

  another_message db "This is a string that already has UPPERCASE letters.", 0

  a db 'a'
  z db 'z'

section .bss ; for declaring non constant variables
  message resb 100 ; exceeding the 100 character limit will begin to bleed into the adjacent memory
  

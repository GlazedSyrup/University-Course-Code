extern printf
extern scanf
extern exit

global main

section .text

main:
  ; printf("%s", "Enter a number: ");
  mov rsi, prompt
  mov rax, 0
  push rax
  call printf
  pop rax

  ; scanf("%d", &number);
  mov rdi, inputFormat
  mov rsi, message
  mov rax, 0
  push rax
  call scanf
  pop rax

  ; convert to uppercase
  mov rdi, message
  push rax
  call uppercase
  pop rax

  printTheResult:
    ; printf("The result is %s.\n", message);
    mov rdi, resultFormat
    mov rsi, message
    mov rax, 0
    push rbx
    call printf
    pop rbx

    ; exit(0)
    mov rax, 0
    ret ; return 0
    ; call exit

uppercase: ; can be before or after main, it is not important

    ; loop over every character in 'message'
    ;   change that character to uppercase (ascii math)
    ;   go to next character
    ; until we encounter a null terminator (character == 0)

  mov rsi, message
  mov bl, 'a'
  mov bh, 'z'

  nextChar:
    mov al, [rsi]

    cmp al, 0 ; check for null terminator
    je endOfString ; if null, return

    ; Check if lower
    cmp al, bl ; is it before a?
    jl skipCharacter

    cmp al, bh  ; is it after 'a'
    jg skipCharacter
    
    ; change to uppercase
    sub al, 32
    mov [rsi], al

  skipCharacter:
    inc rsi
    jmp nextChar

  endOfString:
    mov rax, 0
    ret

section .data
  prompt db "Enter a message: ", 0
  inputFormat db "%s", 0
  resultFormat db "The result is %s.", 0ah, 0dh, 0

  another_message db "This is a string that already has UPPERCASE letters.", 0

  a db 'a'
  z db 'z'

section .bss ; for declaring non constant variables
  message resb 100 ; exceeding the 100 character limit will begin to bleed into the adjacent memory
  

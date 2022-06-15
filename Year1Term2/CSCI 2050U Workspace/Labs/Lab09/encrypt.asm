extern printf
extern scanf
extern exit

global main

section .text

main:
;;;;PRINT The message prompt
    mov rdi, promptMessage
    mov rax, 0
    push rbx
    call printf
    pop rbx

;;;;TAKE in the message
    mov rdi, inputFormat
    mov rsi, message
    mov rax, 0
    push rbx
    call scanf
    pop rbx

;;;;PRINT The key prompt
    mov rdi, promptKey
    mov rax, 0
    push rbx
    call printf
    pop rbx

;;;;TAKE in the key 
    mov rdi, inputFormat
    mov rsi, key
    mov rax, 0
    push rbx
    call scanf

;;;;ENCRYPT
    mov rdi, message
    push rax
    call encrypt
    pop rax


printTheResult:
    mov rdi, encryptedText
    mov rsi, message
    mov rax, 0
    push rbx
    call printf
    pop rbx

    mov rax, 0
    ret

encrypt:
    mov rdi, message
    mov rsi, key
    mov cl, 'A' ; 65
    mov ch, 26

    shiftChar:
        mov al, [rdi] ; Current Character of message
        mov bl, [rsi] ; Current Character of key

        cmp al, 0
        je endOfString

        sub bl, cl
        add al, bl

        cmp al, 90 ;IF al (Shift+CurrentChar) > 90
        jg loopChars

        mov [rdi], al

    nextChar:
        inc rdi
        inc rsi
        jmp shiftChar

    loopChars:
        sub al, ch    
        mov [rdi], al
        jmp nextChar

    endOfString:
        mov rax, 0
        ret


section .data
    promptMessage db "Enter the message:   ", 0
    promptKey db "Enter the key:       ", 0
    inputFormat db "%s", 0
    encryptedText db "Encrypted message:   %s", 0ah, 0

section .bss ; for declaring non constant variables
    message resb 51 ; exceeding the 100 character limit will begin to bleed into the adjacent memory
    key resb 51 ; exceeding the 100 character limit will begin to bleed into the adjacent memory
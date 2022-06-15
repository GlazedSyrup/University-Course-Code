extern printf
extern scanf
extern exit

global main

section .text

main:
;;;;PRINT The name prompt
    mov rdi, promptName
    mov rax, 0
    push rbx
    call printf
    pop rbx

;;;;TAKE in the name of user
    mov rdi, inputFormat2
    mov rsi, name
    mov rax, 0
    push rbx
    call scanf
    pop rbx



;;;;PRINT The age prompt
    mov rdi, promptAge
    mov rax, 0
    push rbx
    call printf
    pop rbx

;;;;TAKE in the age of user
    mov rdi, inputFormat
    mov rsi, age
    mov rax, 0
    push rbx
    call scanf
    pop rbx

;;;;MULTIPLY the age by 7
    mov rdi, [age]
    mov rax, 7
    mul rdi

;;;;PRINT the age in dogyears
    mov rdi, dogYears
    mov rsi, name
    mov rdx, rax
    mov rax, 0
    push rbx
    call printf
    pop rbx





;;;;ADD 80 years to the age
    mov rax, [age]
    add rax, 79


;;;;PRINT the age in 2100
    mov rdi, ageIn2100
    mov rsi, name
    mov rdx, rax
    mov rax, 0
    push rbx
    call printf
    pop rbx



;;;; exit(0)
    mov rax, 0
    call exit


section .data
    promptName db "What is your name? ", 0
    promptAge db "How old are you? ", 0
    
    inputFormat db "%d", 0
    inputFormat2 db "%s", 0
    name dq 0
    age dq 0
    ageDog dq 0
    age2100 dq 0


    ageIn2100 db "%s will be %d years old in 2100.", 0ah, 0
    dogYears db "%s is %d years old in dog years.", 0ah, 0
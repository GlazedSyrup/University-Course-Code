extern printf
extern scanf
extern exit

global main

section .text

main:
;;;;MINIMUM
    mov rdi, array
    mov rdx, array_size

    mov r8, [rdi] ; number of the array
;    mov [minNum], r8 ; number of the array
    
    call minimum

printTheResult:
    mov rdi, resultText
    mov rsi, r8
    push rbx
    call printf
    pop rbx

minimum:

    cmp rdx, 0 ; check for null terminator
    je endOfArray ; if null, return
     
    cmp r8, rdx ; is it bigger than minNum(r8)?
    jl skipNumber


    ;mov [minNum], r8 ;;; ERROR, doesnt work i think, doesnt move new value int minNum
    mov r8, rdx ;;; ERROR, doesnt work i think, doesnt move new value int minNum

    jmp skipNumber





skipNumber:
    inc rsi
    dec rdx
    jmp minimum


endOfArray:
    mov rax, 0
    ret


section .data
    minNum dq 0
    array_size dq 12
    array dq -9, -2, 1, 8, 15, 3, -7, 16, -1, 20, 5, 2
    resultText db "The minimum element is: %d", 0ah, 0

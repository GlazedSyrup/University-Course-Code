extern printf
extern scanf

global main

;;;The following code is done completely without testing due to an unfortunate and unforseen event
;;;The following code is my entire understanding of asm without the capability to test code 
;;;It goes without saying that had I the resources required I would have performed much better

main:
    call getDivisible

    ; return 0
    mov rax, 0
    ret



section .text
getDivisible:
    mov rdi, inputFmt
    mov rsi, inputPrmpt
    mov rax, 0
    push rbx 
    call printf
    pop rbx
    
    mov rdi, inputFmt
    mov rsi, divisor
    mov rax, 0
    push rcx
    call scanf
    pop rcx 
    
	;;;;INITIALIZE VALUES
	mov rdi, 0
	mov rsi, startValues
    mov rdx, numValues
	mov rcx, divisor
	mov rbx, endValues
    mov r11, endNumValues
    call checkDiv



checkDiv:
    mov rdi, [rsi] ;current num of array

    cmp rdx, 0 ; check for null terminator
    je printTheResult ; if null, return
     
    idiv rdi, rcx ; is it divisible by rcx(divisor)?
    je nextInt ; if not

    mov [rbx], rdi
    inc rbx

    jmp nextInt ;; unsure if needed, should proceed to the next code segment no problem

nextInt:
    inc rsi
    dec rdx
    inc r11
    jmp checkDiv

printTheResult:
    mov rdx, numValues
    mov rbx, endValues
    mov r11, endNumValues

    looping:
    cmp r11, 0 ; check for null terminator
    je endOfArray ; if null, return

    mov rdi, outputFmt
    mov rsi, [rbx]
    mov rcx, divisor
    push r8
    call printf
    pop r8
    
    nextNum:
    inc rbx
    dec r11
    jmp looping:

endOfArray:
    mov rax, 0
    ret

section .data

	startValues     dq 70, -1, -16, 0, -7, 15, 11, -72, 30, -9, 23, 19, -28, 13, 6, 21, -2, 33, -5, 4
	endValues 	    times 20 dq 0
	numValues       dq 20
	endNumValues    dq 0

	inputPrmpt      db "Enter a number: ", 0
	inputFmt        db "%d", 0
	divisor         dq 0

    outputFmt       db "%d is divisible by %d", 0xa, 0

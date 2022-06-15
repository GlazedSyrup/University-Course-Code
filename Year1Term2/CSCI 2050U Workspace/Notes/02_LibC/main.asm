extern printf
extern scanf
extern exit

global main

section .text

main:
; everything in assembly language is an address
    ; this is the following C program
    ; int number = 0;
    ; printf("Enter a number: ");
    ; scanf("%d", &number);
    ; number = number * number;
    ; printf("The result is %d.\n", number)



    ; printf("%s", "Enter a number: ");
    ; arguments:
    ;   rdi - first argument
    ;   rsi - second argument
    mov rdi, promptFormat ;rdi is a 64 bit register    
    mov rsi, prompt ; move into the 64bit register rdi, promptname
    mov rax, 0 ; clearing out the rax register; using the rax register for the return value; printf will put the value into rax
    push rbx ; is a junk value and allows the stack to be increased from 8 bytes to 16 ;we always need to push 16 bytes at a time ; padding the stack to fufil the 16 multiple byte requirement
    call printf ; rax after this stores how many characters did i print
    pop rbx
    
    ; scanf("%d", &number);
    mov rdi, inputFormat ; moving inputformat into the register rdi
    mov rsi, number ; [number] says give me the value at this address
    mov rax, 0 ; clearing rax
    push rcx ; padding the stack once again
    call scanf ; call implicitly puts the return address on the stack ; puts 8 bytes on the stack ; rax after this stores how many characters did i read
    pop rcx 

    ; number = number * number;
    mov rax, [number]
    mul rax

    ; printf("The result is %d.\n", number)
    mov rdi, resultFormat
    mov rsi, rax
    mov rax, 0
    push rbx
    call printf
    pop rbx



    ; exit(0)
    mov rax, 0
    call exit

section .data
    promptFormat db "%s", 0 ;every string needs a null terminator : , 0
    prompt db "Enter a number: ", 0  ; array of characters  , 0, 0, 0 - is how many characters it is expecting  ; , means after you are done all those bytes, add this-->(0) ; promptName is an address label. is the same as main:

    inputFormat db "%d", 0
    number dq 0 ;64 bit storage ; int number = 0; ; varname varsizetype initializedvalue ; is a memory address (everything is a memory address)

    resultFormat db "the result is %d.", 0ah, 0dh, 0 ; newline works with just 0ah, idk what 0dh does ; 0dh apparently does :0dh is carriage return it just moves the cursor

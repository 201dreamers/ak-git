.global lab2
.syntax unified

#define A #13
#define B #3
#define C #2

lab2:
    push {lr}
    mov r0, A
    mov r1, B
    mov r2, C
    bl calc
    pop {pc}

calc:
    push {lr}

    sub r3, r0, r1
    cmp r3, #0

    ite ge
    addge r3, r0, r1
    sbclt r3, r0, r1

    sdiv r3, r2

    pop {lr}

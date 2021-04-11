.syntax unified
.cpu cortex-m4
//.fpu softvfp
.thumb
//global memory locations
.global vtable_kernel
.global __kernel_reset__

.type vtable_kernel, %object
.type __kernel_reset__, %function

.section .interrupt_vector
vtable_kernel:
	.word __stack_start
	.word __kernel_reset__+1
	.size vtable_kernel, .-vtable_kernel

.section .rodata
	start: .asciz "kernel start\n"
	finish: .asciz "value in reg #1: "

.section .text
__kernel_reset__:
	ldr r0, =start
	bl dbgput_line

	mov r0, #13    
	mov r1, #3    
	mov r2, #2  

    sbc r3, r0, r1
    cmp r3, #0

    ite ge
    addge r3, r0, r1
    sbclt r3, r0, r1

    sdiv r3, r2

	mov r0, r3
	ldr r0, =finish
	bl dbgput
        mov r0, r3
        bl dbgput_num

end:
	b end

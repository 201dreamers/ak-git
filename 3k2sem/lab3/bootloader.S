.syntax unified
.cpu cortex-m4
//.fpu softvfp
.thumb

.global bootload
.section .rodata
	image: .incbin "kernel.bin"
	end_of_image:
	str_boot_start: .asciz "bootloader started"
	str_boot_end: .asciz "bootloader end"
	str_boot_indicate: .asciz "#"
.section .text
bootload:
	ldr r0, =str_boot_start
	bl dbgput_line
	ldr r0, =end_of_image
	ldr r1, =image
	ldr r2, =_ram_start
sub r4, r1, r0
sub r2,r4 
eor r4, r4
loop:
	ldrb r3, [r0, r4]
 	strb r3, [r2, r4]
 	sub r4, #1
 	add r5, r0, r4
	cmp r5, r1
	bne loop
bl newline
ldr r0, =str_boot_end
bl dbgput_line
ldr lr, =bootload_end
add lr, #1
ldr r2, =_ram_start
add r2, #4 // go to __reset_kernel__
ldr r0, [r2]
bx r0

bootload_end:
	b bootload_end

ldr	r0,=FileName
mov	r1,#0
swi	0x66
mov	r3,r0

ldr	r1,=line1
mov	r2,#80
swi	0x6a
ldr	r4,=line1

mov	r0,r3
ldr	r1,=line2
mov	r2,#80
swi	0x6a
ldr	r5,=line2

compare:
	ldrb	r1,[r4],#1
	ldrb	r2,[r5],#1
	cmp	r1,#0
	beq	end_str1
	cmp	r2,r1
	bne	noteq
	beq	compare

end_str1:
	cmp	r2,#0
	bne	noteq

ldr	r0,=eq
mov	r2,#80
swi	0x02
mov	r0,r3
swi	0x68
swi	0x11

noteq:
	ldr r0,=neq
	mov r2,#80
	swi 0x02
	mov r0,r3
	swi 0x68
	swi 0x11


FileName: .asciz "26.txt"
eq: .asciz "Equal"
neq: .asciz "Not equal"
.align
line1: .skip 80
line2: .skip 80

FileName:	.asciz	"22.txt"
FileHandle:	.word	0

.align

string:	.skip 80

ldr	r0,=FileName
mov	r1,#0
swi	0x66
ldr	r1,=string
mov	r2,#80
swi	0x6a
ldr	r2,=string


Loop:
ldrb	r3,[r2],#1
cmp	r3,#0
beq	TER
cmp	r3,#0x2C
beq	NEW
mov	r0,r3
swi	0x00
bal	Loop


NEW:
mov	r0,#'\n'
swi	0x00
bal	Loop


TER:
ldr	r0,=FileHandle
str	r0,[r0]
swi	0x68
swi	0x11
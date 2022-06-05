FileName:	.asciz	"20.txt"
FileHandle:	.word	0

.align

string:	.skip 80

ldr	r0,=FileName
mov	r1,#0
swi	0x66
ldr	r1,=string
mov	r2,#80
swi	0x6a
ldr	r0,=string
swi	0x02
swi	0x68
swi	0x11
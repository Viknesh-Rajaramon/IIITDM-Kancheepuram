.equ	SCount,250			@250*(1+3)=1000
.equ	LCount,10			@STimer*(10(1+3))=1000*40=40000

LTimer:
	mov	r2,#LCount

LLoop:
	BL	STimer			@Branch with Link
	subs	r2,r2,#1		@r2=r2-1//At end of subtraction updates condition flag
	BNE	LLoop

swi	0x11

STimer:
	mov	r1,#SCount

SLoop:					@Requires 1(Subtraction)+3(BNE)=4 cycles
	subs	r1,r1,#1		@r1=r1-1//At end of subtraction updates condition flag
	BNE	SLoop			
	mov	PC,LR			@Put the value in Link Register into PC
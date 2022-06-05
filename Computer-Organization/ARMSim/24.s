.equ	SCount,250			@250*(1+3)=1000
.equ	LCount,2000			@STimer*2000=1000*2000=2000000
.equ	cycles,5

BULB:
	mov	r3,#cycles
	
Loop:
	mov	r0,#0x02		@r0=0x02//Turning On Left LED
	swi	0x201
	mov	r4,PC			@Store PC in r4
	B	LTimer			
	mov	r0,#0x01		@r0=0x01//Turning On Right LED
	swi	0x201
	mov	r4,PC			@Store PC in r4
	B	LTimer
	subs	r3,r3,#1		@r3=r3-1//At end of subtraction updates condition flag
	BNE	Loop

swi	0x11

LTimer:
	mov	r2,#LCount

LLoop:
	BL	STimer			@Branch with Link
	subs	r2,r2,#1		@r2=r2-1//At end of subtraction updates condition flag
	BNE	LLoop
	mov	PC,r4			@Move r4 to PC

STimer:
	mov	r1,#SCount

SLoop:					@Requires 1(Subtraction)+3(BNE)=4 cycles
	subs	r1,r1,#1		@r1=r1-1//At end of subtraction updates condition flag
	BNE	SLoop			
	mov	PC,LR			@Put the value in Link Register into PC
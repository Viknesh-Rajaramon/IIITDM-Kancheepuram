.equ	SEG_A,0x80
.equ	SEG_B,0x40
.equ	SEG_C,0x20
.equ	SEG_D,0x08
.equ	SEG_E,0x04
.equ	SEG_F,0x02
.equ	SEG_G,0x01
.equ	SCount,250			@250*(1+3)=1000
.equ	LCount,1000			@STimer*1000=1000*1000=1000000


SEGMENT:
	mov	r0,#SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_G		@For 0
	swi	0x200
	mov	r4,PC						@Store PC in r4
	B	LTimer
	mov	r0,#SEG_B|SEG_C					@For 1
	swi	0x200
	mov	r4,PC						@Store PC in r4
	B	LTimer
	mov	r0,#SEG_A|SEG_B|SEG_D|SEG_E|SEG_F		@For 2
	swi	0x200
	mov	r4,PC						@Store PC in r4
	B	LTimer
	mov	r0,#SEG_A|SEG_B|SEG_C|SEG_D|SEG_F		@For 3
	swi	0x200
	mov	r4,PC						@Store PC in r4
	B	LTimer
	mov	r0,#SEG_B|SEG_C|SEG_F|SEG_G			@For 4
	swi	0x200
	mov	r4,PC						@Store PC in r4
	B	LTimer
	mov	r0,#SEG_A|SEG_C|SEG_D|SEG_F|SEG_G		@For 5
	swi	0x200
	mov	r4,PC						@Store PC in r4
	B	LTimer
	mov	r0,#SEG_A|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G		@For 6
	swi	0x200
	mov	r4,PC						@Store PC in r4
	B	LTimer
	mov	r0,#SEG_A|SEG_B|SEG_C				@For 7
	swi	0x200
	mov	r4,PC						@Store PC in r4
	B	LTimer
	mov	r0,#SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G	@For 8
	swi	0x200
	mov	r4,PC						@Store PC in r4
	B	LTimer
	mov	r0,#SEG_A|SEG_B|SEG_C|SEG_D|SEG_F|SEG_G		@For 9
	swi	0x200
	mov	r4,PC						@Store PC in r4
	B	LTimer
	
swi	0x11

LTimer:
	mov	r2,#LCount

LLoop:
	BL	STimer			@Branch with Link
	subs	r2,r2,#1		@r2=r2-1//At end of subtraction updates condition flag
	BNE	LLoop
	mov	PC,r4			@Move r4 to PC

swi	0x11

STimer:
	mov	r1,#SCount

SLoop:					@Requires 1(Subtraction)+3(BNE)=4 cycles
	subs	r1,r1,#1		@r1=r1-1//At end of subtraction updates condition flag
	BNE	SLoop			
	mov	PC,LR			@Put the value in Link Register into PC
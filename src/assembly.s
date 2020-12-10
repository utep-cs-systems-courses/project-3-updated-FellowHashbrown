	.arch msp430g2553
	.p2align 1,0
	.text

	.text
jt:	.word default
	.word state1
	.word state2
	.word state3
	.word state4

	.global state_advance
state_advance:
	sub #2, r1
	mov #0, 0(r1)

	cmp #0, r12
	jl default

	cmp #5, r12
	jhs default

	add r12, r12
	mov jt(r12), r0

state1:
	add #1, 0(r1)
	call #dim_75
	jmp end
state2:
	add #1, 0(r1)
	call #dim_50
	jmp end
state3:
	add #1, 0(r1)
	call #dim_25
	jmp end
state4:
	mov #0, r12
	call #binary_led
	jmp end
default:
end:
	mov 0(r1), r12
	add #2, r1
	pop r0

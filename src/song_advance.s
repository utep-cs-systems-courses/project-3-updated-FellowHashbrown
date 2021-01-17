	.arch msp430g2553
	.p2align 1,0
	.text
jt:				; jump table options
	.word song1
	.word song2
	.word song3
	.word song4
	
	;; external variables or functions
	.extern button_state
	.extern song_1
	.extern song_2
	.extern song_3
	.extern buzzer_set_period

	.global song_advance

song_advance:
	cmp.b #3, &button_state
	jhs song4

	mov.b &button_state, r13
	add.b r13, r13
	mov jt(r13), r0

song1:
	call #song_1
	jmp end
song2:
	call #song_2
	jmp end
song3:
	call #song_3
	jmp end
song4:
	mov #0, r12
	call #buzzer_set_period
end:
	pop r0

	.file	"03.stack_overflow.c"
	.text
	.globl	overflower
	.type	overflower, @function
overflower:
.LFB0:
	.cfi_startproc
	pushq	%rbp 				# on ajoute des donnees sur la stack
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	overflower			# on relance la recursive
	nop
	popq	%rbp				# on eleve cette element de la stack
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	overflower, .-overflower
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	overflower
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu2~18.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits

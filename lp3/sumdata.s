	.file	"sumdata.c"
	.globl	x
	.data
	.align 16
	.type	x, @object
	.size	x, 20
x:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.text
	.globl	sum
	.type	sum, @function
sum:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L2
.L5:
	cmpl	$0, -20(%rbp)
	je	.L3
	movl	-8(%rbp), %eax
	cltq
	movl	x(,%rax,4), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L4
.L3:
	movl	-8(%rbp), %eax
	cltq
	movl	x(,%rax,4), %eax
	addl	%eax, -4(%rbp)
.L4:
	addl	$1, -8(%rbp)
.L2:
	cmpl	$4, -8(%rbp)
	jle	.L5
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	sum, .-sum
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

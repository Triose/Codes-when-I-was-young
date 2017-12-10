	.file	"1163_2.cpp"
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	_ZStL13allocator_arg, @object
	.size	_ZStL13allocator_arg, 1
_ZStL13allocator_arg:
	.zero	1
	.type	_ZStL6ignore, @object
	.size	_ZStL6ignore, 1
_ZStL6ignore:
	.zero	1
	.align 8
	.type	_ZL2PI, @object
	.size	_ZL2PI, 8
_ZL2PI:
	.long	1413754136
	.long	1074340347
	.align 8
	.type	_ZL1E, @object
	.size	_ZL1E, 8
_ZL1E:
	.long	2333366121
	.long	1074118410
	.globl	n
	.bss
	.align 4
	.type	n, @object
	.size	n, 4
n:
	.zero	4
	.globl	m
	.align 4
	.type	m, @object
	.size	m, 4
m:
	.zero	4
	.globl	dp
	.align 32
	.type	dp, @object
	.size	dp, 48400
dp:
	.zero	48400
	.section	.rodata
.LC0:
	.string	"r"
.LC1:
	.string	"in.txt"
.LC2:
	.string	"%d"
.LC3:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3395:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	call	freopen@PLT
.L11:
	leaq	n(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	scanf@PLT
	cmpl	$-1, %eax
	setne	%al
	testb	%al, %al
	je	.L2
	movl	$1, -20(%rbp)
.L6:
	movl	-20(%rbp), %edx
	movl	n(%rip), %eax
	cmpl	%eax, %edx
	jg	.L3
	movl	$1, -16(%rbp)
.L5:
	movl	-20(%rbp), %eax
	cmpl	%eax, -16(%rbp)
	jg	.L4
	movl	-20(%rbp), %eax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	cltq
	imulq	$110, %rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	dp(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	scanf@PLT
	addl	$1, -16(%rbp)
	jmp	.L5
.L4:
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	.L6
.L3:
	movl	n(%rip), %eax
	subl	$1, %eax
	movl	%eax, -20(%rbp)
.L10:
	movl	-20(%rbp), %eax
	testl	%eax, %eax
	jle	.L7
	movl	$1, -12(%rbp)
.L9:
	movl	-20(%rbp), %eax
	cmpl	%eax, -12(%rbp)
	jg	.L8
	movl	-20(%rbp), %eax
	leal	1(%rax), %edx
	movl	-12(%rbp), %eax
	addl	$1, %eax
	cltq
	movslq	%edx, %rdx
	imulq	$110, %rdx, %rdx
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	dp(%rip), %rax
	movl	(%rdx,%rax), %edx
	movl	-20(%rbp), %eax
	leal	1(%rax), %ecx
	movl	-12(%rbp), %eax
	cltq
	movslq	%ecx, %rcx
	imulq	$110, %rcx, %rcx
	addq	%rcx, %rax
	leaq	0(,%rax,4), %rcx
	leaq	dp(%rip), %rax
	movl	(%rcx,%rax), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	_Z3MaxIiET_S0_S0_
	movl	%eax, %esi
	movl	-20(%rbp), %edx
	movl	-20(%rbp), %ecx
	movl	-12(%rbp), %eax
	cltq
	movslq	%ecx, %rcx
	imulq	$110, %rcx, %rcx
	addq	%rcx, %rax
	leaq	0(,%rax,4), %rcx
	leaq	dp(%rip), %rax
	movl	(%rcx,%rax), %eax
	leal	(%rax,%rsi), %ecx
	movl	-12(%rbp), %eax
	cltq
	movslq	%edx, %rdx
	imulq	$110, %rdx, %rdx
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	leaq	dp(%rip), %rax
	movl	%ecx, (%rdx,%rax)
	addl	$1, -12(%rbp)
	jmp	.L9
.L8:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	.L10
.L7:
	movl	444+dp(%rip), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L11
.L2:
	movl	$0, %eax
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L13
	call	__stack_chk_fail@PLT
.L13:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3395:
	.size	main, .-main
	.section	.text._Z3MaxIiET_S0_S0_,"axG",@progbits,_Z3MaxIiET_S0_S0_,comdat
	.weak	_Z3MaxIiET_S0_S0_
	.type	_Z3MaxIiET_S0_S0_, @function
_Z3MaxIiET_S0_S0_:
.LFB3605:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jle	.L15
	movl	-4(%rbp), %eax
	jmp	.L17
.L15:
	movl	-8(%rbp), %eax
.L17:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3605:
	.size	_Z3MaxIiET_S0_S0_, .-_Z3MaxIiET_S0_S0_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB3835:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L20
	cmpl	$65535, -8(%rbp)
	jne	.L20
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L20:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3835:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_n, @function
_GLOBAL__sub_I_n:
.LFB3836:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3836:
	.size	_GLOBAL__sub_I_n, .-_GLOBAL__sub_I_n
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_n
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 6.2.0-5ubuntu12) 6.2.0 20161005"
	.section	.note.GNU-stack,"",@progbits

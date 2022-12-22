	.file	"ex11.c"
	.section .rdata,"dr"
LC0:
	.ascii "%d \0"
	.text
	.globl	_nombre_diviseurs
	.def	_nombre_diviseurs;	.scl	2;	.type	32;	.endef
_nombre_diviseurs:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$1, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L2
L4:
	movl	8(%ebp), %eax
	cltd
	idivl	-12(%ebp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	L3
	addl	$1, -16(%ebp)
L3:
	addl	$1, -12(%ebp)
L2:
	movl	-12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jne	L4
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.globl	_nombre_triangulairemabite
	.def	_nombre_triangulairemabite;	.scl	2;	.type	32;	.endef
_nombre_triangulairemabite:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	L7
L8:
	movl	8(%ebp), %eax
	leal	-1(%eax), %edx
	movl	%edx, 8(%ebp)
	addl	%eax, -4(%ebp)
L7:
	cmpl	$0, 8(%ebp)
	jne	L8
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "la reponse est : %d\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$1, 24(%esp)
	movl	$0, 28(%esp)
	movl	$0, 16(%esp)
	movl	$1, 20(%esp)
	jmp	L11
L12:
	addl	$50000, 20(%esp)
	movl	20(%esp), %eax
	movl	%eax, (%esp)
	call	_nombre_triangulairemabite
	cltd
	movl	%eax, 24(%esp)
	movl	%edx, 28(%esp)
L11:
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	_nombre_diviseurs
	cmpl	$499, %eax
	jle	L12
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef

# ---------------- Beginning of Generated Code --------------------
        .file   "foo"
        .text
.globl graph1
        .type   graph1, @function
graph1:
.LFB0:
	.cfi_startproc
	pushq	%rbp              # save base pointer on stack
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp        # move stack pointer to base pointer
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
        subq	$1344, %rsp 	  # make space for this stack frame
	movq	%rbx, %r9        # save %rbx (callee-saved) in %r9
# ------------------------- begin Your code -----------------------------
	movl	$48,%eax         	#  48 -> %eax
	movl	%eax,%edi         	#  %eax -> %edi
	call	new              	#  new()
	movq	%rax,-1016(%rbp)     	#  %rax -> john
	movl	$48,%eax         	#  48 -> %eax
	movl	%eax,%edi         	#  %eax -> %edi
	call	new              	#  new()
	movq	%rax,-1008(%rbp)     	#  %rax -> mary
	movl	$48,%eax         	#  48 -> %eax
	movl	%eax,%edi         	#  %eax -> %edi
	call	new              	#  new()
	movq	%rax,-1000(%rbp)     	#  %rax -> fred
	movl	$2,%eax         	#  2 -> %eax
	movq	-1016(%rbp),%rcx     	#  john -> %rcx
	movl	%eax,32(%rcx)         	#  %eax -> ^. [32+%rcx]
	movl	$19,%eax         	#  19 -> %eax
	movq	-1016(%rbp),%rcx     	#  john -> %rcx
	movl	%eax,0(%rcx)         	#  %eax -> ^. [0+%rcx]
.L1:
	movq	-1008(%rbp),%rax     	#  mary -> %rax
	movq	-1016(%rbp),%rcx     	#  john -> %rcx
	movq	%rax,8(%rcx)         	#  %rax -> ^. [8+%rcx]
	movsd	.LC4(%rip),%xmm0   	#  40000.000000 -> %xmm0
	movq	-1016(%rbp),%rax     	#  john -> %rax
	movsd	%xmm0,40(%rax)         	#  %xmm0 -> ^. [40+%rax]
	movsd	.LC5(%rip),%xmm0   	#  3.000000 -> %xmm0
	movq	-1016(%rbp),%rax     	#  john -> %rax
	movsd	%xmm0,16(%rax)         	#  %xmm0 -> ^. [16+%rax]
	movl	$21,%eax         	#  21 -> %eax
	movq	-1008(%rbp),%rcx     	#  mary -> %rcx
	movl	%eax,0(%rcx)         	#  %eax -> ^. [0+%rcx]
	movq	-1000(%rbp),%rax     	#  fred -> %rax
	movq	-1008(%rbp),%rcx     	#  mary -> %rcx
	movq	%rax,8(%rcx)         	#  %rax -> ^. [8+%rcx]
.L0:
	movl	$20,%eax         	#  20 -> %eax
	movq	-1000(%rbp),%rcx     	#  fred -> %rcx
	movl	%eax,0(%rcx)         	#  %eax -> ^. [0+%rcx]
	movl	$0,%eax         	#  0 -> %eax
	movq	-1000(%rbp),%rcx     	#  fred -> %rcx
	movl	%eax,8(%rcx)         	#  %eax -> ^. [8+%rcx]
	movsd	.LC6(%rip),%xmm0   	#  4.500000 -> %xmm0
	movq	0(%rbp),%rax     	#   -> %rax
	movsd	%xmm0,24(%rax)         	#  %xmm0 -> ^. [24+%rax]
genarith arefop
	movq	-1016(%rbp),%rax     	#  john -> %rax
	movl	%eax,40(%rcx)         	#  %eax -> ^. [40+%rcx]
	movq	-1296(%rbp),%rax     	#  ac -> %rax
	movl	%eax,96(%rcx)         	#  %eax -> ^. [96+%rcx]
	movq	-1016(%rbp),%rax     	#  john -> %rax
	movq	%rax,-992(%rbp)     	#  %rax -> ptr
	movl	$0,%eax         	#  0 -> %eax
	movl	%eax,-1308(%rbp)     	#  %eax -> sum
	movl	$1,%eax         	#  1 -> %eax
	movl	%eax,-1312(%rbp)     	#  %eax -> i
.L2:
	movq	-992(%rbp),%rax     	#  ptr -> %rax
	movl	$0,%ecx         	#  0 -> %ecx
	cmpl	%ecx,%eax           	#  compare %eax - %ecx
	jne	.L7 			#  jump if     !=
	jmp	.L8 			#  jump 
.L7:
	movl	-1308(%rbp),%eax     	#  sum -> %eax
genarith arefop
	movq	-992(%rbp),%rcx     	#  ptr -> %rcx
	movl	%eax,0(%rcx)         	#  %eax -> ^. [0+%rcx]
	addl	%eax,%eax         	#  %eax + %eax -> %eax
	movl	%eax,-1308(%rbp)     	#  %eax -> sum
genarith arefop
	movq	-992(%rbp),%rax     	#  ptr -> %rax
	movl	%eax,0(%rcx)         	#  %eax -> ^. [0+%rcx]
	movq	-976(%rbp),%rax     	#  people -> %rax
	movl	$-48,%ecx         	#  -48 -> %ecx
	movl	$48,%edx         	#  48 -> %edx
	movl	-1312(%rbp),%ebx     	#  i -> %ebx
	imull	%ebx,%edx         	#  %edx * %ebx -> %edx
	addl	%edx,%ecx         	#  %ecx + %edx -> %ecx
genarith arefop
	movq	-1016(%rbp),%rax     	#  john -> %rax
	movl	%eax,32(%rcx)         	#  %eax -> ^. [32+%rcx]
	movq	-1136(%rbp),%rax     	#  aco -> %rax
	movl	$-8,%ecx         	#  -8 -> %ecx
	movl	$12,%edx         	#  12 -> %edx
	movl	-1312(%rbp),%ebx     	#  i -> %ebx
	imull	%ebx,%edx         	#  %edx * %ebx -> %edx
	addl	%edx,%ecx         	#  %ecx + %edx -> %ecx
genarith arefop
	movq	-992(%rbp),%rax     	#  ptr -> %rax
	movl	%eax,8(%rcx)         	#  %eax -> ^. [8+%rcx]
	movq	%rax,-992(%rbp)     	#  %rax -> ptr
	movl	-1312(%rbp),%eax     	#  i -> %eax
	movl	$1,%ecx         	#  1 -> %ecx
	addl	%ecx,%eax         	#  %eax + %ecx -> %eax
	movl	%eax,-1312(%rbp)     	#  %eax -> i
	jmp	.L2 			#  jump 
.L8:
	movl	$.LC9,%edi       	#  addr of literal .LC9
	call	write              	#  write()
	movl	-1312(%rbp),%eax     	#  i -> %eax
	call	writelni              	#  writelni()
	movl	$.LC10,%edi       	#  addr of literal .LC10
	call	write              	#  write()
	movl	-1308(%rbp),%eax     	#  sum -> %eax
	call	writelni              	#  writelni()
	movl	$.LC11,%edi       	#  addr of literal .LC11
	call	write              	#  write()
genarith arefop
	movq	-1000(%rbp),%rax     	#  fred -> %rax
	movl	%eax,24(%rcx)         	#  %eax -> ^. [24+%rcx]
	call	writelnf              	#  writelnf()
	movl	-1308(%rbp),%eax     	#  sum -> %eax
	movl	$3,%ecx         	#  3 -> %ecx
	cmpl	%ecx,%eax           	#  compare %eax - %ecx
	jl	.L12 			#  jump if     <
	jmp	.L13 			#  jump 
.L12:
	jmp	.L0 			#  jump 
.L13:
# ----------------------- begin Epilogue code ---------------------------
	movq	%r9, %rbx        # restore %rbx (callee-saved) from %r9
        leave
        ret
        .cfi_endproc
.LFE0:
        .size   graph1, .-graph1
# ----------------- end Epilogue; Literal data follows ------------------
        .section        .rodata
	.align  4
.LC9:
	.string	"i = "
	.align  4
.LC10:
	.string	"Sum of ages = "
	.align  4
.LC11:
	.string	"Fred loc im = "
	.align  8
.LC4:
	.long	0   	#  40000.000000
	.long	1088653312
	.align  8
.LC5:
	.long	0   	#  3.000000
	.long	1074266112
	.align  8
.LC6:
	.long	0   	#  4.500000
	.long	1074921472

        .ident  "CS 375 Compiler - Summer 2013"

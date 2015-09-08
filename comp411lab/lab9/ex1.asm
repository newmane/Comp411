#------------------------------------------
# Lab 8: String Processing and Recursion
#
# Name: Emily Newman
#
# Onyen: newmane
#
#------------------------------------------
.data 
		newLine:	.asciiz "\n"
.text 0x3000

main:
	ori	$v0, $0, 5		# scan in number
	syscall

	addu	$a0, $0, $v0		# save the num 
	beq	$v0, 0, exit		# if it equals 0 exit

	jal	fibonacci

	j	print

fibonacci:
	addiu	$sp, $sp, -12		# allocates 3 word in stack
	sw	$ra, 8($sp)		# return adress stored
	sw	$a0, ($sp)		# store $a0 on stack
	sw	$s0, 4($sp)		# store $s0

	bgt 	$a0, 1, calculations	# if num is greater than 1 then go to calculations
	move	$v0, $a0		# move $a0 to $v0
	j	restore			# jump to restore

calculations:
	subu	$a0, $a0, 1		# $a0 = n-1
	jal	fibonacci		# fibonacci of n-1

	move	$s0, $v0		# save fibonacci(n-1)
	sub	$a0, $a0, 1		# $a0 = n-2
	jal 	fibonacci 

	addu	$v0, $v0, $s0		# $v0 = fibonacci(n-2) + fibonacci(n-1)	

restore:
	lw 	$a0, ($sp)		# loading number 
	lw	$ra, 8($sp)		# get return address off stack
	lw 	$s0, 4($sp)		# get $s0
	addiu 	$sp, $sp, 12		# pop 2 words off stack

	jr	$ra

print:
	addiu	$a0, $v0, 0		# $a0 = fibonacci
	ori	$v0, $0, 1		# print fibonacci
	syscall

	la	$a0, newLine		# print newline
	ori 	$v0, $0, 4
	syscall

	j	main


exit:
	ori	$a0, $0, 0		# print the factorial of 0
	ori 	$v0, $0, 1
	syscall

	ori	$v0, $0, 10		# exit Program
	syscall

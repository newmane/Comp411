#------------------------------------------
# Lab 8: String Processing and Recursion
#
# Name: Emily Newman
#
# Onyen: newmane
#
#------------------------------------------
.data
	buffer:		.space 21
	newLine:	.asciiz "\n"

.text 0x3000

main:
	ori 	$v0, $0, 8		# scan in temp
	la 	$a0, buffer
	li 	$a1, 20
	syscall

	addiu	$v0, $0, 0		# set answer = 0
	addiu	$s0, $0, 10		# $s0 = 10 to change place value
	addiu	$s1, $0, 0		# set i = 0

	j	a_to_i

a_to_i:
	la	$t0, ($a0)		# load $a0
	add	$t0, $t0, $s1		# add i to $a0
	lb  	$t1, ($s1)		# load number
	addiu	$a0, $v0, 0		# $a0 is now input for factorial
	beq 	$t1, 10, factorial	# if newLine call factorial
	la	$a0, buffer		# restore $a0
	addiu	$s1, $s1, 1		# i++
	multu 	$v0, $s0		# answer*10
	mflo 	$v0
	sub	$t1, $t1, 48		# int found using offset
	add	$v0, $v0, $t1		# answer += $t1

	j	a_to_i

factorial:
	beq 	$a0, 0, exit		# if input if 0 exit
	jal	onecheck		# jump to onecheck

	addiu	$a0, $v0, 0		# $a0 = factorial 
	ori	$v0, $0, 1		# print factorial
	syscall

	la	$a0, newLine		# print newline
	ori 	$v0, $0, 4
	syscall

	j	main

onecheck:
	bne	$a0, 1, factcalc	# if not 1 go to loop 2
	ori	$v0, $0, 1		# passing the result 1 through $v0
	jr	$ra			# return to place in factorial routine

factcalc:
	addiu	$sp, $sp, -8		# allocates 2 word in stack
	sw	$ra, 4($sp)		# return adress stored
	sw	$a0, ($sp)		# store $a0 on stack
	
	sub	$a0, $a0, 1		# $a0 = n-1
	jal	onecheck		# factorial of n-1

	lw 	$a0, ($sp)		# loading n 
	lw	$ra, 4($sp)		# get return address off stack
	addiu 	$sp, $sp, 8		# pop 2 words off stack
	
	multu	$v0, $a0		# answer*n-1
	mflo	$v0		
	jr	$ra
	
exit:
	ori	$a0, $0, 1		# factorial of 0 is 1
	ori 	$v0, $0, 1		# print 1
	syscall

	ori	$v0, $0, 10		# Exit Program
	syscall

	

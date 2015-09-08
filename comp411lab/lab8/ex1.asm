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
	beq 	$t1, 10, end		# if newLine go to end
	addiu	$s1, $s1, 1		# i++
	multu 	$v0, $s0		# answer*10
	mflo 	$v0			
	sub	$t1, $t1, 48		# int found using offset
	add	$v0, $v0, $t1		# answer += $t1
	j	a_to_i
	
end:
	addiu	$a0, $v0, 0		# $a0 = answer
	ori	$v0, $0, 1
	syscall				# print answer
	
	beq 	$a0, 0, exit		# if 0 go to exit
	
	la	$a0, newLine		# print newline
	ori 	$v0, $0, 4
	syscall
	
	j	main
	
exit:
	ori	$v0, $0, 10		# Exit Program
	syscall			
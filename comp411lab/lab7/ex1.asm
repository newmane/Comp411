#-------------------------
#Lab7: PPM to PPG
#
#Name: <Emily Newman>
#Onyen: <newmane>
#
#-------------------------

.data 0x0 
	type:		.asciiz "P2\n"
	newLine:	.asciiz "\n"
	buffer:		.space 4
	
.text 0x3000
main:
	
	ori 	$v0, $0, 8	#scan in magic number
	la 	$a0, buffer
	li 	$a1, 4
	syscall
	
	ori 	$v0, $0, 4	#Print out P2
	ori 	$a0, $0, 0
	syscall
	
	ori 	$v0, $0, 5	#Scan in number of columns
	syscall
	addu 	$t0, $0, $v0
	ori	$v0, $0, 1
	or 	$a0, $0, $t0	#Print number of columns
	syscall
	
	ori 	$v0, $0, 4	#New line
	la	$a0, newLine
	syscall 
	
	ori 	$v0, $0, 5	#Scan in number of rows
	syscall
	addu	$t1, $0, $v0
	ori	$v0, $0, 1
	or	$a0, $0, $t1	#Print out number of rows
	syscall 
	
	ori	$v0, $0, 4	#New line
	la	$a0, newLine 
	syscall
	
	ori	$v0, $0, 5	#Scan in the PPM max
	syscall
	addu	$s4, $0, $v0	
	
	addi	$s5, $0, 255	#Print the Gray max (255)
	ori	$v0, $0, 1
	or 	$a0, $0, $s5
	syscall
	
	
	multu 	$t0, $t1	#Rows * Columns
	mflo	$t4
	
	
loop:
	addi	$t3, $t3, 0
	beq	$t3, $t4, exit	#While $t3 != Rows * Columns
	
	ori	$v0, $0, 4	#New line
	la	$a0, newLine
	syscall
	
	ori	$v0, $0, 5	#Scan in read
	syscall
	addu	$t5, $0, $v0
	
	ori	$v0, $0, 5	#Scan in green
	syscall
	addu	$t6, $0, $v0
	
	ori	$v0, $0, 5	#Scan in blue
	syscall
	addu	$t7, $0, $v0
	
	add	$t8, $t5, $t6	#Add red green and blue
	add	$t9, $t8, $t7
	multu	$t9, $s5	#(Red + Green + Blue) * 255
	mflo	$s0
	
	addi	$s7, $0, 3
	multu	$s4, $s7	#PPM Max * 3
	mflo	$s1
	
	divu	$s0, $s1	#((red + green + blue) * 255) / (3 * PPM_MAX)
	mflo 	$s3
	
	ori	$v0, $0, 1	#Print out gray value
	or	$a0, $0, $s3
	syscall
	
	addi	$t3, $t3, 1	#$t3++
	
	j 	loop		#Loop 

exit:

	ori	$v0, $0, 10	#Exir Program
	syscall
	
#---------------------------------
# Lab 5: Pixel Conversion
#
# Name: <Emily Newman>
# Onyen: <newmane>
#
# --------------------------------
# Below is the expected output.
# 
# Converting pixels to grayscale:
# 0
# 1
# 2
# 34
# 5
# 67
# 89
# Finished.
# -- program is finished running --
#---------------------------------

.data 0x0
	startString:	.asciiz	"Converting pixels to grayscale:\n"
	finishString:	.asciiz	"Finished."
	newline:	.asciiz	"\n"
	pixels:		.word 	0x00010000,	0x010101,	0x6,		0x3333, 
				0x030c,		0x700853,	0x294999,	-1

.text 0x3000

main:
	ori $v0, $0, 4				#System call code 4 for printing a string
	ori $a0, $0, 0x0   	 		#address of startString is in $a0
	syscall					#print the string

        
#------- INSERT YOUR CODE HERE -------
addiu $t1, $0, 0
addiu $t0, $0, 0

Lwhile:        
        lw $t2, pixels($t0)
        beq $t2, -1, Lendw   # while($t2 != -1)
        
        lbu $t2, pixels($t1)  #load blue
        addu $t3, $0, $t2     # $t3 = 0 + $t2
        addiu $t1, $t1, 1    #Increment to the next byte
        lbu $t2, pixels($t1)   #load green
        addu $t3, $t3, $t2     #$t3 += $t2
        addiu $t1, $t1, 1     # $t1++
        lbu $t2, pixels($t1)  #load red
        addu $t3, $t3, $t2
        addiu $t4, $0, 3     #t4 = 3
        divu $t3, $t4    #converting to grayscale 
        mflo $t5
       
        ori $v0, $0, 1    #System call for printing an integer
        ori $a0, $t5, 0
        syscall
        
        ori $v0, $0, 4    #System call for printing a String
        ori $a0, $0, 43   #new line
        syscall
        
        addiu $t0, $t0, 4   #next word 
        addiu $t1, $t1, 2
        beq $0, $0, Lwhile   #Back to top of the loop 
        
#------------ END CODE ---------------

Lendw:

exit:

	ori $v0, $0, 4				#System call code 4 for printing a string
	ori $a0, $0, 33  			#address of finishString is in $a0; we computed this
						#  simply by counting the number of chars in startString,
						#  including the \n and the terminating \0

	syscall					#print the string

	ori $v0, $0, 10				#System call code 10 for exit
	syscall					#exit the program

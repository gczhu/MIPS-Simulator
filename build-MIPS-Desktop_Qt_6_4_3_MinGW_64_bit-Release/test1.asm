addi $t1, $zero, 2 # t1=2
addi $t2, $zero, -1 # t2=-1
add $t3, $t1, $t2 # t3=1
nor $t4, $t1, $t2 # t4=0
sll $t1, $t1, 2 #t1=8
srl $t1, $t1, 1 #t1=4
slt $t0, $t2, $t1 #t0=1
sw $t2, 32($t1)
lw $t5, 32($t1) #t5=-1
L1:addi $t3, $t3, -1 #t3=0,t3=-1
beq $t3, $zero, L1 #true
L2:addi $t3, $t3, 1 #t3=0
bne $t3, $zero, L2 #false
jal L3
addi $t3, $t3, 1 #t3=1
L3: addi $t3, $t3, -1 #t3=-1
jr $ra #jump to "addi $t3, $t3, -1"
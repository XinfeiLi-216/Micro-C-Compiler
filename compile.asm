.data
_prompt: .asciiz "Enter the value of variable" 
_enter: .asciiz " \n" 
_outofrange: .asciiz " IndexOutOfRange" 
.text
lui $t0,4097
li $t1,0
sw $t1,72($t0)
li $t1,1
sw $t1,76($t0)
lw $t1,72($t0)
li $t2,5
slt $t3,$t1,$t2
bne $t3,$zero,arr_outofrange0
la $a0,_outofrange
li $v0,4
syscall
arr_outofrange0:
lw $t2,76($t0)
li $t3,4
mul $t4,$t3,$t1
li $t3,48
add $t4,$t4,$t3
add $t4,$t4,$t0
sw $t2,0($t4)
li $t1,1
sw $t1,80($t0)
li $t1,2
sw $t1,84($t0)
lw $t1,80($t0)
li $t2,5
slt $t3,$t1,$t2
bne $t3,$zero,arr_outofrange1
la $a0,_outofrange
li $v0,4
syscall
arr_outofrange1:
lw $t2,84($t0)
li $t3,4
mul $t4,$t3,$t1
li $t3,48
add $t4,$t4,$t3
add $t4,$t4,$t0
sw $t2,0($t4)
li $t1,2
sw $t1,88($t0)
li $t1,3
sw $t1,92($t0)
lw $t1,88($t0)
li $t2,5
slt $t3,$t1,$t2
bne $t3,$zero,arr_outofrange2
la $a0,_outofrange
li $v0,4
syscall
arr_outofrange2:
lw $t2,92($t0)
li $t3,4
mul $t4,$t3,$t1
li $t3,48
add $t4,$t4,$t3
add $t4,$t4,$t0
sw $t2,0($t4)
li $t1,3
sw $t1,96($t0)
li $t1,4
sw $t1,100($t0)
lw $t1,96($t0)
li $t2,5
slt $t3,$t1,$t2
bne $t3,$zero,arr_outofrange3
la $a0,_outofrange
li $v0,4
syscall
arr_outofrange3:
lw $t2,100($t0)
li $t3,4
mul $t4,$t3,$t1
li $t3,48
add $t4,$t4,$t3
add $t4,$t4,$t0
sw $t2,0($t4)
li $t1,4
sw $t1,104($t0)
li $t1,4
sw $t1,108($t0)
li $t1,3
sw $t1,112($t0)
lw $s1,108($t0)
lw $s2,112($t0)
mul $s0,$s1,$s2
sw $s0,108($t0)
lw $t1,104($t0)
li $t2,5
slt $t3,$t1,$t2
bne $t3,$zero,arr_outofrange4
la $a0,_outofrange
li $v0,4
syscall
arr_outofrange4:
lw $t2,108($t0)
li $t3,4
mul $t4,$t3,$t1
li $t3,48
add $t4,$t4,$t3
add $t4,$t4,$t0
sw $t2,0($t4)
la $a0,_prompt
li $v0,4
syscall
li $v0,5
syscall
sw $v0,68($t0)
li $t1,0
sw $t1,112($t0)
lw $t1,112($t0)
li $t2,5
slt $t3,$t1,$t2
bne $t3,$zero,arr_outofrange5
la $a0,_outofrange
li $v0,4
syscall
arr_outofrange5:
li $t3,12
add $t3,$t1,$t3
li $t4,4
mul $t4,$t3,$t4
add $t4,$t4,$t0
lw $t5,0($t4)
sw $t5,112($t0)
li $t1,1
sw $t1,116($t0)
lw $t1,116($t0)
li $t2,5
slt $t3,$t1,$t2
bne $t3,$zero,arr_outofrange6
la $a0,_outofrange
li $v0,4
syscall
arr_outofrange6:
li $t3,12
add $t3,$t1,$t3
li $t4,4
mul $t4,$t3,$t4
add $t4,$t4,$t0
lw $t5,0($t4)
sw $t5,116($t0)
lw $s1,112($t0)
lw $s2,116($t0)
add $s0,$s1,$s2
sw $s0,112($t0)
lw $a0,112($t0)
li $v0,1
syscall

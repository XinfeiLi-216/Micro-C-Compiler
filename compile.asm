.data
.text
lui $t0,4097
li $t1,1
sw $t1,4($t0)
li $t1,3
sw $t1,8($t0)
lw $t1,8($t0)
sw $t1,0($t0)

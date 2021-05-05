.data
.text
lui $t0,4097
li $t1,3
sw $t1,12($t0)
lw $t1,12($t0)
sw $t1,0($t0)
li $t1,3
sw $t1,16($t0)
lw $t1,16($t0)
sw $t1,4($t0)
li $t1,6
sw $t1,20($t0)
lw $t1,20($t0)
sw $t1,8($t0)
while_begin0:
lw $t1,4($t0)
sw $t1,24($t0)
li $t1,0
sw $t1,28($t0)
lw $s1,24($t0)
lw $s2,28($t0)
slt $t3,$s1,$s2
li $t4,1
sw $zero,24($t0)
beq $t3,$t4,gt_not_label0
beq $s1,$s2,gt_not_label0
sw $t4,24($t0)
gt_not_label0:
lw $t1,24($t0)
beq $t1,$zero,while_break0
codeblock_begin0:
do_while_begin1:
codeblock_begin1:
lw $t1,0($t0)
sw $t1,28($t0)
li $t1,1
sw $t1,32($t0)
lw $s1,28($t0)
lw $s2,32($t0)
add $s0,$s1,$s2
sw $s0,28($t0)
lw $t1,28($t0)
sw $t1,0($t0)
lw $t1,8($t0)
sw $t1,32($t0)
li $t1,1
sw $t1,36($t0)
lw $s1,32($t0)
lw $s2,36($t0)
add $s0,$s1,$s2
sw $s0,32($t0)
lw $t1,32($t0)
sw $t1,8($t0)
codeblock_end1:
lw $t1,8($t0)
sw $t1,36($t0)
li $t1,6
sw $t1,40($t0)
lw $s1,36($t0)
lw $s2,40($t0)
slt $s0,$s1,$s2
sw $s0,36($t0)
lw $t1,36($t0)
beq $t1,$zero,do_while_break1
j do_while_begin1
do_while_break1:
li $t1,3
sw $t1,40($t0)
lw $t1,40($t0)
sw $t1,8($t0)
lw $t1,4($t0)
sw $t1,44($t0)
li $t1,1
sw $t1,48($t0)
lw $s1,44($t0)
lw $s2,48($t0)
sub $s0,$s1,$s2
sw $s0,44($t0)
lw $t1,44($t0)
sw $t1,4($t0)
codeblock_end0:
j while_begin0
while_break0:

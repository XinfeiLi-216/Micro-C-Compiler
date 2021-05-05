.data
# no pre-defined data
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
li $t1,1
sw $t1,24($t0)
lw $t1,24($t0)
beq $t1,$zero,if_break10
# codeblock_begin10:
while_begin11:
lw $t1,4($t0)
sw $t1,28($t0)
li $t1,0
sw $t1,32($t0)
lw $s1,28($t0)
lw $s2,32($t0)
slt $t3,$s1,$s2
li $t4,1
sw $zero,28($t0)
beq $t3,$t4,gt_not_label0
beq $s1,$s2,gt_not_label0
sw $t4,28($t0)
gt_not_label0:
lw $t1,28($t0)
beq $t1,$zero,while_break11
# codeblock_begin11:
do_while_begin12:
# codeblock_begin12:
lw $t1,0($t0)
sw $t1,32($t0)
li $t1,1
sw $t1,36($t0)
lw $s1,32($t0)
lw $s2,36($t0)
add $s0,$s1,$s2
sw $s0,32($t0)
lw $t1,32($t0)
sw $t1,0($t0)
lw $t1,8($t0)
sw $t1,36($t0)
li $t1,1
sw $t1,40($t0)
lw $s1,36($t0)
lw $s2,40($t0)
add $s0,$s1,$s2
sw $s0,36($t0)
lw $t1,36($t0)
sw $t1,8($t0)
# codeblock_end12:
lw $t1,8($t0)
sw $t1,40($t0)
li $t1,6
sw $t1,44($t0)
lw $s1,40($t0)
lw $s2,44($t0)
slt $s0,$s1,$s2
sw $s0,40($t0)
lw $t1,40($t0)
beq $t1,$zero,do_while_break12
j do_while_begin12
do_while_break12:
li $t1,3
sw $t1,44($t0)
lw $t1,44($t0)
sw $t1,8($t0)
lw $t1,4($t0)
sw $t1,48($t0)
li $t1,1
sw $t1,52($t0)
lw $s1,48($t0)
lw $s2,52($t0)
sub $s0,$s1,$s2
sw $s0,48($t0)
lw $t1,48($t0)
sw $t1,4($t0)
# codeblock_end11:
j while_begin11
while_break11:
# codeblock_end10:
if_break10:
lw $t1,0($t0)
bne $t1,$zero,else_ignore20
# codeblock_begin20:
li $t1,6
sw $t1,52($t0)
lw $t1,52($t0)
sw $t1,0($t0)
# codeblock_end20:
else_ignore20:
li $t1,1
sw $t1,56($t0)
lw $t1,56($t0)
beq $t1,$zero,if_break30
# codeblock_begin30:
li $t1,5
sw $t1,60($t0)
lw $t1,60($t0)
sw $t1,4($t0)
# codeblock_end30:
if_break30:

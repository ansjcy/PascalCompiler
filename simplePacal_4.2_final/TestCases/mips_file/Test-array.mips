.macro print_int (%x)
	li $v0, 1
	add $a0, $zero, %x
	syscall
.end_macro

.macro print_char (%x)
	li $v0, 11
	add $a0, $zero, %x
	syscall
.end_macro

.macro print_str (%str)
	.data
		myLabel: .asciiz %str

	.text
	li $v0, 4
	la $a0, myLabel
	syscall
.end_macro

addi $sp, $sp,   -100
add  $fp, $zero, $sp
addi $sp, $sp, -24
sw $sp, 8($fp)
testarray0:
sw $ra, 0($fp)
addi $v0, $zero, 0
add $t0, $zero, $fp
addi $t0, $t0, 12
sw $v0, 0($t0)
add $t0, $zero, $fp
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $v0, $zero, 5
addi $v0, $v0, 1
addi $sp, $sp, -4
sw $v0, 0($sp)
addi $v0, $zero, 0
lw $t0, 4($sp)
sw $v0, 16($t0)
for_start_1:
lw   $v1, 0($sp)
slt  $t0, $v0, $v1
beq  $t0, $zero, for_end_1
add $t0, $zero, $fp
lw $v0, 16($t0)
addi $sp, $sp, -4
sw   $v0, 0($sp)
add $t0, $zero, $fp
lw $v0, 16($t0)
add $t0, $zero, $fp
addi $t0, $t0, 8
lw   $t0, 0($t0)
sll $v0, $v0, 2
add $t0, $t0, $v0
lw   $v0, 0($sp)
addi $sp, $sp, 4
sw   $v0, 0($t0)
lw   $t0, 4($sp)
lw   $v0, 16($t0)
addi $v0, $v0, 1
sw   $v0, 16($t0)
j for_start_1
for_end_1:
lw $t0, 4($sp)
lw $v0, 16($t0)
addi $v0, $v0, -1
sw $v0, 16($t0)
addi $sp, $sp, 8
add $t0, $zero, $fp
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $v0, $zero, 5
addi $v0, $v0, 1
addi $sp, $sp, -4
sw $v0, 0($sp)
addi $v0, $zero, 0
lw $t0, 4($sp)
sw $v0, 16($t0)
for_start_2:
lw   $v1, 0($sp)
slt  $t0, $v0, $v1
beq  $t0, $zero, for_end_2
add $t0, $zero, $fp
lw $v0, 12($t0)
addi $sp, $sp, -4
sw $v0, 0($sp)
add $t0, $zero, $fp
lw $v0, 16($t0)
add $t0, $zero, $fp
lw $t0, 8($t0)
sll $v0, $v0, 2
add $t0, $t0, $v0
lw  $v0, 0($t0)
lw $t1, 0($sp)
add $v0, $t1, $v0
addi $sp, $sp, 4
add $t0, $zero, $fp
addi $t0, $t0, 12
sw $v0, 0($t0)
lw   $t0, 4($sp)
lw   $v0, 16($t0)
addi $v0, $v0, 1
sw   $v0, 16($t0)
j for_start_2
for_end_2:
lw $t0, 4($sp)
lw $v0, 16($t0)
addi $v0, $v0, -1
sw $v0, 16($t0)
addi $sp, $sp, 8
add $t0, $zero, $fp
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $v0, $zero, 5
addi $v0, $v0, 1
addi $sp, $sp, -4
sw $v0, 0($sp)
addi $v0, $zero, 0
lw $t0, 4($sp)
sw $v0, 16($t0)
for_start_3:
lw   $v1, 0($sp)
slt  $t0, $v0, $v1
beq  $t0, $zero, for_end_3
add $t0, $zero, $fp
lw $v0, 16($t0)
add $t0, $zero, $fp
lw $t0, 8($t0)
sll $v0, $v0, 2
add $t0, $t0, $v0
lw  $v0, 0($t0)
add $t0, $zero, $v0
print_int($t0)
addi $t0, $zero, 10
print_char($t0)
lw   $t0, 4($sp)
lw   $v0, 16($t0)
addi $v0, $v0, 1
sw   $v0, 16($t0)
j for_start_3
for_end_3:
lw $t0, 4($sp)
lw $v0, 16($t0)
addi $v0, $v0, -1
sw $v0, 16($t0)
addi $sp, $sp, 8
print_str("sum of array=")
addi $t0, $zero, 10
print_char($t0)
add $t0, $zero, $fp
lw $v0, 12($t0)
add $t0, $zero, $v0
print_int($t0)
addi $t0, $zero, 10
print_char($t0)
addi $sp, $sp, 100
addi $v0, $zero, 17
syscall

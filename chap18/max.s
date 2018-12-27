# PURPOSE:	This program finds the maximum number of a
#		set of data items.
#
# VARIABLES:	The registers have the following uses:
#
#	%edi - Holds the index of the data item being examined
#	%ebx - Largest data item found
#	%eax - Current data item
#
#	The following memory locations are used:
#
#	data_items - contains the item data. A 0 is used to
#		terminate the data
#
	.section	.data
data_items:			# These are the data items
	.long	3, 67, 34, 222, 45, 75, 54, 34, 44, 33, 22, 11, 66, 0

	.section	.text
	.globl	_start
_start:
	movl	$0,	%edi	# Move 0 into the index register
	movl	data_items(, %edi, 4),	%eax
				# Load the first byte of data
	movl	%eax,	%ebx	# Since this is the first item, %eax is
				# the biggest

start_loop:
	cmpl	$0,	%eax	# Check to see if we have hit the end
	je	loop_exit
	incl	%edi		# Load next value
	movl	data_items(, %edi, 4),	%eax
	cmpl	%ebx,	%eax	# Compare values
	jle	start_loop	# Jump to loop beginning if the new
				# one is not bigger
	movl	%eax,	%ebx	# Move the value as the largest
	jmp	start_loop	# Jump to loop beginning

loop_exit:
	movl	$1,	%eax	# 1 is the _exit() syscall
	int	$0x80

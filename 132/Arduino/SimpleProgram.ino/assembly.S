include <avr.io.h>

.global function
function:

ldi r20, 0
ldi r21, 1
ldi r22, 1

label2:
cp r24, r20
breq label1
add r20, r22
lsl r21
jmp label2
label1:
mov r24, r21

ret

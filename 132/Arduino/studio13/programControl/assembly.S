#include <avr/io.h>

.global greaterThan
greaterThan:
cp r22, r24
brlt myLabel
ldi r24, 0
ret
myLabel: 
ldi r24, 1
ret


.global slowMultiply
slowMultiply:
ldi r20, 0  //sum
ldi r21, 0  //counter

recursiveLabel:
cp r21, r24
brlt  lastLabel
add r20, r22
jmp recursiveLabel

lastLabel:
add r18, r21
ret

.global slowExponent
slowExponent:
  ret

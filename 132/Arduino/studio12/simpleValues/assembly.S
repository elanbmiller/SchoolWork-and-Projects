#include <avr/io.h>

; AVR assembly comments start with a semicolon
// (or a double slash, like C)
; Lines without labels should be indented once.

.global giveMeMax
giveMeMax:
ldi r24, 254 // Load the value 1 into register 24
ret

// Define further "functions" below:
// .global functionName
// functionName:
//   *code*
//   ret

.global giveMeZero
giveMeZero:
call printRegs
ldi r24, 0
call printRegs
ret


.global addFour
addFour:
ldi r16, 4
add r24, r16
ret






.global filterAtIndex
filterAtIndex:
push r28
push r29

mov r18, r20
mov r19, r21

//this part is correct I believe


ldi r30, lo8(input2)
ldi r31, hi8(input2)
lsl r24  //left shifting which multiplies by 2 (r24x2)
rol r25  //left shift with carry, replacing lowest bit with carry (r25x2)
add r30, r24  //increasing the address
adc r31, r25  //increasing the address
ld r24, Z+
ld r25, Z


                                                                                          //accesing filter index specific element
ldi r26, lo8(fir1)
ldi r27, hi8(fir1)
lsl r22
rol r23
add r26, r22
adc r27, r23
ld r22, X+
ld r23, X


ldi r20, 15
ldi r21, 0

push r18
push r19

//push r24
//push r25

call qMultiply  //takes as parameters 25:24, 23:22, 21:20 ...--return value goes to r24 r25
//this is the end of correct part
pop r19
pop r18

//pop r25
//pop r24
//call printRegs
add r24, r18
adc r25, r19

//st y+, r18
//st y, r19
pop r29
pop r28

ret //ints are int 24 and 25


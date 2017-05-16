.name "st"
.comment ""

ldi %5, r2, r3
st r3, 50
ld %5, r4
sti r4, r3, %0
ld %1, r4
st r4, 50
#add r5, r5, r6
#zjmp %50
#add r2, r6, r4
#sub r5, r4, r8
#sub r8, r4, r7
#fork %10

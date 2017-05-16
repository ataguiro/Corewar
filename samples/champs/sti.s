.name "sti"
.comment ""

ldi %5, r2, r3
st r3, 50
ld %5, r4
sti r4, r3, %0
ld %1, r4
st r4, 50

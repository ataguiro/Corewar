.name "xor"
.comment ""

ld	%7, r2
xor %1, -5, r1
#and %0, -5, r31
zjmp	%550
st	r1, 75

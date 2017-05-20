.name "ld"
.comment ""

ld		%-1, r2
st		r2, 20
ld		%2, r3
add 	r2, r3, r4
st		r4, 25
live	%1

.name "fork"
.comment ""

fork	%10
ld 		%15, r4
st 		r4, 20 
fork	%40
fork	%256

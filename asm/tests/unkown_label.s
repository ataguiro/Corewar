.name "Basic"
.comment "Program"

ld		%1, r1
ld		%2, r2 # comment
live	%5
#zjmp	%:heyy
ld		:blah, r8

label:
	live %42

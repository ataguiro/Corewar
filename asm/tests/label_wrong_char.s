.name "Basic"
.comment "Program"

ld		%1, r1
ld		%2, r2 # comment
live	%5
zjmp	%:la$el

la$el:
	live %42

.name "zork"
.comment "I'M ALIIIIVE"

		live %0
		xor r1, %2, r2
		xor r1, %:live, r2
		sti r1, %:live, 4
live:	sti r1, %0, r1
		zjmp %:live

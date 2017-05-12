.name "zork"
.comment "I'M ALIIIIVE"

		zjmp %:live
live:	sti r1, r2, %1
		zjmp %:live

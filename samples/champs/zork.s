.name "zork"
.comment "I'M ALIIIIVE"

		and r1, %0, r1
l2:		sti r1, %:live, %1
live:	live %1
		zjmp %:live

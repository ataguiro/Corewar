.name "cheat"
.comment ""

l2:		sti r1, %:pouet, %1
		and r1, %0, r1

l1:		sti r1, %0, %1
		and r1, %0, r1

pouet:	live %2
		zjmp %:pouet

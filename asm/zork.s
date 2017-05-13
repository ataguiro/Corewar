# hi test


.name "zork"; this is a test
.comment "I'M ALIIIIVE" ;another test lol

l2:		sti r1, %:live, %1
		and r1, %0, r1
		and r1, %0, r1
		and r1, %0,r1
		and r155, %0, r1
		and r1, %0, r1

live:		live %1
		zjmp %:live
		live %2
		aff %4
		blablabla
		sti r1, %:l2, %5
		%5 sti, r1, %:l2

# hi test


.name "zork"; this is a test
.comment "I'M ALIIIIVE" ;another test lol

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		add r1, r2 ;added by ataguiro
		zjmp %:live

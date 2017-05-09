.name "test"
.comment "just"

		ld %0, r15
l1:		live %42
		zjmp %:l1

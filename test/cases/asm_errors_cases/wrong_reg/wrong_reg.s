.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		and r50, %0, r1

live:	live %1
		zjmp %:live

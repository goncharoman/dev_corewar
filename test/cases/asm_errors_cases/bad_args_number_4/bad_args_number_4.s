.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti
		and r1, %0, r1

live:	live %1
		zjmp %:live

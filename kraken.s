.name		"Kraken"
.comment	"Release the Kraken"

# live %42
ld %16777216,	r2		# store live oper
ld %191102976,	r3		# store sti

ld %50229260, 	r4		# store args: r2, %-400, r12
ld %33450764, 	r5		# store args: r1, %-405, r12

ld %33656842,	r6		# store args: r2, 400, r10
ld %16878346,	r7		# store args: r1, 395, r10

ld %100,		r11
ld %1,			r8

sti r1, %:tentacle, %1

tentacle:
		live %42
		xor r15, %2, r14
		zjmp %:tail
		add r15, r8, r15

first:
		sti r2, %-400, r12
		sti r1, %-405, r12
		sti r3, %-407, r12
		sti r4, %-411, r12
		sti r3, %-413, r12
		sti r5, %-417, r12
		lfork %-436

second:
		sti r2, %400, r10
		sti r1, %395, r10
		sti r3, %393, r10
		sti r6, %389, r10
		sti r3, %387, r10
		sti r7, %383, r10
		lfork %358

		sub r10, r11, r10
		add r12, r11, r12

		ld %0, r13
		zjmp %:tentacle
tail:

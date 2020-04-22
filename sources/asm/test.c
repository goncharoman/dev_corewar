#include <asm.h>

static void print_token(t_token *token)
{
	static int	n = 0;
	const char *dict[] = {	"CMD",
		"STR",
		"LBL",
		"OPR",
		"REG",
		"DIR",
		"DIRL",
		"IND",
		"INDL",
		"SEP",
		"ENDLN",
		"END"
		};


	printf("%03d [%03d, %03d] (% 5s)   %s\n", n++,
													token->row,
													token->col,
													dict[(int)token->type],
													token->value);
}

void	print_tokens(t_list **tokens)
{
	t_list *current;

	if (tokens)
	{
		if (*tokens)
		{
			current = *tokens;
			while (current)
			{
				print_token((t_token*)current->content);
				current = current->next;
			}
		}
	}
}

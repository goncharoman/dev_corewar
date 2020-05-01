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


	printf("%03d [%03d, %03d] (%5s)   %s\n", n++,
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


void	print_code(t_program *program)
{
	int fd;

	if ((fd = open("code_out", O_RDWR)))
		write(fd, program->code, program->position);
	close(fd);
}

static void	print_call(t_list *begin_call)
{
	t_call	*call;

	while (begin_call)
	{
		call = begin_call->content;
		printf("\t[%u:%u] %d %d\t%u\n", call->row, call->col, call->position, call->instrct_position, call->size);
		begin_call = begin_call->next;
	}
}

void 	print_labels(t_list *begin_label)
{
	t_label *label;

	while (begin_label)
	{
		label = begin_label->content;
		printf("( %s ) [%d]\n", label->name, label->position);
		print_call(label->calls);
		begin_label = begin_label->next;
	}

}

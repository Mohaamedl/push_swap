#include "push_swap.h"

int		rra(t_stack *a)
{
	reverse_rotate_stack(a);
	printf("rra%s\n","");
	return (1);
}

int		rrb(t_stack *b)
{
	reverse_rotate_stack(b);
	printf("rrb%s\n","");
	return (1);
}

int		rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	printf("rrr%s\n","");
	return (1);
}

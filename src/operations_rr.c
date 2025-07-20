#include "push_swap.h"

int		ra(t_stack *a)
{
	rotate_stack(a);
	printf("ra%s\n", "");
	return (1);
}

int		rb(t_stack *b)
{
	rotate_stack(b);
	printf("rb%s\n", "");
	return (1);
}

int		rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	printf("rr%s\n", "");
	return (1);
}


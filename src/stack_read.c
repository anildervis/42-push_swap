#include "push_swap.h"

int *argument_get(int argc, char **argv)
{
	int i;
	int j;
	char *str;
	char *old;
	char **stack_list;
	
	str = ft_calloc(2000, sizeof(char));
	i = 0;
    while (++i < argc)
    {
		stack_list = ft_split(argv[i], ' ');
		j = -1;
		while (stack_list[++j])
		{
			old = str;
			str = ft_strjoin(str, " ");
			free(old);
			old = str;
			str = ft_strjoin(str, argv[i]);
			free(old);
		}
	}
	free(stack_list);
	return (stack_converter(str));
}

int *stack_converter(char *str)
{
	int i;
	int len;
	int *stack;
	char **char_stack;

	char_stack = ft_split(str, ' ');
	i = 0;
	len = 0;
	while (char_stack[i++])
		len++;
	i = 0;
	stack = ft_calloc(len + 2, sizeof(int));
	stack[0] = len;
	while(++i <= len)
	{
		stack[i] = ft_atoi(char_stack[i - 1]);
		free(char_stack[i - 1]);
	}
	stack[i] = '\0';
	free(str);
	free(char_stack);
	return (stack);
}

// indexing can be optimized by using different algorithms
int *indexing(int *list)
{
    int i;
    int j;
    int *index;

    index = (int *)malloc(sizeof(int) * (list[0] + 2)); // null terminated
    index[0] = list[0];
    j = 0;
    while (++j <= list[0])
    {
        i = 0;
        index[j] = 0;
        while (++i <= list[0])
        {
            if (i != j)
            {
                if (list[i] == list[j])
                    exit(1);// duplicate error
                else if (list[j] > list[i])
                    index[j] += 1; 
            }
        }
    }
    index[j] = '\0';
    free(list);
    return (index);
}
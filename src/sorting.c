#include "push_swap.h"

void seperating_into_stacks(int *stack_a, int *stack_b)
{
    int i;
    int mid_point;
    int count;

    i = 0;
    mid_point = (int)(stack_a[0] / 2);
    count = stack_a[0];
    while (++i <= count)
    {
        if (stack_a[1] < mid_point)
            push_b(stack_a, stack_b);
        else
            rotate(stack_a, stack_b, 'a');
    }
}

void send_all_b(int *stack_a, int *stack_b)
{
    int i;
    int count;
    
    i = 0;
    count = stack_a[0];
    while (++i <= count) // son 3ü bırakıyoruz
    {
        if (stack_a[1] != (stack_a[0] + stack_b[0] - 1) && stack_a[1] != (stack_a[0] + stack_b[0] - 2) && stack_a[1] != (stack_a[0] + stack_b[0] - 3) && stack_a[1] != (stack_a[0] + stack_b[0] - 4) && stack_a[1] != (stack_a[0] + stack_b[0] - 5))
            push_b(stack_a, stack_b);
        else
            rotate(stack_a, stack_b, 'a');
    }
}

int ft_max_index(int *stack)
{
    int i;
    int rt;

    i = 0;
    rt = 1;
    while (++i <= stack[0])
    {
        if (stack[rt] < stack[i])
            rt = i;
    }
    return (rt);
}

int ft_min_index(int *stack)
{
    int i;
    int rt;

    i = 0;
    rt = 1;
    while (++i <= stack[0])
    {
        if (stack[rt] > stack[i])
            rt = i;
    }
    return (rt);
}

void sort_three(int *stack_a, int *stack_b)
{
    int i;
    int index_of_max;

    i = 0;
    index_of_max = ft_max_index(stack_a);
    if (index_of_max == 1)
        rotate(stack_a, stack_b, 'a');
    else if (index_of_max == 2)
        reverse_rotate(stack_a, stack_b, 'a');
    if (stack_a[1] > stack_a[2])
        swap(stack_a, stack_b, 'a');
}

void sort_four(int *stack_a, int *stack_b)
{
    int index_of_max;

    index_of_max = ft_max_index(stack_a);
    if (index_of_max == 2 || index_of_max == 3)
        rotate(stack_a, stack_b, 'a');
    if (index_of_max == 3)
        rotate(stack_a, stack_b, 'a');
    else if (index_of_max == 4)
        reverse_rotate(stack_a, stack_b, 'a');
    push_b(stack_a, stack_b);
    sort_three(stack_a, stack_b);
    push_a(stack_a, stack_b);
    rotate(stack_a, stack_b, 'a');
}

void sort_five(int *stack_a, int *stack_b)
{
    int index_of_max;

    index_of_max = ft_max_index(stack_a);
    if (index_of_max == 2 || index_of_max == 3)
        rotate(stack_a, stack_b, 'a');
    if (index_of_max == 3)
        rotate(stack_a, stack_b, 'a');
    if (index_of_max == 4 || index_of_max == 5)
        reverse_rotate(stack_a, stack_b, 'a');
    if (index_of_max == 4)
        reverse_rotate(stack_a, stack_b, 'a');
    push_b(stack_a, stack_b);
    sort_four(stack_a, stack_b);
    push_a(stack_a, stack_b);
    rotate(stack_a, stack_b, 'a');
}

int is_sorted(int *stack)
{
    int i;

    i = 0;
    while (++i < stack[0])
        if (stack[i] > stack[i + 1])
            return (0);
    return (1);
}

// en kısa hamle sayısını her pushtan sonra tekrar bulmak yerine
// daha optimal bir çözüm olarak her elemente + (rotate sayısı % stack[0])
// benzeri bir eklenti yapılabilir
int road_to_smallest_bigger_index(int *stack_a, int *stack_b, int position)
{
    int i;
    int index;

    i = 0;
    index = ft_max_index(stack_a);
    while (++i <= stack_a[0])
        if (((stack_a[i] - stack_b[position]) <= (stack_a[index] - stack_b[position])) && ((stack_a[i] - stack_b[position]) >= 0))
            index = i;
    if (index > ((int)(stack_a[0] / 2)) && position > ((int)(stack_b[0] / 2)))
        return (fmax(stack_a[0] - index + 1, stack_b[0] - position + 1));
    if (index <= ((int)(stack_a[0] / 2)) && position <= ((int)(stack_b[0] / 2)))
        return (fmax(index - 1, position - 1));
    return(fmin(fmin(index - 1 + stack_b[0] - position + 1, position - 1 + stack_a[0] - index + 1), fmin(fmax(index - 1, position - 1), fmax(stack_a[0] - index + 1, stack_b[0] - position + 1))));
}

void double_rotate(int a_road, int b_road, int *stack_a, int *stack_b)
{
    int i;
    
    i = 0;
    while (++i < a_road && i < b_road)
        rotate(stack_a, stack_b, 'r');
    i--;
    while (++i < a_road)
        rotate(stack_a, stack_b, 'a');
    i--;
    while (++i < b_road)
        rotate(stack_a, stack_b, 'b');
}

void double_reverse_rotate(int a_road, int b_road, int *stack_a, int *stack_b)
{
    int i;

    i = 0;
    a_road = stack_a[0] - a_road + 1;
    b_road = stack_b[0] - b_road + 1;
    while (++i <= a_road && i <= b_road)
        reverse_rotate(stack_a, stack_b, 'r');
    i--;
    while (++i <= a_road)
        reverse_rotate(stack_a, stack_b, 'a');
    i--;
    while (++i <= b_road)
        reverse_rotate(stack_a, stack_b, 'b');
}

void on_my_way(int a_road, int b_road, int *stack_a, int *stack_b)
{
    if (a_road <= ((int)(stack_a[0] / 2)))
    {
        b_road = stack_b[0] - b_road + 2;
        while (--a_road)
            rotate(stack_a, stack_b, 'a');
        while (--b_road)
            reverse_rotate(stack_a, stack_b, 'b');
    }
    else
    {
        a_road = stack_a[0] - a_road + 2;
        while (--b_road)
            rotate(stack_a, stack_b, 'b');
        while (--a_road)
            reverse_rotate(stack_a, stack_b, 'a');
    }
}

void send_all_a(int *stack_a, int *stack_b, int *stack_c)
{
    int i;
    int count;

    while (stack_b[0] > 0)
    {
        count = stack_b[0] + 1;
        stack_c[0] = stack_b[0];
        while (--count > 0)
            stack_c[count] = road_to_smallest_bigger_index(stack_a, stack_b, count);
        int b_road = ft_min_index(stack_c);
        int a_road = ft_max_index(stack_a);
        i = 0;
        while (++i <= stack_a[0])
            if (((stack_a[i] - stack_b[b_road]) <= (stack_a[a_road] - stack_b[b_road])) && ((stack_a[i] - stack_b[b_road]) >= 0))
                a_road = i;
        if (stack_c[b_road] == fmax(stack_a[0] - a_road + 1, stack_b[0] - b_road + 1))
            double_reverse_rotate(a_road, b_road, stack_a, stack_b);
        else if (stack_c[b_road] == fmax(a_road - 1, b_road - 1))
            double_rotate(a_road, b_road, stack_a, stack_b);
        else
            on_my_way(a_road, b_road, stack_a, stack_b);
        push_a(stack_a, stack_b);
        stack_c[stack_c[0]] = '\0';
    }
}

void last_sort(int *stack_a, int *stack_b)
{
    int i;
    int index_of_max;

    i = 0;
    index_of_max = ft_max_index(stack_a);
    if (index_of_max > ((int)(stack_a[0] / 2)))
    {
        while (++index_of_max <= stack_a[0])
            reverse_rotate(stack_a, stack_b, 'a');
    }
    else
    {
        while (--index_of_max >= 0)
            rotate(stack_a, stack_b, 'a');
    }
}

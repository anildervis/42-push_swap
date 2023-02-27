#include "push_swap.h"

int ft_strlen(char const *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    int i;
    int k;

    i = 0;
    k = 0;
    str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[k])
    {
        str[i + k] = s2[k];
        k++;
    }
    str[i + k] = 0;
    return (str);
}

#include <string.h>
#include <unistd.h>
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    //int n;

    while((s1[i] != '\0' || s2[i] != '\0') || (s1[i] == s2[i]))
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

int main(void)
{
    char s1[4] = "abc";
    char s2[3] = "ab";
    int str = ft_strcmp(s1, s2);
    int str1 = strcmp(s1, s2);
    printf("%d\n", str);
    printf("%d\n", str1);
}
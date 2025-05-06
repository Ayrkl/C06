#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

void ft_sort(char *argv[], int argc)
{
    int i, j;
    char *temp;

    for (i = 1; i < argc - 1; i++)
    {
        for (j = i + 1; j < argc; j++)
        {
            if (ft_strcmp(argv[i], argv[j]) > 0)
            {
                temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int i = 1;
    ft_sort(argv, argc);

    while (i < argc)
    {
        int j = 0;
        while (argv[i][j] != '\0')
        {
            write(1, &argv[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
    return 0;
}


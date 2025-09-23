#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    char *alpha = "abcdefghijklmnopkrstuvwxyz";
    char *alpha1 = "ABCDEFGHIJKLMNOPKRSTUVWXYZ";

    if (argc == 2)
    {
        char c = argv[1][i];
        while (argv[1][i])
        {
            int j = -1;
            if (c >= 'b' && c <= 'z')
            {
                while (c != alpha[j])
                {
                    write(1, &c, 1);
                    j++;
                }
            }
            else if (c >= 'B' && c <= 'Z')
            {
                while (c != alpha1[j])
                {
                    write(1, &c, 1);
                    j++;
                }
            }
            else if (c == 'a')
                write(1, &c, 1);
            else if (c == 'A')
                write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
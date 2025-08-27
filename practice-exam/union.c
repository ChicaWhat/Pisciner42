#include <unistd.h>

int main(int ac, char **av)
{
		int i = 0;
		int j = 0;
		char *s1 = av[1];
		char *s2 = av[2];
		char table[256] = {0};

		if (ac == 3)
		{
			while (s1[i])
			{
				if (s1[i] && !table[(int)s1[i]])
				{
					write(1, &s1[i], 1);
					table[(int)s1[i]] = 1;
				}
				i++;
			}
			while (s2[j])
			{
					if (s2[j] && !table[(int)s2[j]])
					{
							write(1, &s2[j], 1);
							table[(int)s2[j]] = 1;
					}
					j++;
			}
		}
		write(1, "\n", 1);
		return (0);
}

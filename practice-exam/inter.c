#include <unistd.h>

int main(int ac, char **av)
{
		int i = 0;
		int j;
		char inter[256] = {0};
		char *s1 = av[1];
		char *s2 = av[2];

		if (ac == 3)
		{
				while (s1[i])
				{
						j = 0;
						while (s2[j])
						{
								if (s1[i] == s2[j] && !inter[(int)s2[j]])
								{
										write(1, &s2[j], 1);
										inter[(int)s2[j]] = 1;
										break;
								}
								j++;
						}
						i++;
				}
		}
		write(1, "\n", 1);
		return (0);
}

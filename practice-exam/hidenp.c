#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
		int i = 0;
		int j = 0;
		//int flag = 1;
		char *str1 = argv[1];
		char *str2 = argv[2];

		if (argc == 3)
		{
				while (str1[i] != '\0' && str2[j] != '\0')
				{
						if (str1[i] == str2[j])
								i++;
							j++;
				}
				if (str1[i] == '\0')
						write(1, "1", 1);
				else
						write(1, "0", 1);
		}
		write(1, "\n", 1);
		return (0);
}

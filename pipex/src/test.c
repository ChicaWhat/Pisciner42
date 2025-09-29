#include "../pipex.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;

	char **path = get_path(envp);
	char *command = find_command_path(path, av[1]);
	if (command)
		ft_printf("%s\n", command);
	ft_free_all(path, command);
	return (0);
}
#include "../pipex.h"

void    ft_daddy(char **av, char **envp, int *fd)
{
    pid_t   pid_first_child;
    pid_t   pid_second_child;

    pid_first_child = fork();
    if (pid_first_child < 0)
        pipex_error(1);
    else if (pid_first_child == 0)
        ft_first_child(av, envp, fd);
    else
    {
        close(fd[1]);
        waitpid(pid_first_child, NULL, WNOHANG);
        pid_second_child = fork();
        if (pid_second_child < 0)
            pipex_error(1);
        else if (pid_second_child == 0)
            ft_second_child(av, envp, fd);
        else
        {
            close(fd[0]);
            waitpid(pid_second_child, NULL, WNOHANG);
        }
    }
}

 void    ft_first_child(char **av, char **envp, int *fd)
{
    int     input_fd;
    char    **path;
    char    *command_path;
    char    **command_split;

    close(fd[0]);
    input_fd = open(av[1], O_RDONLY);
    if (input_fd == -1)
        pipex_error(2);
    if (dup2(input_fd, STDIN_FILENO) == -1)
        pipex_error(9);
    close(input_fd);
    if (dup2(fd[1], STDOUT_FILENO) == -1)
        pipex_error(9);
    close(fd[1]);
    path = get_path(envp);
    command_path = find_command_path(path, av[2]);
    command_split = check_commands(av[2]);
    if (execve(command_path, command_split, envp) == -1)
        pipex_error(127);
    exit(1);
}

void    ft_second_child(char **av, char **envp, int *fd)
{
    int     output_fd;
    char    **path;
    char    *command_path;
    char    **command_split;

    close(fd[1]);
    output_fd = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
    if (output_fd == -1)
        pipex_error(2);
    if (dup2(fd[0], STDIN_FILENO) == -1)
        pipex_error(9);
    close(fd[0]);
    if (dup2(output_fd, STDOUT_FILENO) == -1)
        pipex_error(9);
    close(output_fd);
    path = get_path(envp);
    command_path = find_command_path(path, av[3]);
    command_split = check_commands(av[3]);
    if (execve(command_path, command_split, envp) == -1)
        pipex_error(127);
    exit(1);
}

int main(int ac, char **av, char **envp)
{
    int fd[2];
    (void)envp;

    if (ac != 5)
        write(2, "./pipex file1 comand1 comand2 file2\n", 36);
    if (pipe(fd) == -1)
        pipex_error(24);
    ft_first_child(av, envp, fd);
    else
    {
        ft_daddy(av, envp, fd);
    }
    return (0);
}

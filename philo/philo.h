/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 21:47:44 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/26 18:57:38 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include "./error.h"

# ifndef RED
#  define RED "\033[0;31m"
# endif
# ifndef BLUE
#  define BLUE "\033[0;34m"
# endif
# ifndef PURPLE
#  define PURPLE "\033[0;35m"
# endif
# ifndef CYAN
#  define CYAN "\033[0;36m"
# endif
# ifndef GREEN
#  define GREEN "\033[0;32m"
# endif
# ifndef RST
#  define RST "\033[0m"
# endif

typedef struct s_philo	t_philo;

/**
* @struct s_data
* @brief Shared program state. All philosophers read or modify this data.
*
* @var n_philos			Total number of philosophers (av[1]).
* @var time_to_die			Milliseconds without eating before death (av[2]).
* @var time_to_eat			Milliseconds spent eating (av[3]).
* @var time_to_sleep		Milliseconds spent sleeping after eating (av[4]).
* @var target_meals		Target meals per philosopher (optional av[5]).
* @var start_time			Program start timestamp in ms.
* @var dead_flag			0 = all alive, 1 = someone has died.
* @var forks_inited		Index of the last initialized fork mutex.
* @var monitor_created		1 if the monitor thread was created successfully.
* @var monitor				Thread that monitors deaths.
* @var mutex_dead			Mutex protecting dead_flag.
* @var forks				Array of fork mutexes.
* @var print_mutex			Ensures atomic, ordered prints.
* @var philos				Array of philosopher structs.
*/
typedef struct s_data
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				target_meals;
	long			start_time;
	int				dead_flag;
	int				forks_inited;
	int				monitor_created;
	pthread_t		monitor;
	pthread_mutex_t	*mutex_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	t_philo			*philos;
}	t_data;

/**
* @struct s_philo
* @brief Per-philosopher state and resources.
*
* @var id				Philosopher identifier (1-based).
* @var meals_eaten		Number of meals completed.
* @var last_meal_time	Timestamp (ms) of last meal start.
* @var thread			Philosopher execution thread.
* @var meal_mutex		Protects meals_eaten and last_meal_time.
* @var left_fork		Pointer to left fork mutex.
* @var right_fork		Pointer to right fork mutex.
* @var table			Pointer to the shared table data.
*/
typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*table;
}	t_philo;

/** @brief Free all resources of table depending on error_code. */
void	ft_cleanup(t_data *table, int error_code);

/** @brief Destroy meal mutexes up to meals_inited (inclusive). */
void	destroy_meal_mutex(t_data *table, int meals_inited);

/**
 * @brief Allocate and fill the main t_data structure from argv.
 * @param ac Argument count.
 * @param av Argument vector.
 * @return Pointer to t_data on success, NULL on failure.
 */
t_data	*init_data_struct(int ac, char **av);

/**
 * @brief Second init phase: set start_time, dead_flag, and init mutexes.
 * @param table Program table.
 * @return 0 on success, 1 on error.
 */
int		init_data2(t_data *table);

/**
 * @brief Init mutex_dead, print_mutex, forks array, and philos array.
 * @param table Program table.
 * @param dead_inited Output status of mutex init.
 * @param i Fork index.
 * @return 0 on success, 1 or 2 on failure.
 */
int		init_mutex(t_data *table, int *dead_inited, int i);

/**
 * @brief Init each philosopher meal_mutex.
 * @param table Program table.
 * @param meals_inited Last initialized index (output).
 * @return 0 on success, 1 on failure.
 */
int		init_mutex2(t_data *table, int *meals_inited);

/**
 * @brief Initialize one philosopher with id, times, and fork pointers.
 * @param philo Philosopher to init.
 * @param table Shared table.
 * @param i Index.
 */
void	init_one_philo(t_philo *philo, t_data *table, int i);

/** @brief Initialize all philosophers. */
void	init_philos(t_data *table);

/**
 * @brief Entry point. Validates args and starts program.
 * @return 0 on success, 1 on error.
 */
int		main(int ac, char **av);

/**
 * @brief Orchestrate initialization, threads, joins, and cleanup.
 * @param ac Argument count.
 * @param av Argument vector.
 * @return 0 on success, 1 on error.
 */
int		start_program(int ac, char **av);

/**
 * @brief Validate that all arguments are positive digit strings.
 * @param av Argument vector.
 * @return 1 if invalid, 0 if valid.
 */
int		is_av_valid(char **av);

/**
 * @brief Check argument count and validity. Prints errors on stderr.
 * @param ac Argument count.
 * @param av Argument vector.
 * @return 1 on error, 0 if OK.
 */
int		check_av(int ac, char **av);

/**
 * @brief Thread-safe print of philosopher state.
 * @param philo Philosopher.
 * @param status 1=fork, 2=eating, 3=sleeping, 4=thinking.
 */
void	ft_print_mutex(t_philo *philo, int status);

/**
 * @brief Check dead_flag before printing.
 * @param philo Philosopher.
 * @return 1 if dead, 0 otherwise.
 */
int		check_dead_before_print(t_philo *philo);

/**
 * @brief Print a philosopher death line.
 * @param philo Philosopher.
 */
void	print_dead(t_philo *philo);

/**
 * @brief Routine for the single philosopher case.
 * @param argv Philosopher pointer.
 * @return NULL.
 */
void	*one_philo_routine(void *argv);

/**
 * @brief Monitor routine: detects death and completion.
 * @param argv Table pointer.
 * @return NULL.
 */
void	*routine_monitor(void *argv);

/**
 * @brief Routine when target meals is provided.
 * @param argv Philosopher pointer.
 * @return NULL.
 */
void	*routine_with_av(void *argv);

/**
 * @brief Main philosopher routine (no target meals).
 * @param argv Philosopher pointer.
 * @return NULL.
 */
void	*routine(void *argv);

/**
 * @brief Eating logic for odd philosopher.
 * @param philo Philosopher.
 */
void	ft_odd_philo(t_philo *philo);

/**
 * @brief Eating logic for even philosopher (reverse fork order).
 * @param philo Philosopher.
 */
void	ft_pair_philo(t_philo *philo);

/**
 * @brief Dispatch eating logic by philosopher parity.
 * @param philo Philosopher.
 * @return 0 always.
 */
int		philo_eating(t_philo *philo);

/**
 * @brief Print sleeping and wait time_to_sleep, then check dead_flag.
 * @param philo Philosopher.
 * @param status Print status.
 * @return 1 if dead, 0 otherwise.
 */
int		philo_sleeping(t_philo *philo, int status);

/**
 * @brief Print thinking, short wait, then check dead_flag.
 * @param philo Philosopher.
 * @param status Print status.
 * @return 1 if dead, 0 otherwise.
 */
int		philo_thinking(t_philo *philo, int status);

/**
 * @brief Check if all philosophers reached target meals.
 * @param philo Any philosopher (to access table).
 * @return 0 if all done, 1 otherwise.
 */
int		all_philos_eaten(t_philo *philo);

/**
 * @brief Create monitor thread.
 * @param table Program table.
 * @return 0 on success, 1 on error.
 */
int		monitor_thread(t_data *table);

/**
 * @brief Create philosopher threads and the monitor.
 * @param philo Array of philosophers.
 */
void	ft_philo_thread(t_philo *philo);

/**
 * @brief Join philosopher threads and monitor if created.
 * @param table Program table.
 * @param threads_init Count of initialized threads.
 */
void	join_the_threads(t_data *table, int threads_init);

/**
 * @brief Return 1 if c is an ASCII digit, 0 otherwise.
 * @param c Character.
 * @return 1 or 0.
 */
int		is_digit(int c);

/**
 * @brief Convert digit string to int, return -1 on overflow.
 * @param s String.
 * @return Parsed int or -1.
 */
int		ft_atoi(char *s);

/**
 * @brief Compute string length (excluding null terminator).
 * @param s String.
 * @return Length.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Write string to fd.
 * @param s String.
 * @param fd File descriptor.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Return current time in ms using gettimeofday.
 * @return Time in ms.
 */
long	ft_gettimeofday(void);

/**
 * @brief Return elapsed ms since program start.
 * @param table Program table.
 * @return Elapsed ms.
 */
long	ft_now(t_data *table);

/**
 * @brief Set dead_flag if time_to_die exceeded.
 * @param philo Philosopher.
 * @return 1 if dead, 0 otherwise.
 */
int		set_dead(t_philo *philo);

/**
 * @brief Sleep in small slices while checking dead_flag.
 * @param philo Philosopher.
 * @param time_to_wait Time in ms.
 */
void	smart_usleep(t_philo *philo, int time_to_wait);

#endif
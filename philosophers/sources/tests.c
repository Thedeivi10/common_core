# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

#define TIMES_TO_COUNT 21000

# define NC "\e[0m"
# define YELLOW "\e[33m"
# define BYELLOW "\e[1;33m"
# define RED "\e[31m"
# define GREEN "\e[32m"

void	*thread_routine(void *data)
{
	pthread_t tid;
	unsigned int *count;
	unsigned int i;

	tid = pthread_self();
	count = (unsigned int *)data;
	printf("%sThread [%ld]: compte au depart = %u.%s\n",
		YELLOW, tid, *count, NC);
	i = 0;
	while (i < TIMES_TO_COUNT)
	{
		(*count)++;
		i++;
	}
	printf("%sThread [%ld]: Compte final = %u.%s\n", BYELLOW, tid, *count, NC);
	return (NULL);
}

int main (void)
{
	pthread_t tid1;
	pthread_t tid2;
	unsigned int count;

	count = 0;

	printf("Main: Le compte attendu est de %s%u%s\n", GREEN, 2 * TIMES_TO_COUNT, NC);
	pthread_create(&tid1, NULL, thread_routine, &count);
	printf("Main: Creation du premier thread [%ld]\n", tid1);

	pthread_create(&tid2, NULL, thread_routine, &count);
	printf("Main: Creation du second thread [%ld]\n", tid2);

	pthread_join(tid1, NULL);
	printf("Main Union du premiere thread [%ld]\n", tid1);
	pthread_join(tid2, NULL);
	printf("Main: Union du second thread [%ld]\n", tid2);

	if (count != (2 * TIMES_TO_COUNT))
		printf("%sMain: ERREUR ! Le compte est de %u%s\n", RED, count, NC);
	else
		printf("%sMain: OK. Le compte est de %u%s\n", GREEN, count, NC);
	return (0);
}

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

int main(void)
{
	struct timeval tv;
	time_t segundos;

	gettimeofday(&tv, NULL);
	printf("%ld\n", tv.tv_sec);
	segundos = tv.tv_sec;// * 1000;
	usleep(5000000); //  toma microsegundos aqui hay 5s
	gettimeofday(&tv, NULL);
	segundos = segundos - tv.tv_sec;
	printf("%ld\n", segundos);
/* 	Formula para el tiempo que es necesario
	(tv.tv_sec * 1000) + (tv.tv_usec / 1000) */
}
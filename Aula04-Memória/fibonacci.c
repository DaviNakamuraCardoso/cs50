#include <stdio.h>
#include <time.h>

long fibonaccis[2] = {1, 1};
long fibonacci(int a);

int main(void)
{
   int y;
   printf("Posição do número desejado: ");
   scanf("%i", &y);
   clock_t begin = clock();
   printf("%lu\n", fibonacci(y));
   clock_t end = clock();
   printf("Tempo total: %f\n", (double)(end-begin)/ CLOCKS_PER_SEC);
}

long fibonacci(int a)
{
    if (a == 1 || a == 2)
    {
    	return 1;
    }
    else
    {
    	for (int i = 0; i <= a-2; i++)
    	{
    	    long tmp = fibonaccis[1];
    	    fibonaccis[1] = fibonaccis[0] + fibonaccis[1];
    	    fibonaccis[0] = tmp;
    	}
    	return fibonaccis[1];
    }
}

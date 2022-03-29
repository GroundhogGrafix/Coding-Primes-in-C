#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<ggstd.h>
#include<graph.h>

char isprime4(n)
unsigned long n;
{
	unsigned long a, max_div;
	max_div = n/16;

	for(a = 2; a < max_div;a++)
		if((n%a) == 0.0)
			return FALSE;
	return TRUE;
}

char isprime3(n)
unsigned long n;
{
	unsigned long a, max_div;
	max_div = sqrt(n) + 1;

	for(a = 2; a < max_div;a++)
		if((n%a) == 0.0)
			return FALSE;
	return TRUE;
}

char isprime2(n)
unsigned long n;
{
	unsigned long a, max_div;
	max_div = (n >> 1) + 1;

	for(a = 2; a < max_div; a++)
		if((n%a) == 0.0)
			return FALSE;
	return TRUE;
}

char isprime1(n)
unsigned long n;
{
	unsigned long a;

	for(a = 2; a < n;a++)
		if((n%a) == 0.0)
			return FALSE;
	return TRUE;
}

int accTest(nprimes)
unsigned nprimes;
{
	unsigned long a, *primeNumbers = NULL, p = 2;
	int func = 3, kb = 0;

	char (*isprime[])(unsigned long) =
	{
		isprime3,
		isprime2,
		isprime1
	};

	primeNumbers = (unsigned long*) malloc(sizeof(long) * nprimes);

	while(func-- && !kb)
	{
		p = 2;
		for(a=0; a < nprimes && !(kb=kbhit());)
		{
			if(isprime[func](p))
			{
				if(2 == func)
					primeNumbers[a] = p;
				else if(p != primeNumbers[a])
					{
						printf("\nNumber not prime %lu\n", p);
						puts("Press key to exit...");
						getch();
						return 0;
					}
				printf("%-8lu", p);
				a++;
			}
			p++;
		}
	}
	return kb;
}

int main(argc,argv)
int argc;
char** argv;
{
	unsigned long p = 2;
	unsigned nprimes, a;
	int kb = 0;
	char (*isprime)(unsigned long) = NULL;

	_clearscreen(_GCLEARSCREEN);

	puts("How many primes do you want printed?");
	scanf(" %d", &nprimes);

	puts("Which test would you like to perform?");
	puts("1) isprime1");
	puts("2) isprime2");
	puts("3) isprime3");
	puts("4) Accuracy test for all the above.");
	puts("Press any other key to exit.");

	switch(getch())
	{
		case '1':
			isprime = isprime1;
			break;
		case '2':
			isprime = isprime2;
			break;
		case '3':
			isprime = isprime3;
			break;
		case '4':
			kb = accTest(nprimes);
			return 0;
			break;
		default:
			exit(0);
	}

	for(a=0; a < nprimes && !(kb=kbhit());)
	{
		if(isprime(p))
		{
			printf("%-8lu", p);
			a++;
		}
		p++;
	}

	if(kb)
		getch();

	return 0;
}

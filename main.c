#include <stdio.h>
#include <stdint.h>
#include <time.h>

void	prime(int32_t *num, int32_t *vul, int32_t half_num)
{
	while ((*num % *vul))
	{
		(*vul)++;
		if (*vul > half_num)
			*vul = *num;
	}
	*num /= *vul;
}

int32_t sumdigit(int32_t num)
{
	int32_t digit = 0;

	while (num)
	{
		digit += (num % 10);
		num /= 10;
	}
	return(digit);
}

int32_t summ_prime_factors(int32_t num)
{
	int32_t sum = 0;
	int32_t vul = 2;
	int32_t count = 0;

	while (num != 1)
	{
		prime(&num, &vul, num / 2);
		if (vul > 10)
			vul = sumdigit(vul);
		sum += vul;
		count++;
	}
	if (count == 1)
		return (0);
	return (sum);
}

void	some_samm_digits(int32_t num, int16_t count)
{
	while (count)
	{
		if (sumdigit(num) == summ_prime_factors(num))
		{
			printf("answer = %d\n", num);
			--count;
		}
		num++;
	}
}

int32_t	main(int32_t ac, char **av)
{
	clock_t start = clock();
	some_samm_digits(4937775, 10);
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f\n", time_spent);
	return (0);
}

/* print Celsius-Farenheit Table */

#include<stdio.h>


int main()
{
	int lower, upper, step;
	float fahr, celsius;

	lower = 0;
	upper = 100;
	step = 5;

	printf("Cel\tFahr\n");

	celsius = lower;
	while(celsius <= upper)
	{
		fahr = (celsius)*(5.0/9.0)+32;
		printf("%6.1f\t%4.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}

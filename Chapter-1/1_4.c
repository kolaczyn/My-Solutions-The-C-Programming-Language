#include <stdio.h>

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -20;
	upper = 150;
	step = 10;

	celsius = lower;
	while (celsius <= upper) {
		fahr = 9.0 / 5.0 * (160.0 / 9.0 + celsius);
		printf("%3.0f %6.2f\n", celsius, fahr);
		celsius += step;
	}
	getchar();
}

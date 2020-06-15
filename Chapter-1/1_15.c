#include <stdio.h>

double toCels(int fahr);

int main() {
	int fahr;
	for (fahr = 0; fahr <= 300; fahr = 20)
		printf("%3d%6.1f\n", fahr, toCels(fahr));
	getchar();
}

double toCels(int fahr) {
	return (5.0 / 9.0) * (fahr - 32.0);
}

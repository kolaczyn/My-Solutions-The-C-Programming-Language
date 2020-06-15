#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
	int v[9] = { 2, 3, 5, 5, 6, 9, 21, 25, 31 };
	printf("%d", binsearch(21, v, 9));
	getchar();
}

int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = mid = 0;
	high = n - 1;
	while (low <= high && v[mid] != x) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1; // it was '+' instead of '-' in my book. fixed that
		else if (x > v[mid])
			low = mid + 1;
	}
	if (v[mid] == x)
		return mid;
	return -1;
}
#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int* pmonth, int* pday);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int main() {
	int month = 6;
	int day = 21;
	
	printf("%d\n", day_of_year(2020, 6, 21));
	month_day(2019, 365, &day, &month);
	printf("%d - %d\n", day, month);
	getchar();
}


int day_of_year(int year, int month, int day) {
	int i, leap;
	// don't know which years are valid
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (day < 1 || daytab[leap][month] < day || month < 1 || month > 12)
		return -1;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int* pmonth, int* pday) {
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (yearday > leap + 365) {
		*pmonth = *pday = -1;
		return;
	}
	for(i=1; yearday>daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
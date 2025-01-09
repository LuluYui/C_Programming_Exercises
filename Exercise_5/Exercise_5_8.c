#include <ctype.h>
#include <stdio.h>

static char non_leap[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char leap_year[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *daytab[2] = {
  non_leap,
  leap_year
};

int day_of_year(int, int, int);
int month_day(int, int, int *, int *);

int main() {
  int year = 1998;
  int month = 3;
  int day = 25;

  printf("%d \n", day_of_year(1998,3,31));

  int *pmonth;
  int *pday;
  month_day(2000, 145, pmonth, pday);
  printf("%d \n", *pday);
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
  {
    if ( year < 0)
    {
      printf("negative year input : %d ", year );
      return 0;
    }
    if ( 0 > month > 12 )
    {
      printf("negative month input : %d ", year );
      return 0;
    }
    if ( 0 > day > 366 )
    {
      printf("negative month input : %d ", year );
      return 0;
    }

  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  for (i = 1; i < month; i++)
    day += daytab[leap][i];

  if ( 0 > day > 366)
    return 0;

  return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
  if ( year < 0 )
    {
      printf("incorrect year \n");
      return 0;
    }

  if ( 0 > yearday > 366)
    {
      printf("incorrect day \n");
      return 0;
    }

  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;


  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];

  if ( 0 > i > 12)
    return 0;

  if ( 0 > yearday > 366)
    return 0;

  *pmonth = i;
  *pday = yearday;

  return *pday;
}
#include <stdio.h>

#define MAX 1000
#define DEFAULT_TAB_LENGTH 4

// char str[] = " This \t is a \t tab\t\t \tstop test";
char str[] = "i \t\t\t ";

// char *entab(char *, char tab);
char *detab(char *);
char *entab(char *, char);
char result[MAX];

int c;
int arg_pos = 1;
int line_pos = 0;
int tab_stop = DEFAULT_TAB_LENGTH;
int nr_of_spaces = 0;

int main(int argc, char *argv[]){
  char tab;
  char *re;

  int nr_of_custom_tab_stops = argc - 1;
  entab(str, nr_of_custom_tab_stops);

  for (int i=0; re[i] != '\0'; i++)
    printf("%d ", re[i]);

  printf("\n");
  return 0;
}

void entab(char *str, char nr_of_custom_tab_stops)
{
  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
		{
			if (nr_of_custom_tab_stops)
			{
				tab_stop = atoi(argv[arg_pos++]);
				--nr_of_custom_tab_stops;
			}
			else if (argc > 1)
			{
				tab_stop = 1;
			}

			nr_of_spaces = tab_stop - line_pos % tab_stop;

			while (nr_of_spaces)
			{
				putchar(' ');
				++line_pos;
				--nr_of_spaces;
			}
		}
		else
		{
			putchar(c);
			++line_pos;

			if (c == '\n')
			{
				arg_pos = 1;
				line_pos = 0;
				nr_of_custom_tab_stops = argc - 1;
			}
		}
  }


}

char *detab(char *str) {
  int j=0, n=3;

  for (int i=0; str[i] != '\0'; i++)
  {
    if (str[i] == '\t')
    {
      int t=n;
      while(t--)
      {
        result[j++] = ' ';
      }
    } else
    {
      result[j++] = str[i];
    }
  }

  result[j] = '\0';

  return result;
}

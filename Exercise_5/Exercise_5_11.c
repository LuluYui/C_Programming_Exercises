#include <stdio.h>

#define MAX 1000

// char str[] = " This \t is a \t tab\t\t \tstop test";
char str[] = "i \t\t\t ";

// char *entab(char *, char tab);
char *detab(char *);
char *entab(char *, char);
char result[MAX];

int main(int argc, char *argv[]){
  char tab;
  char *re;

  // re = detab(str);
  re = entab(str, '\t');

  // while (--argc > 0 && (*++argv)[0])
  //   if (*argv[0]=='-')
  //     switch(*argv[1]) {
  //       case 't':
  //         tab = *argv[2];
  //         // re = entab(str, tab);
  //         break;
  //       default:
  //         re = detab(str);
  //         break;
  //     }
  //     else
  //       re = detab(str);

  for (int i=0; re[i] != '\0'; i++)
    printf("%d ", re[i]);

  printf("\n");
  return 0;
}

char *entab(char *str, char tab)
{
  int j=0, n=3;
  int spaces=0;

  for (int i=0; str[i] != '\0'; i++)
  {
    if (str[i] == '\t')
    {
      spaces += n;
    } else if (str[i] == ' ')
    {
      spaces++;
    } else
    {
      // file in blanks
      int num_tabs = spaces/3;
      int num_spaces = spaces%3;
      while (num_tabs--)
        result[j++] = '\t';
      while(num_spaces--)
        result[j++] = ' ';

      result[j++] = str[i];
    }
  }
  // file blanks up
  int num_tabs = spaces/3;
  int num_spaces = spaces%3;
  while (num_tabs--)
    result[j++] = '\t';
  while(num_spaces--)
    result[j++] = ' ';
  result[j] = '\0';

  return result;
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

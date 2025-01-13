#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABSTOP 4

int is_str_uint(char *str);
int is_tab_stop_arg_list_valid(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    char c;
    int pos = 1;
    int numSpace = 0;
    int numTabs = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (pos % TABSTOP != 0)  
            {
                ++numSpace;
            } else {
                numSpace = 0;
                ++numTabs;
            }
        } else {

            for (int i = 0; i < numTabs; ++i) 
                putchar('\t');
            numTabs = 0;

            if (c == '\t') {
                numSpace = 0;
                pos = pos + (TABSTOP - (pos - 1) % TABSTOP) - 1;
            }

            for (int i = 0; i < numSpace; i++) {
                putchar(' ');
            }

            numSpace = 0;
            putchar(c);
            
            if (c == '\n') 
                pos = 0;
        }

        ++pos;
  }

  return 0;
}

int is_str_uint(char *str)
{
  for (size_t i = 0; i < strlen(str); ++i)
  {
    if (!isdigit(str[i]))
    {
      return 0;
    }
  }
  return 1;
}

int is_tab_stop_arg_list_valid(int argc, char *argv[])
{
  for (size_t i = 1; i < argc; ++i)
  {
    if (!is_str_uint(argv[i]) || (i > 1 && atoi(argv[i - 1]) > atoi(argv[i])))
    {
      return 0;
    }
  }
  return 1;
}

// NOTE: The current program works in a similar fashion as unexpand.
// run: ./entab 4 8 12 16 > file_tabs.txt < file_spaces.txt
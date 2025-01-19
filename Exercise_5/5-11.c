#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABSTOP 4

int is_str_uint(char *str);
int is_tab_stop_arg_list_valid(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    if (!is_tab_stop_arg_list_valid(argc, argv)){
        printf("Error: Invalid Input Parameters\n");
        return 0;
    }

    int tab_stop = TABSTOP;
    int num_custom_tab_stop = argc - 1;
    char *start_ptr;
    
    if (num_custom_tab_stop) {
        tab_stop = atoi((++argv)[0]);
        num_custom_tab_stop--;
        start_ptr = *argv;
    } else {
      start_ptr = *argv;
    }

    char c;
    int pos = 1;
    int numSpace = 0;
    int numTabs = 0;

    // a\t  
    // 123456789xabcdef
    //    ^  

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (pos % tab_stop != 0)  
            {
                ++numSpace;
            } else {
                numSpace = 0;
                if (num_custom_tab_stop) {
                    tab_stop = atoi((++argv)[0]);
                    num_custom_tab_stop--;
                } 
                ++numTabs;
            }
        } else {
            for (int i = 0; i < numTabs; ++i) 
            {
              putchar('\t');
            }
            numTabs = 0;

            if (c == '\t') {
                numSpace = 0;
                pos = pos + (tab_stop - (pos - 1) % tab_stop) - 1;
            }

            for (int i = 0; i < numSpace; i++) {
                putchar(' ');
            }

            numSpace = 0;
            putchar(c);
            
            if (c == '\n') {
                num_custom_tab_stop = argc - 1;
                pos = 0;
                if (num_custom_tab_stop) {
                    tab_stop = atoi((++argv)[0]);
                    num_custom_tab_stop--;
                    argv = &start_ptr;
                } else {
                  argv = &start_ptr;
                }
            }
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>







char** _tokenization(char *str, char *_delimiters)
{

    char *token;
    int i = 0, token_idx = 0;
    char** local_argv;

    i = 0;
    while (str[token_idx] != '\0')
    {
        if (strchr(_delimiters, str[token_idx]))
            i++;
        token_idx++;
    }
    i++;

    local_argv = malloc(sizeof(char *) * (i + 1));

    token = strtok(str, _delimiters);
    token_idx = 0;
    while (token != NULL)
    {
        local_argv[token_idx] = token;
        token_idx++;
        token = strtok(NULL, _delimiters);
    }
    local_argv[token_idx] = NULL;

    return (local_argv);
}



int main (void)
{
  char** local_argv;
  
  char *getline_bffr = "  \n  \n";
  
  local_argv = _tokenization(getline_bffr, " \n\t\r");
  
  
    free(local_argv);
    
   
    
  return(0);
}
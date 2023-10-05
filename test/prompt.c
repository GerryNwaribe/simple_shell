#include "main.h"
/**
 * main: entry point
 * Return: 0
*/
int main(int argc, char *argv[])
{
    char *prompt_line, token;
    char *pointer_prompt, *pointer_prompt2;
    size_t size = 0; 
    ssize_t handle_error;
    const char *limit = " \n\t\r";
    int token_count = 0, a;
    int argv_count;
    (void)argc;
    /*allocate memeor for the copy of pointer*/
    pointer_prompt2 = malloc(sizeof(char *) * handle_error);
    if (pointer_prompt2 == NULL)
    {
        perror("sh");
        return (-1);
    }
    /*make a copy of string*/
    strcpy(pointer_prompt2, pointer_prompt);

     if (handle_error == -1)
    {
        return (-1);
    }
    else {
    /*calculate number of tokens*/
    token = strtok(pointer_prompt, limit);
    for (; token != NULL; token_count++)
    {
        token = strtok(NULL, limit);
    }
    token_count++;

    /*allocate space for array of strings (tokens)*/
    argv = malloc(sizeof(char *) * token_count);
    if (argv == NULL)
        return (-1);
    
    for (a = 0; token != NULL; a++)
    {
        argv[a] = malloc(sizeof(char) * strlen(token));
    }
    argv[a] = NULL;

    for (argv_count = 0; argv_count < token_count - 1; argv_count++)
    {
        _print_string(argv[argv_count]);
    }
    while(1)
    {
    prompt_line = "$ ";
    _print_string(prompt_line);
    handle_error = getline(&pointer_prompt, &size, stdin);

   
    _print_string(pointer_prompt);
    }
    free(pointer_prompt);
    free(pointer_prompt2);
    free(pointer_prompt);
    }
    return (0);

}
#include "main.h"
/**
 * 
 * 
*/
char *locate(char *a)
{
    char *track, *track2;
    int lenght = 0;
    char *token;
    char *limit = ":";
    int token_count = 0;
    int dir_lenght = 0;
    char *path;
    struct stat buffer;

    track = getenv("PATH");
    if (track != NULL)
    {
    track2 = strdup(track);
    track2 = malloc(strlen(track) + 1);
        if (track2 == NULL)
        {
            perror("sh");
            free(track);
            return (NULL);
        }
    
    lenght = strlen(a);
    token = strtok(track2, limit);
    while (token != NULL)
    {
        token_count++;
        token = strtok(NULL, limit);
    

    dir_lenght = strlen(token);
    path = malloc(lenght + dir_lenght + 2);
    if (path == NULL)
    {
        perror("sh");
            free(track);
            free(track2);
            return (NULL);
    }
    strcpy(path, token);
    strcat(path, "/");
    strcat(path, a);
    strcat(path, "\0");
    
    if (stat(path, &buffer) == 0)
    {
        free(track2);
        return (path);
    }
    }
    /*else{
        free(path);
        token = strtok(NULL, ":");
    }

    free(track2);
    if (stat(a, &buffer) == 0)
    {
        return(a);
    }
return (NULL);
    }
return (NULL);*/
       free(path);
        token = strtok(NULL, ":");
        }

        free(track2);
    

    return NULL;

}
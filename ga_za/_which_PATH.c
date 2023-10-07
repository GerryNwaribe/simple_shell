#include "main.h"

/**
 * get_PATH -
 * @cmmd:
 * Return:
 * 
 */
string get_PATH(string cmmd)
{
    int dir_length, _stat, __stat;
    string path, path_cp, path_token;
    struct stat bffr;

    path = getenv("PATH");
    if (path)
    {
        path_cp = strdup(path);
        int cmmd_length = strlen(cmmd);

        path_token = strtok(path_cp, ":");
        while (path_token != NULL)
        {
            dir_length = strlen(path_token);
            string file_path = malloc(cmmd_length + dir_length + 2);
            if (!file_path)
                free(file_path);

            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, cmmd);
            strcat(file_path, "\0");

            _stat = stat(file_path, &bffr);
            if (_stat == 0)
            {
                free(path_cp);
                return (file_path);
            }
            else
            {
                free(file_path);
                path_token = strtok(NULL, ":");
            }
        }
        
        if (path_cp != NULL)
            free(path_cp);

        __stat = stat(cmmd, &bffr);
        if (__stat == 0)
            return (cmmd);

        return (NULL);
    }
    return (NULL);
}

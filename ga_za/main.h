#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define ERROR -1
#define _bffsz 1024

typedef char *string;
typedef char **_dou_p;
typedef struct main
{
    string key_w;
    int (*_func)(_dou_p dou_argv);
} _is;

extern _dou_p environ;

int _strncmp(const char *str1, const char *str2, size_t n);
char *_strtok(string str, string _delimiters);
char *_strcat(string dest, string src);
char *_strcpy(string dest, string src);
int _strcmp(string s1, string s2);
int _strchr(string s, char c);
int _print_string(string st);
char *_strdup(string str);
int _strlen(string s);
int _putchar(char c);
int _isdigit(int c);
int _atoi(string s);

void execmd(_dou_p local_argv, _dou_p env, _dou_p argv);
ssize_t _getline(char **lineptr, size_t *n, FILE *f_d);
_dou_p _tokenization(string str, string _delimiters);
void _free(void *_malloc, int is_dou_p);
int (*_slt(string s))(_dou_p dou_argv);
int _exit_num(_dou_p local_argv);
string get_PATH(string cmmd);
string _getenv(string str);
int _is_prsent(string str);
int _cd(_dou_p cmmd);
int _env(_dou_p cmmd);

#endif /* End of if statement */

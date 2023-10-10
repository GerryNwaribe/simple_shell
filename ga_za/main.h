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

char *_strtok(string str, string _delimiters);
char *_strcat(string dest, string src);
char *_strcpy(string dest, string src);
int _strcmp(string s1, string s2);
int _strchr(string s, char c);
char *_strdup(string str);
int _strlen(string s);
int _isdigit(int c);
int _atoi(string s);

void execmd(_dou_p local_argv, _dou_p env, _dou_p argv);
_dou_p _tokenization(string str, string _delimiters);
void _free(void *_malloc, int is_dou_p);
void _exit_num(_dou_p local_argv);
int _print_string(string st);
string get_PATH(string cmmd);
string _getenv(string str);
void _cd(_dou_p cmmd);
int _putchar(char c);
void _env(void);


extern _dou_p environ;

#endif /* End of if statement */

#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>

#define ERROR -1
#define GERRY 1
#define _BFFSZ 1024

typedef char *string;
typedef char **dou_p;
/**
 * struct main - Structure representing a shell built-in command.
 * @key_w: The keyword or command name.
 * @_func: A pointer to the function that handles the command.
 * Return: 0
 */
typedef struct main
{
	string key_w;
	int (*_func)(dou_p dou_argv, size_t line_num, dou_p argv, dou_p _cmm);
} _is;
/**
 * struct _list - Structure representing a shell built-in command.
 * @name_value: member
 * @next: member
 * Return: 0
 */
typedef struct _list
{
	string name_value;
	struct _list *next;
} _list;

extern dou_p environ;

char *_strtok(string str, string _delimiters);
int _print_string(string st);
int _isblnk(char *str);
int _putchar(char c);
int _isdigit(int c);
int _atoi(string s);

int (*_slt(string s))(dou_p dou_argv, size_t line_num, dou_p argv, dou_p _cmm);
int _exit_num(dou_p local_argv, size_t line_num, dou_p argv, dou_p _cmm);
int _unsetenv(dou_p dou_argv, size_t line_num, dou_p argv, dou_p _cmm);
int _alias(dou_p local_argv, size_t line_num, dou_p argv, dou_p _cmm);
int _setenv(dou_p dou_argv, size_t line_num, dou_p argv, dou_p _cmm);
int _env(dou_p cmmd, size_t line_num, dou_p argv, dou_p _cmm);
int _cd(dou_p cmmd, size_t line_num, dou_p argv, dou_p _cmm);
int _is_prsent(string str);

int _execmd(dou_p dou_cm, dou_p env, dou_p av, size_t ln_nu, dou_p ft_cmm);
void _error_MESSAGE(dou_p argv, size_t line_num, dou_p cmmd, string key_w);
int _tokenize_slt_exec(string gtln, dou_p env, dou_p av, size_t l_dx);
int _semicolon(string gtln, dou_p env, dou_p av, size_t ln_cnt);
size_t _getline(char **getlineptr, size_t *bffsz, int f_d);
dou_p _tokenization(string str, string _delimiters);
string _nll_nwln(string gtln, ssize_t read);
void *_realloc(void *ptr, size_t new_size);
void _free(void *_malloc, int is_dou_p);
int _print_num(size_t _n, int _c);
int _is_semicolon(string gtln);
string _get_PATH(string cmmd);
void _pwd_update(char __s[]);
string _getenv(string str);

#endif /* End of Include Guard */

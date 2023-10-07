#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ERROR -1

typedef char* string;
typedef char** _dou_p;

char *_strtok(char *str, char *_delimiters);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strchr(char *s, char c);
int _strlen(char *s);

_dou_p _tokenization(char *str, char *_delimiters);
void execmd(_dou_p local_argv, _dou_p env);
void _free(void* _malloc, int is_dou_p);
int _print_string(string st);
string get_PATH(string cmmd);
int _putchar(char c);


#endif /* End of if statement */

/**
 *  pid_t fork(void);
 *  int execve(const char *pathname, char *const argv[], char *const envp[]);
 *
 * ========= wait, waitpid, waitid - wait for process to change state ============
 *  pid_t wait(int *wstatus);
 *  pid_t waitpid(pid_t pid, int *wstatus, int options);
 *  int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);
 *              This is the glibc and POSIX interface;
 *                  see NOTES for information on the raw system call.
 */

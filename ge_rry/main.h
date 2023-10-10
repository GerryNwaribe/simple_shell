#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define ERROR -1
#define BUFSIZE 1024
/*typedef char* string;
typedef char** _dou_p;*/

int _putchar(char c);
int _print_string(char* st);
void execute(char *argv[], char **env);
char *locate(char *a);
int _true_path(const char *pathname, struct stat *buffer);
ssize_t _getline(char **str, size_t *a, FILE *stream);
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

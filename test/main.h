#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#define ERROR -1

<<<<<<< HEAD
/*typedef char* string;
typedef char** _dou_p;*/
=======
typedef char *string;
typedef char **_dou_p;
>>>>>>> fc8a364d4de1cf4c10ebf26d0f0c1792de232d62

int _putchar(char c);
int _print_string(char* st);

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

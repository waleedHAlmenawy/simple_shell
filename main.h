#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>

#define R_BUF_SIZE 1024

#ifndef S_IFREG
#define S_IFREG 0100000
#endif

/* String Manipulation */
char *_strdup(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *str1, char *str2, int num);
void str_cut(char *l);
void _puts(char *);
int _putchar(char);

/* Memory Mangement */
void free_strigns(char **str_arr);
void free_elements(char **av, char *path, char **arr_path, char **cmds);
void free_path(char **path_arr);

/* PATH */
char *find_path(char **environ);
char **path_arr(char *path);
char **group_cmd(char **arr_p, char *cmd);

/* Helpers */
void buf_s(size_t *s, int n);
void handle_sign_sigint(int s_num);
int _sep(char *cmd);
char **tokenizer(char *l);

/* Shell */
void shell_loop(char **argv, char **environ);
ssize_t _line(char **l, size_t *num, int file_des);
void execute_shell_cmd(char *line, char **env);


#endif

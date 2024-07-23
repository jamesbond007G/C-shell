#ifndef HEADERS_H_
#define HEADERS_H_

#include "separate.h"
#include "warp.h"
#include "pastevents.h"
#include "sysco.h"
#include "peek.h"
#include "seek.h"
#include"pro.h"
#include <stdio.h>
#include <dirent.h>
// #include "prompt.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "pwd.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "sys/wait.h"
#include "time.h"
#include "math.h"

#define red_color "\x1b[31m"
#define blue_color "\x1b[34m"
#define green_color "\x1b[32m"
// #define violet_color "\x1b[35m"
#define reset_color "\x1b[0m"
#define directory_name_length 5000
#include "separate.h"

int compare_strings(const void *a, const void *b);
void run(char *instructions[2000], int instruction_count, char *directory, char *home_directory, char *code_store_directory, char *input, char *new_input_xxx);

void run_final(char *input, char *input_store, int *number, int backgroundid[500]);
void print_cur_directory();
char *make_path_for_tilda(char *a, char *b);
char *string(int length);
// char *string(int length)
char *changed_file_name_for_comparison(char *a);
int strcmp2(char *a, char *b);
int strcmp1(char *a, char *b);
// int compare_strings(const void *a, const void *b);
char *different(char *a, char *b);
char *make_path_for_spaces(char *instructions[2000], int i, int instruction_count);
void print_user(struct stat *info);
void print_group(struct stat *info);
void print_permission(__mode_t k);
int checkdirectory(struct stat info);
int checkexecutable(struct stat info);
FILE *open_c_file(const char *mode, char *home_directory_start_from_where);
FILE *open_b_file(const char *mode, char *home_directory_start_from_where);
void store(char instruction[4096], char *home_dir);
int check_readable(struct stat info);
char *filecat(char *a, char *b);
int min(int a, int b);
int compare_strings(const void *a, const void *b);
char *current_directory();
char *make_path_for_minus(char *a, char *b);
int check_valid_flag(char *instruction);
char *differentc(char *a, char *b);

#endif
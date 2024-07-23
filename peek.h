#ifndef PEEK_H_
#define PEEK_H_
void printcolor(char *input, char *path_entered);
void printdetails(char *input, char *path_entered);
void lshidden(char *path_entered);
void lslong(char *path_entered);
void ls_hidden_long(char *path_entered);
void ls_normal(char *path_entered);
void ls(char *instructions[2000], int instruction_index, int instructions_count);
#endif 
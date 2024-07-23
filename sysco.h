#ifndef SYSCO_H_
#define SYSCO_H_
void execute_system_call(char *instructions);
void run_background(int backgroundid[500], int *number, char *instructions);
#endif
#ifndef SEPARATE_H_
#define SEPARATE_H_
typedef struct process
{
    char *arr[100];
    int number;

} process;
void separate_foreground_background(process *background, process *foreground, char *input);
#endif
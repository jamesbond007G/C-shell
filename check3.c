#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void run_background(int backgroundid[500], int *number, int d)
{
    // int number = 5;
    // int backgroundid[number];

   
        int getid = fork();
        if (getid == 0)
        {
            int sleep_duration = d;
            // printf("%d")
            sleep(sleep_duration);
            exit(0);
        }
        else if (getid > 0)
        {
            printf("Process %d started with PID %d\n", i + 1, getid);
            backgroundid[*number] = getid;
            (*number) = (*number) + 1;
        }
    

    // sleep(20); // Give some time for background processes to start
}
void execute_system_call(char *instructions)
// {
//     char delimiter1[] = " \t";
//     char *small_instructions[2000];
//     for (int i = 0; i < 2000; i++)
//     {
//         small_instructions[i] = (char *)malloc(sizeof(char) * 1000);
//     }
//     char *token = strtok(instructions, delimiter1);
//     int count = 0;
//     while (token != NULL)
//     {
//         small_instructions[count++] = token;
//         token = strtok(NULL, delimiter1);
//     }
//     execvp(small_instructions[0], small_instructions);
//     return;
// }
// void print_detail_of_current_process()
// {
// }
// void print_detial_of_input(int i)
// {
//     struct passwd* info = getpid(i);
//     printf("%d", info.)
// }
int main()
{
    int number = 0;
    while (1)
    {
        int d;
        scanf("%d", &d);
        int backgroundid[500];
        run_background(backgroundid, &number, d);
        for (int i = 0; i < number; i++)
        {
            if (backgroundid[i] > 0)
            {
                pid_t result = waitpid(backgroundid[i], NULL, WNOHANG);
                if (result > 0)
                {
                    printf("Background process %d with PID %d has finished.\n", i + 1, backgroundid[i]);
                    backgroundid[i]=0;
                }
            }
        }
    }
    return 0;
}

#include "headers.h"

void run_background(int backgroundid[500], int *number, int d)
{
    // int number = 5;
    // int backgroundid[number];

    int getid = fork();
    if (getid == 0)
    {
        printf("gopal\n");
        char *instructions[4];
        for (int i = 0; i < 4; i++)
        {
            instructions[i] = (char*)malloc(sizeof(char)*2000);
        }
        strcpy(instructions[0], "sleep\0");
        printf("%s ", instructions[0]);
        // printf("%s ", instructions[1]);
        // printf("%s ", instructions[2]);
        char de[2];
        de[0] = d + '0';
        de[1] = '\0';

        strcpy(instructions[1], de);
        // strcpy(instructions[])
        instructions[2] = NULL;
        // int child = fork();
        execvp(instructions[0], instructions);

        // sleep(20); // Give some time for background processes to start
    }
    else if (getid > 0)
    {
        printf("Processstarted with PID %d\n", getid);
        backgroundid[*number] = getid;
        (*number) = (*number) + 1;
    }
}
// void execute_system_call(char *instructions)
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
                    backgroundid[i] = 0;
                }
            }
        }
    }
    return 0;
}

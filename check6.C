#include "headers.h"

void run_background(int backgroundid[500], int *number, char *instructions)
{
    // int number = 5;
    // int backgroundid[number];

    int getid = fork();
    if (getid == 0)
    {

        char delimiter1[] = " \t\n";
        char *small_instructions[2000];
        for (int i = 0; i < 2000; i++)
        {
            small_instructions[i] = (char *)malloc(sizeof(char) * 1000);
        }
        char *token = strtok(instructions, delimiter1);
        int count = 0;
        while (token != NULL)
        {
            strcpy(small_instructions[count++], token);
            token = strtok(NULL, delimiter1);
        }
        small_instructions[count] = NULL;
        if (execvp(small_instructions[0], small_instructions) == -1)
        {
            printf("no such command\n");
        }
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
        char input[4096];
        char *input_store = (char *)malloc(sizeof(char) * 4096);

        fgets(input, 4096, stdin);
        int backgroundid[500];
        run_background(backgroundid, &number, input);
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

#include"headers.h"
void execute_system_call(char *instructions)
{
    // int fork111 = fork();

    char *small_instructions[2000];
    // if (fork111 == 0)
    // {
    char delimiter1[] = " \t";
    for (int i = 0; i < 2000; i++)
    {
        small_instructions[i] = (char *)malloc(sizeof(char) * 1000);
    }
    char *token = strtok(instructions, delimiter1);
    int count = 0;
    while (token != NULL)
    {
        small_instructions[count++] = token;
        // printf("%s  ", token);
        token = strtok(NULL, delimiter1);
    }

    small_instructions[count] = NULL;
    int llll = fork();
    if (llll == 0)
    {
        if (execvp(small_instructions[0], small_instructions) == -1)
        {
            printf("invalid command\n");
            
            // main();
        }
    }
    else if (llll > 0)
    {
        wait(NULL);
        return; 
    }

    // return;
}
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
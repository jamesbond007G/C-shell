#include "headers.h"
int main()
{
    while (1)
    {
        /* code */

        int id = fork();
        int backgroundid[100];
        char input[4096];
        fgets(input, 4096, stdin);
        int number = 0;
        if (input[strlen(input) - 1] == '\n')
        {
            input[strlen(input) - 1] = '\0';
        }
        // printf("%s", input);
        if (id == 0)
        {
            printf("GOPAL");
            char delimiter1[4] = " \t";
            char *instructions[2000];
            // char delimiter1[4] = " \t";
            for (int i = 0; i < 2000; i++)
            {
                instructions[i] = (char *)malloc(sizeof(char) * 1000);
            }
            int instruction_count = 0;
            char *token = strtok(input, delimiter1);
            while (token != NULL)
            {
                strcpy(instructions[instruction_count++], token);

                printf("%s\n", token);
                char *token = strtok(NULL, delimiter1);
            }
            printf("\n");
            instructions[instruction_count] = NULL;
            execvp(instructions[0], instructions);
            // exit(1);
        }
        else if (id > 0)
        {
            printf("process is started %d\n", id);
            backgroundid[number++] = id;
        }
        for (int i = 0; i < number; i++)
        {
            if (backgroundid[i] > 0)
            {
                pid_t result = waitpid(backgroundid[i], NULL, WNOHANG);
                if (result > 0)
                {
                    printf("process is finished %d \n", backgroundid[i]);
                    backgroundid[i] = 0;
                }
            }
        }
    }
}
#include"headers.h"
void separate_foreground_background(process *background, process *foreground, char *input)
{
    char delimiter1[] = ";\n";
    // char delimiter2 = ';';
    char *instructions[2000];

    int instruction_count = 0;
    char *token = strtok(input, delimiter1);

    while (token != NULL)
    {
        instructions[instruction_count++] = token;
        token = strtok(NULL, delimiter1);
    }

    for (int i = 0; i < instruction_count; i++)
    {
        char delimiter2[] = "&";
        // if(instr)

        char *token1 = strtok(instructions[i], delimiter2);
        char *save_i_instruction = (char *)malloc(sizeof(char) * 4096);
        // strcpy(save_i_instruction, instructions[]) ;
        char *final_strings[200];
        for (int lol = 0; lol < 200; lol++)
        {
            final_strings[lol] = (char *)malloc(sizeof(char) * 4096);
        }
        int count = 0;
        while (token1 != NULL)
        {
            final_strings[count++] = token1;
            token1 = strtok(NULL, delimiter2);
        }
        int flag_for_background_process_available = 0;
        if (count == 1)
        {
            for (int j = 0; j < strlen(instructions[i]); j++)
            {
                if (instructions[i][j] == '&')
                {
                    flag_for_background_process_available = 1;
                    // printf("YES\n");
                }
            }
        }

        int lol1 = 0;

        for (lol1 = 0; lol1 <= count - 2; lol1++)
        {
            background->arr[background->number] = (char *)malloc(sizeof(char) * 4000);

            strcpy((*background).arr[(*background).number++], final_strings[lol1]);
        }
        foreground->arr[background->number] = (char *)malloc(sizeof(char) * 4000);

        strcpy((*foreground).arr[(*background).number++], final_strings[lol1]);
    }
}
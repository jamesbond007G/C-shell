#include"headers.h"
void warp(char *instructions[2000], int i, int instruction_count)
{
    char *newinput_path;
    newinput_path = make_path_for_spaces(instructions, i, instruction_count);
    char previous[4096];
    int start = strlen(directory) - 1;
    char doubledot[4] = "..";
    char minus[4] = "-";
    char delimiter[] = " ";
    char *token4 = strtok(instructions[i], delimiter);
    if (token4[0] == '-')
    {
        char previousnew[4096];
        char *new_path = make_path_for_minus(previous, newinput_path);
        strcpy(previousnew, current_directory());
        chdir(new_path);
        // free(new_path);
        strcpy(previous, previousnew);
        // printf("%s\n", previous);
    }
    else if (token4[0] == '~')
    {
        strcpy(previous, current_directory());
        chdir(make_path_for_tilda(home_directory, newinput_path));
    }
    else
    {
        // printf("%s\n", instructions[i + 1]);
        // strcpy(previous, directory);
        strcpy(previous, current_directory());

        // printf("%s\n", new_input_xxx);
        chdir(newinput_path);
    }

    // printf()
    i = instruction_count;
}

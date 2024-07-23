#include "headers.h"
int get_end_for_i(int i, char *home_dir)
{
    int k = 0;
    for (int j = 1; j < i; j++)
    {
        k = k - (read_bytes_from_file(j, home_dir) + 1);
    }
    return k;
}
int get_begin_for_i(int i, char *home_dir)
{
    int k = 0;
    int end = get_end_for_i(i, home_dir);
    int begin = end - read_bytes_from_file(i, home_dir) - 1;

    return begin;
}
char *get_instructions_for_i(int i, char *home_dir)
{
    FILE *fptr = open_c_file("r", home_dir);
    fseek(fptr, get_begin_for_i(i, home_dir), SEEK_END);
    
    int size = read_bytes_from_file(i, home_dir);
    char *buffer = (char *)malloc(sizeof(char) * (4096));
    int k = fread(buffer, 1, size, fptr);
    buffer[k] = '\0';
    fclose(fptr);
    return buffer;
}
void pastevents_delete(char *home_dir)
{
    FILE *fptr = open_c_file("w", home_dir);
    FILE *fptr1 = open_b_file("w", home_dir);
    fclose(fptr);
    fclose(fptr1);
}
void pastevents_execute(int n, char *home_dir, char *directory, char *home_directory, char *code_store_directory, char *input, char *new_input_xxx)
{
    char *instruction[2];
    instruction[0] = (char *)malloc(sizeof(char) * 500);
    instruction[0] = get_instructions_for_i(n, home_dir);
    char *input_store;
    input_store = (char *)malloc(sizeof(char) * 4096);
    run_final(instruction[0], input_store, &number, backgroundid);
}
int check_past_events_in_input(char *input)
{
    // char targ
    char delimiter1[] = " ;\t\n&";
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
        if (strcmp(instructions[i], "pastevents") == 0)
        {
            return 1;
        }
    }
    return 0;
}
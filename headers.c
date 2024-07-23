#include "headers.h"

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
char *current_directory()
{
    char *cur_directory = (char *)malloc(sizeof(char) * 5000);
    getcwd(cur_directory, 5000);
    return cur_directory;
}
void run(char *instructions[2000], int instruction_count, char *directory, char *home_directory, char *code_store_directory, char *input, char *new_input_xxx)
{
    for (int i = 0; i < instruction_count; i++)
    {
        if (strcmp(instructions[i], "warp") == 0)
        {

            // char previous[4096];
            // printf("YES\n");
            // printf("%d", instr)
            if (i + 1 == instruction_count)
            {
                printf("%s\n", current_directory());
                strcpy(previous, current_directory());
                chdir(home_directory);
                i = i + 1;
                print_cur_directory();
                continue;
            }
            // printf("%d",i);
            // printf("%s", instructions[i]);
            int j;
            // printf("%s\n", instructions[i+1]);
            for (j = i + 1; j < instruction_count; j++)
            {
                if (instructions[j][0] == '.' && instructions[j][1] == '\0')
                {
                    strcpy(previous, current_directory());
                    // printf("YES\n");
                    print_cur_directory();
                    continue;
                }
                else if (instructions[j][0] == '-')
                {
                    char previousnew[4096];
                    // printf("%s", current_directory)
                    // char *new_path = make_path_for_minus(previous, newinput_path);
                    strcpy(previousnew, current_directory());
                    chdir(previous);
                    // free(new_path);
                    strcpy(previous, previousnew);
                }
                else if (instructions[j][0] == '~')
                {
                    strcpy(previous, current_directory());

                    chdir(make_path_for_tilda(home_directory, instructions[j]));
                }
                else
                {

                    strcpy(previous, current_directory());

                    if (chdir(instructions[j]) == -1)
                    {
                        printf("no such directory\n");
                    }
                }
            }
            i = j;
            print_cur_directory();

            // printf()
        }
        // free(newinput_path);

        else if (strcmp(instructions[i], "peek") == 0)
        {
            ls(instructions, i, instruction_count);
            i++;
            while ((i != instruction_count - 1) && instructions[i][0] == '-')
            {

                i++;
            }
            if (i == instruction_count - 1)
            {
                i = i + 1;
            }
        }
        else if (strcmp(instructions[i], "pastevents") == 0)
        {
            if (strcmp(instructions[i + 1], "purge") == 0)
            {
                int z = 1;
                pastevents_delete(code_store_directory);
                i = i + 2;
            }
            else if (strcmp(instructions[i + 1], "execute") == 0)
            {
                int l = 1;
                // atoi(instructions[i+])
                pastevents_execute(atoi(instructions[i + 2]), code_store_directory, directory, home_directory, code_store_directory, input, new_input_xxx);
                i = i + 3;
            }
            else
            {
                FILE *fptr12 = open_b_file("r", code_store_directory);
                fseek(fptr12, 0, SEEK_END);
                int size_of_file = ftell(fptr12);
                // printf("%d", size_of_file);
                for (int i = 1; i < min(size_of_file / 5, 16); i++)
                {
                    printf("%s\n", get_instructions_for_i(i, code_store_directory));
                }
                fclose(fptr12);
                i = i + 1;
            }
        }
        else if (strcmp(instructions[i], "seek") == 0)
        {
            i++;
            int f_flag = 0;
            int d_flag = 0;
            int e_flag = 0;
            while (instructions[i][0] == '-')
            {
                if (strcmp(instructions[i], "-f") == 0 && check_valid_flag(instructions[i]))
                {
                    f_flag = 1;
                }
                if (strcmp(instructions[i], "-d") == 0 && check_valid_flag(instructions[i]))
                {
                    d_flag = 1;
                }
                if (strcmp(instructions[i], "-e") == 0 && check_valid_flag(instructions[i]))
                {
                    e_flag = 1;
                }
                if (check_valid_flag(instructions[i]) == 0)
                {
                    printf("Invalid flag %s\n", instructions[i]);
                }

                i++;
            }

            char *to_find = (char *)malloc(sizeof(char) * 500);
            strcpy(to_find, instructions[i]);
            char path_to_be_entered[4000];
            if (i == instruction_count - 1)
            {

                getcwd(path_to_be_entered, sizeof(path_to_be_entered));
                i = i + 1;
            }
            else
            {
                strcpy(path_to_be_entered, instructions[i + 1]);
                i = i + 2;
            }
            int no_of_files = seek_e_count_f(path_to_be_entered, to_find, 1, 0);
            int no_of_folders = seek_e_count_d(path_to_be_entered, to_find, 0, 1);

            if (f_flag == 1 && d_flag == 0 && e_flag == 1)
            {
                if (no_of_files == 0)
                {
                    printf("No files found\n");
                }
                else if (no_of_files == 1)
                {
                    // printf("LOLLLL\n");
                    seek_e(path_to_be_entered, to_find, 1, 0, path_to_be_entered);
                }
            }
            else if (f_flag == 1 && d_flag == 0 && e_flag == 0)
            {
                if (no_of_files == 0)
                {
                    printf("No files found\n");
                }
                else
                {
                    seek_f(path_to_be_entered, to_find, path_to_be_entered);
                }
            }
            else if (f_flag == 0 && d_flag == 1 && e_flag == 1)
            {
                if (no_of_folders == 0)
                {
                    printf("No directories found\n");
                }
                else if (no_of_folders == 1)
                {
                    seek_e(path_to_be_entered, to_find, 0, 1, path_to_be_entered);
                }
            }
            else if (f_flag == 0 && d_flag == 1 && e_flag == 0)
            {
                if (no_of_folders == 0)
                {
                    printf("No directories found\n");
                }
                else
                {
                    seek_d(path_to_be_entered, to_find, path_to_be_entered);
                }
            }
            else if (f_flag == 1 && d_flag == 1 && e_flag == 0)
            {
                if (no_of_folders + no_of_files == 0)
                {
                    printf("No directories or file found\n");
                }
                else
                {
                    seek_normal(path_to_be_entered, to_find, path_to_be_entered);
                }
            }
            else if (f_flag == 1 && d_flag == 1 && e_flag == 1)
            {
                if (no_of_files + no_of_folders == 0)
                {
                    printf("No directories or file found\n");
                }
                else if (no_of_files + no_of_folders == 1)
                {
                    seek_e(path_to_be_entered, to_find, 1, 1, path_to_be_entered);
                }
            }
            else if (f_flag == 0 && d_flag == 0 && e_flag == 1)
            {
                if (no_of_files + no_of_folders == 0)
                {
                    printf("No directories or file found\n");
                }
                else
                {
                    if (no_of_files + no_of_folders == 1)
                    {
                        seek_e_normal(path_to_be_entered, to_find, 0, 0, path_to_be_entered);
                    }
                }
            }
            else if (f_flag == 0 && d_flag == 0 && e_flag == 0)
            {
                if (no_of_files + no_of_folders == 0)
                {
                    printf("No directories or file found\n");
                }
                else
                {
                    seek_normal(path_to_be_entered, to_find, path_to_be_entered);
                }
            }
        }
        else if (strcmp(instructions[i], "proclore") == 0)
        {
            int pid;
            if (instruction_count == 1)
            {
                pid = getpid();
            }
            else
            {
                pid = atoi(instructions[i + 1]);
            }
            proclore(pid);
            i = i + 1;
        }
        else if (strcmp(instructions[i], "exit") == 0)
        {
            char *exit1 = string(4096);
            strcpy(exit1, "exit");
            store(exit1, code_store_directory);
            // free(input_store);
            exit(0);
        }
        else
        {
            char *maaa = (char *)malloc(sizeof(char) * directory_name_length);
            strcpy(maaa, new_input_xxx);

            // int fo = fork();

            execute_system_call(new_input_xxx);
            // printf("goapl %s\n", new_input_xxx);
            char delimiter1[] = " \t";

            char *token = strtok(maaa, delimiter1);
            while (token != NULL)
            {
                i++;

                token = strtok(NULL, delimiter1);
            }
            // printf("goapl\n");
        }
    }
}
void run_final(char *input, char *input_store, int *number, int backgroundid[500])
{
    if (input[strlen(input) - 1] == '\n')
    {
        input[strlen(input) - 1] = '\0';
    }
    strcpy(input_store, input);
    process foreground;
    process background;
    foreground.number = 0;
    background.number = 0;
    for (int i = 0; i < 100; i++)
    {
        foreground.arr[i] = NULL;
        background.arr[i] = NULL;
    }

    separate_foreground_background(&background, &foreground, input);
    for (int i = 0; i < background.number; i++)
    {
        // printf("gopal\n");
        if (foreground.arr[i])
        {
            // printf("go=== %s\n", foreground.arr[i]);
            char *new_input_xxx = (char *)malloc(sizeof(char) * 5000);
            strcpy(new_input_xxx, foreground.arr[i]);
            // printf("foreground = %s\n", foreground.arr[i]);
            char *instructions[2000];
            char delimiter1[20] = " \t\n";
            for (int i = 0; i < 2000; i++)
            {
                instructions[i] = (char *)malloc(sizeof(char) * 1000);
            }
            int instruction_count = 0;
            char *token = strtok(foreground.arr[i], delimiter1);

            while (token != NULL)
            {
                instructions[instruction_count++] = token;
                // printf("%s ", token);
                token = strtok(NULL, delimiter1);
            }
            // printf("%dgg\n", instruction_count);
            if (instruction_count != 0)
            {
                int fo = fork();
                if (fo == 0)
                {
                    run(instructions, instruction_count, directory, home_directory, code_store_directory, input_store, new_input_xxx);
                }
                // printf("%dgopalaaaa\n",i);
                else if (fo)
                {
                    int status;

                    waitpid(fo, &status, 0);
                }
            }
        }
        else if (background.arr[i])
        {
            // printf("background = %s\n", background.arr[i]);
            // int fork213 = fork();

            // printf("g\n");
            run_background(backgroundid, number, background.arr[i]);
            // printf("gopal%d\n",background.number);
        }
    }

    if (check_past_events_in_input(input) != 1)
    {
        store(input_store, code_store_directory);
        free(input_store);
    }
    // printf("goapl%d\n", 1);
    // print_background_status(number, backgroundid);
}
void print_cur_directory()
{
    char directory[256];
    getcwd(directory, sizeof(directory));
    printf("%s\n", directory);
}

char *string(int length)
{
    char *a;
    a = (char *)malloc(sizeof(char) * (length + 3));
}

char *changed_file_name_for_comparison(char *a)
{

    char *c = (char *)malloc(sizeof(char) * (strlen(a) + 2));
    int i = 0;
    int j = 0;
    while (i != strlen(a))
    {

        if ((int)a[i] <= 90 && (int)a[i] >= 65)
        {
            int k = ((int)a[i]) + 32;
            c[j++] = (char)k;
        }
        else if ((int)a[i] >= 97 && (int)a[i] <= 122)
        {
            c[j++] = a[i];
        }
        else if ((int)a[i] >= 48 && (int)a[i] <= 57)
        {
            c[j++] = a[i];
        }

        i++;
    }
    c[j] = '\0';
    return c;
}
int strcmp2(char *a, char *b)
{
    int compare;
    if (strlen(a) < strlen(b))
    {
        compare = strlen(a);
    }
    else
    {
        compare = strlen(b);
    }
    for (int i = 0; i < compare; i++)
    {
        if (a[i] > b[i])
        {
            return 1;
        }
        else if (b[i] > a[i])
        {
            return 0;
        }
        else
        {
            continue;
        }
    }
    if (strlen(a) > strlen(b))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    // return 1;
}

int strcmp1(char *a, char *b)
{
    char *modifieda = changed_file_name_for_comparison((char *)a);
    char *modifiedb = changed_file_name_for_comparison((char *)b);
    return strcmp2(a, b);
}

char *different(char *a, char *b)
{
    int la = strlen(a);
    int lb = strlen(b);
    int lc = lb - la;

    char *c = (char *)malloc(sizeof(char) * (lc + 5));
    if (la > lb)
    {
        return b;
    }
    if (la == lb)
    {
        c = '\0';
        return c;
    }
    c[0] = '~';
    // c[1] = '/';
    int i = 0;
    int j = 1;
    if (strncmp(b, a, la - 1) == 0)
    {
        // printf("YES\n");
        for (i; i < lc; i++, j++)
        {
            c[j] = b[i + la];
        }
        c[j] = '\0';
    }
    else
    {
        return b;
    }
    // printf("%s", c);
    return c;
}
char *differentc(char *a, char *b)
{
    int la = strlen(a);
    int lb = strlen(b);
    int lc = lb - la;

    char *c = (char *)malloc(sizeof(char) * (lc + 5));
    if (la > lb)
    {
        return b;
    }
    if (la == lb)
    {
        c = '\0';
        return c;
    }
    c[0] = '.';
    // c[1] = '/';
    int i = 0;
    int j = 1;
    if (strncmp(b, a, la - 1) == 0)
    {
        // printf("YES\n");
        for (i; i < lc; i++, j++)
        {
            c[j] = b[i + la];
        }
        c[j] = '\0';
    }
    else
    {
        return b;
    }
    // printf("%s", c);
    return c;
}
char *make_path_for_tilda(char *a, char *b)
{
    char *c = (char *)malloc(sizeof(char) * (strlen(a) + strlen(b) + 3));
    // c = "\0";
    strcpy(c, a);
    for (int i = 1; i < strlen(b); i++)
    {
        char temp[3];
        temp[0] = b[i];
        temp[1] = '\0';
        strcat(c, temp);
    }

    return c;
}
char *make_path_for_spaces(char *instructions[2000], int i, int instruction_count)
{
    char *c = (char *)malloc(sizeof(char) * directory_name_length);
    strcpy(c, instructions[i + 1]);
    for (int k = i + 2; k < instruction_count; k++)
    {
        char temp[2];
        temp[0] = '/';
        temp[1] = '\0';
        if (instructions[k][0] != '/')
        {
            strcat(c, temp);
            strcat(c, instructions[k]);
        }
        else
        {
            strcat(c, instructions[k]);
        }
    }
    return c;
}
void print_user(struct stat *info)
{
    int id = (*info).st_uid;
    struct passwd *info1 = getpwuid(id);
    // char *user_name = (char *)malloc(sizeof(char) * 200);
    // strcpy(user_name, info1->pw_name);
    if (info1 != NULL)
    {
        printf("\t%s", info1->pw_name);
    }
}
void print_group(struct stat *info)
{
    int id = (*info).st_gid;
    struct passwd *info1 = getpwuid(id);
    if (info1 != NULL)
    {
        printf("\t%s", info1->pw_name);
    }
}
void print_permission(__mode_t k)
{
    char permissions[9][4];
    strcpy(permissions[0], "---");
    strcpy(permissions[1], "--x");
    strcpy(permissions[2], "-w-");
    strcpy(permissions[3], "-wx");
    strcpy(permissions[4], "r--");
    strcpy(permissions[5], "r-x");
    strcpy(permissions[6], "rw-");
    strcpy(permissions[7], "rwx");
    char dash[2];
    dash[0] = '-';
    dash[1] = '\0';
    char *final_permission = (char *)malloc(sizeof(char) * 20);
    strcpy(final_permission, permissions[(k >> 6) % 8]);
    strcat(final_permission, permissions[(k >> 3) % 8]);
    strcat(final_permission, permissions[k & 7]);
    printf("%s", final_permission);
    free(final_permission);
}
int checkdirectory(struct stat info)
{
    return S_ISDIR(info.st_mode);
}
int checkexecutable(struct stat info)
{
    __mode_t permissions = info.st_mode;
    if (info.st_mode & S_IXUSR)
    {
        return 1;
    }
    else
        return 0;
}
FILE *open_c_file(const char *mode, char *home_directory_start_from_where)
{
    char *path = (char *)malloc(sizeof(char) * 5000);
    strcpy(path, home_directory_start_from_where);
    strcat(path, "/files_for_storing/save_commands.txt");
    FILE *k = fopen(path, mode);
    return k;
}

FILE *open_b_file(const char *mode, char *home_directory_start_from_where)
{
    // FILE *k = fopen("save_bytes.txt", mode);
    char *path = (char *)malloc(sizeof(char) * 5000);
    strcpy(path, home_directory_start_from_where);
    strcat(path, "/files_for_storing/save_bytes.txt");
    return fopen(path, mode);
}
void store(char instruction[4096], char *home_dir)
{

    FILE *fptr = open_c_file("a", home_dir);
    FILE *fptr1 = open_b_file("a", home_dir);
    char *new_string = (char *)malloc(sizeof(char) * 5000);
    strcpy(new_string, instruction);
    char *string_for_comparison = (char *)malloc(sizeof(char) * 5000);
    string_for_comparison = get_instructions_for_i(1, home_dir);
    if (strcmp(string_for_comparison, new_string) != 0)
    {
        // fseek(fptr, 0,SEEK_SET);

        fprintf(fptr, "%s\n", new_string);
        // fprintf(fptr, "\n");
        int numberofdigits;
        numberofdigits = (int)log10(strlen(new_string)) + 1;
        int temp = 4 - numberofdigits;
        while (temp--)
        {
            fprintf(fptr1, "%d", 0);
        }
        fprintf(fptr1, "%ld\n", strlen(new_string));
        // fprintf(fptr1, "\n");
    }
    fclose(fptr);
    fclose(fptr1);
    // return;
}
int check_readable(struct stat info)
{
    __mode_t permissions = info.st_mode;
    if ((permissions >> 6) % 8 >= 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char *filecat(char *a, char *b)
{
    char temp[2];
    temp[0] = '/';
    temp[1] = '\0';
    strcat(a, temp);
    strcat(a, b);
    return NULL;
}
int compare_strings(const void *a, const void *b)
{
    char *str_a = *(char **)a;
    char *str_b = *(char **)b;
    return strcmp1(str_a, str_b);
}
char *make_path_for_minus(char *a, char *b)
{
    char *c = (char *)malloc(sizeof(char) * directory_name_length);
    // c = '\0';
    strcpy(c, a);
    for (int i = 1; i < strlen(b); i++)
    {
        char temp[3];
        temp[0] = b[i];
        temp[1] = '\0';
        strcat(c, temp);
    }
    return c;
}
int check_valid_flag(char *instruction)
{
    if (instruction[0] == '-')
    {
        if (strlen(instruction) == 2)
        {
            return 1;
        }
    }
    return 0;
}
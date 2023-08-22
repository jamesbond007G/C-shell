#include "headers.h"
#define directory_name_length 5000
#define red_color "\x1b[31m"
#define blue_color "\x1b[34m"
#define green_color "\x1b[32m"
#define violet_color "\x1b[35m"

#define reset_color "\x1b[0m"
void run(char *instructions[2000], int instruction_count, char *directory, char *home_directory, char *code_store_directory, char *input, char *new_input_xxx);
void pastevents_delete(char *home_dir);
void pastevents_execute(int n, char *home_dir, char *directory, char *home_directory, char *code_store_directory, char *input, char *new_input_xxx);

char home_directory[directory_name_length];
char code_store_directory[directory_name_length];
char directory[256];

typedef struct process
{
    char *arr[100];
    int number;

} process;
void check_process_state(pid_t pid)
{
    char state;
    char stat_path[50];
    snprintf(stat_path, sizeof(stat_path), "/proc/%d/stat", pid);

    FILE *stat_file = fopen(stat_path, "r");
    if (stat_file == NULL)
    {
        perror("Error opening stat file");
        return;
    }

    // Read the state character from the stat file
    fscanf(stat_file, "%*d %*s %c", &state);

    fclose(stat_file);

    printf("Process with PID %d is in state: %c\n", pid, state);
}
void separate_foreground_background(process *background, process *foreground, char *input)
{
    char delimiter1[] = ";";
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
        char *token1 = strtok(instructions[i], delimiter2);
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
        int lol1;
        for (lol1 = 0; lol1 <= count - 2; lol1++)
        {
            background->arr[background->number] = (char *)malloc(sizeof(char) * 4000);

            strcpy((*background).arr[(*background).number++], final_strings[lol1]);
        }
        foreground->arr[background->number] = (char *)malloc(sizeof(char) * 4000);

        strcpy((*foreground).arr[(*background).number++], final_strings[lol1]);
    }
}
char *format_string(char *str)
{
    int len = strlen(str);
    char *final = (char *)malloc(sizeof(char) * (len + 10));
    int j = 0;
    for (int i = len - 1; i >= 1; i--)
    {
        if (str[i] == ' ' && str[i - 1] != ' ' && str[i + 1] != ' ')
        {
            final[j++] = str[i];
        }
        else if (str[i] != ' ')
        {
            final[j++] = str[i];
        }
    }
    if (str[0] != ' ')
    {
        final[j++] = str[0];
    }
    final[j] = '\0';
    printf("new_string = %s\n", final);
    for (int i = 0; i < strlen(final) / 2; i++)
    {
        char temp1;
        temp1 = final[i];
        final[i] = final[strlen(final) - 1 - i];
        final[strlen(final) - 1 - i] = temp1;
    }
    return final;
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

    // int lengtha = strlen(modifieda);
    // int lengthb = strlen(modifiedb);
    return strcmp2(modifieda, modifiedb);
}

int compare_strings(const void *a, const void *b)
{
    char *str_a = *(char **)a;
    char *str_b = *(char **)b;
    return strcmp1(str_a, str_b);
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
    for (i; i < lc; i++, j++)
    {
        c[j] = b[i + la];
    }
    c[j] = '\0';
    // printf("%s", c);
    return c;
}
char *current_directory()
{
    char *cur_directory = (char *)malloc(sizeof(char) * 5000);
    getcwd(cur_directory, 5000);
    return cur_directory;
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
        strcat(c, temp);
        strcat(c, instructions[k]);
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
    // printf("gopl test = %d    %s",k,final_permission);
    // return final_permission;
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
void printcolor(char *input, char *path_entered)
{
    struct stat info;
    char *full_path = (char *)malloc(sizeof(char) * 5000);
    char temp[2];
    temp[0] = '/';
    temp[1] = '\0';
    strcpy(full_path, path_entered);
    strcat(full_path, temp);
    strcat(full_path, input);
    stat(full_path, &info);
    __mode_t permissions = info.st_mode;

    if (checkdirectory(info))
    {
        printf(blue_color "\t%s\n" reset_color, input);
    }
    else if (checkexecutable(info))
    {
        printf(green_color "\t%s\n" reset_color, input);
    }
    else
    {
        printf("\t%s\n", input);
    }
}
void printdetails(char *input, char *path_entered)
{
    struct stat info;
    char *full_path = (char *)malloc(sizeof(char) * 5000);
    char temp[2];
    temp[0] = '/';
    temp[1] = '\0';
    strcpy(full_path, path_entered);
    strcat(full_path, temp);
    strcat(full_path, input);
    stat(full_path, &info);
    __mode_t permissions = info.st_mode;

    struct tm *tm_info = localtime(&info.st_mtime);
    int year = tm_info->tm_year + 1900; // Year since 1900
    // char *user = get_user_name(info);
    // char *group = get_group_name(info);
    print_permission(permissions);
    // free(permission);
    print_user(&info);
    print_group(&info);
    // printf("%s\t", user);
    // printf("%s\t", group);
    // free(user);
    // free(group);
    printf("\t%ld", info.st_size);
    printf("\t%04d-%02d-%02d %02d:%02d:%02d",
           year, tm_info->tm_mon + 1, tm_info->tm_mday,
           tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
    printcolor(input, path_entered);
}
void lshidden(char *path_entered)
{
    DIR *dir = opendir(path_entered);
    if (dir == NULL)
    {
        printf("incorrect path. no such directory exists");
        return;
    }
    struct dirent *en;
    struct dirent *entry;
    int count_no_of_files_and_folders = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        count_no_of_files_and_folders++;
    }
    char *all_files_of_directory[count_no_of_files_and_folders];
    for (int i = 0; i < count_no_of_files_and_folders; i++)
    {
        all_files_of_directory[i] = (char *)malloc(sizeof(char) * 300);
    }
    int i = 0;
    DIR *dir1 = opendir(path_entered);

    while ((entry = readdir(dir1)) != NULL)
    {
        all_files_of_directory[i++] = entry->d_name;
    }
    qsort(all_files_of_directory, count_no_of_files_and_folders, sizeof(char *), compare_strings);

    for (int i = 0; i < count_no_of_files_and_folders; i++)
    {
        printcolor(all_files_of_directory[i], path_entered);
    }
    closedir(dir);
}
void lslong(char *path_entered)
{
    DIR *dir = opendir(path_entered);
    if (dir == NULL)
    {
        printf("incorrect path. no such directory exists");
        return;
    }
    struct dirent *en;
    struct dirent *entry;
    int count_no_of_files_and_folders = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        count_no_of_files_and_folders++;
    }
    char *all_files_of_directory[count_no_of_files_and_folders];
    for (int i = 0; i < count_no_of_files_and_folders; i++)
    {
        all_files_of_directory[i] = (char *)malloc(sizeof(char) * 300);
    }
    int i = 0;
    DIR *dir1 = opendir(path_entered);

    while ((entry = readdir(dir1)) != NULL)
    {
        all_files_of_directory[i++] = entry->d_name;
    }
    qsort(all_files_of_directory, count_no_of_files_and_folders, sizeof(char *), compare_strings);

    for (int i = 0; i < count_no_of_files_and_folders; i++)
    {
        if (all_files_of_directory[i][0] != '.')
        {
            printdetails(all_files_of_directory[i], path_entered);
        }
    }
    closedir(dir);
}
void ls_hidden_long(char *path_entered)
{

    DIR *dir = opendir(path_entered);
    if (dir == NULL)
    {
        printf("incorrect path. no such directory exists");
        return;
    }
    struct dirent *en;
    struct dirent *entry;
    int count_no_of_files_and_folders = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        count_no_of_files_and_folders++;
    }
    char *all_files_of_directory[count_no_of_files_and_folders];
    for (int i = 0; i < count_no_of_files_and_folders; i++)
    {
        all_files_of_directory[i] = (char *)malloc(sizeof(char) * 300);
    }
    int i = 0;
    DIR *dir1 = opendir(path_entered);

    while ((entry = readdir(dir1)) != NULL)
    {
        all_files_of_directory[i++] = entry->d_name;
    }
    qsort(all_files_of_directory, count_no_of_files_and_folders, sizeof(char *), compare_strings);

    for (int i = 0; i < count_no_of_files_and_folders; i++)
    {
        printdetails(all_files_of_directory[i], path_entered);
    }
    closedir(dir);
}
void ls_normal(char *path_entered)
{
    DIR *dir = opendir(path_entered);
    if (dir == NULL)
    {
        printf("incorrect path. no such directory exists");
        return;
    }
    struct dirent *en;
    struct dirent *entry;
    int count_no_of_files_and_folders = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        count_no_of_files_and_folders++;
    }
    char *all_files_of_directory[count_no_of_files_and_folders];
    for (int i = 0; i < count_no_of_files_and_folders; i++)
    {
        all_files_of_directory[i] = (char *)malloc(sizeof(char) * 300);
    }
    DIR *dir1 = opendir(path_entered);
    int i = 0;
    while ((entry = readdir(dir1)) != NULL)
    {
        all_files_of_directory[i++] = entry->d_name;
    }
    qsort(all_files_of_directory, count_no_of_files_and_folders, sizeof(char *), compare_strings);

    for (int i = 0; i < count_no_of_files_and_folders; i++)
    {
        if (all_files_of_directory[i][0] != '.')
        {
            // printf("%s\n", all_files_of_directory[i]);
            printcolor(all_files_of_directory[i], path_entered);
        }
    }
    closedir(dir);
}
void ls(char *instructions[2000], int instruction_index, int instructions_count)
{
    int option;
    char *path_entered = string(4096);
    int hidden_flag = 0;
    int long_flag = 0;
    instruction_index = instruction_index + 1;
    while ((instruction_index != instructions_count) && instructions[instruction_index][0] == '-')
    {
        if (strcmp(instructions[instruction_index], "-l") == 0)
        {
            long_flag = 1;
        }
        else if (strcmp(instructions[instruction_index], "-a") == 0)
        {
            hidden_flag = 1;
        }
        else
        {
            hidden_flag = 1;
            long_flag = 1;
        }
        instruction_index++;
    }
    if (instructions_count == 1)
    {
        char curr_directory[256];
        getcwd(curr_directory, sizeof(curr_directory));
        strcpy(path_entered, curr_directory);
        ls_normal(path_entered);
    }
    else
    {
        if (instruction_index == instructions_count)
        {
            // if(instructions[i+1])
            char curr_directory[256];
            getcwd(curr_directory, sizeof(curr_directory));
            if (hidden_flag == 0 && long_flag == 0)
            {
                strcpy(path_entered, curr_directory);
                ls_normal(path_entered);
            }
            else if (hidden_flag == 1 && long_flag == 0)
            {
                strcpy(path_entered, curr_directory);
                lshidden(path_entered);
            }
            else if (hidden_flag == 0 && long_flag == 1)
            {
                strcpy(path_entered, curr_directory);
                lslong(path_entered);
            }
            else if (hidden_flag == 1 && long_flag == 1)
            {
                strcpy(path_entered, curr_directory);
                ls_hidden_long(path_entered);
            }
        }
        else
        {
            if (hidden_flag == 0 && long_flag == 0)
            {
                // if(instructions[i+1])
                // char curr_directory[256];
                // getcwd(curr_directory, sizeof(curr_directory));
                strcpy(path_entered, instructions[instruction_index]);
                ls_normal(path_entered);
            }
            else if (hidden_flag == 1 && long_flag == 0)
            {
                strcpy(path_entered, instructions[instruction_index]);
                lshidden(path_entered);
            }
            else if (hidden_flag == 0 && long_flag == 1)
            {
                strcpy(path_entered, instructions[instruction_index]);
                lslong(path_entered);
            }
            else if (hidden_flag == 1 && long_flag == 1)
            {
                strcpy(path_entered, instructions[instruction_index]);
                ls_hidden_long(path_entered);
            }
        }
    }
}

char colors[5][200];
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
int read_bytes_from_file(int i, char *home_dir)
{
    FILE *fptr1 = open_b_file("r", home_dir);
    int end = -((i - 1) * 5 + 1);
    int begin = -(i * 5 - 1);
    int x = begin - 1;
    // fseek(fptr1, x, SEEK_END);
    int zeroes = 3;
    int number = 0;
    while (x != (end))
    {
        fseek(fptr1, x, SEEK_END);
        int digit = fgetc(fptr1) - '0';
        // printf("%d ", digit);
        number += (digit * pow(10, zeroes));
        zeroes--;
        x++;
    }
    // printf("\n");
    // printf("number = %d\n", number);
    fclose(fptr1);
    return number;
}
int check_exists_command_file(char instruction[4096], char *home_dir)
{
    FILE *fptr = open_c_file("r", home_dir);
    int begin = -(read_bytes_from_file(1, home_dir));
    char buffer[4097];
    fseek(fptr, begin, SEEK_END);
    // printf("%d                   ", begin);
    size_t read = fread(buffer, -begin, -begin, fptr);
    // buffer[read] = '\0';
    fclose(fptr);
    // printf("this is the string i have got        %s\n", buffer);
    if (strcmp(buffer, instruction) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int get_end_for_i(int i, char *home_dir)
{
    // FILE *fptr1 = open_b_file("r", home_dir);
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
    // printf("end = %d\n", end);
    int begin = end - read_bytes_from_file(i, home_dir) - 1;
    // printf("begin = %d\n", begin);

    return begin;
}
char *get_instructions_for_i(int i, char *home_dir)
{
    FILE *fptr = open_c_file("r", home_dir);
    fseek(fptr, get_begin_for_i(i, home_dir), SEEK_END);
    // char buffer[409]
    // printf("begin of previous instructions =       %d\n", get_begin_for_i(i, home_dir));
    int size = read_bytes_from_file(i, home_dir);
    char *buffer = (char *)malloc(sizeof(char) * (4096));
    int k = fread(buffer, 1, size, fptr);
    buffer[k] = '\0';
    // printf("buffer - %s\n", buffer);
    fclose(fptr);
    return buffer;
}
void store(char instruction[4096], char *home_dir)
{

    FILE *fptr = open_c_file("a", home_dir);
    FILE *fptr1 = open_b_file("a", home_dir);
    // printf("this is the instructions i am storing      %s\n", instruction);
    // for(inti)
    // fprintf(fptr,instructions)
    // FILE *fptr_for_check
    char *new_string = (char *)malloc(sizeof(char) * 5000);
    strcpy(new_string, instruction);
    if (check_exists_command_file(new_string, home_dir) == 0)
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
void execute_system_call(char *instructions)
{
    int fork1 = fork();
    if (fork1 == 0)
    {
        char delimiter1[] = " \t";
        char *small_instructions[2000];
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
        // printf("\n");
        // printf("instruction executed %s\n", small_instructions[0]);
        small_instructions[count] = NULL;
        // for (int i = 0; i < count; i++)
        // {
        //     printf("%s ", small_instructions[i]);
        // }
        // printf("\n");
        execvp(small_instructions[0], small_instructions);
    }
    else if (fork1 > 0)
    {
        wait(NULL);
    }
    // return;
    // int k = main();
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
void seek_e(char *path_entered, char *to_find, int f_flag, int d_flag)
{
    DIR *dir = opendir(path_entered);
    if (dir == NULL)
    {
        printf("incorrect path. no such directory exists");
        return;
    }
    struct dirent *en;
    struct dirent *entry;
    int count_no_of_files_and_folders = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        count_no_of_files_and_folders++;
    }
    char *all_files_of_directory[count_no_of_files_and_folders];
    for (int i = 0; i < count_no_of_files_and_folders; i++)
    {
        all_files_of_directory[i] = (char *)malloc(sizeof(char) * 300);
    }
    DIR *dir1 = opendir(path_entered);
    int i = 0;
    while ((entry = readdir(dir1)) != NULL)
    {
        all_files_of_directory[i++] = entry->d_name;
        char temp[2];
        char *full_path = (char *)malloc(sizeof(char) * 5000);
        temp[0] = '/';
        temp[1] = '\0';
        struct stat info;
        strcpy(full_path, path_entered);
        strcat(full_path, temp);
        strcat(full_path, all_files_of_directory[i - 1]);
        stat(full_path, &info);
        if (strcmp(entry->d_name, to_find) == 0)
        {
            if (f_flag == 1 && checkdirectory(info) != 1)
            {
                if (check_readable(info) == 1)
                {
                    printf("%s\n", full_path);
                }
                else
                {
                    printf("Missing permissions for task!\n");
                }
            }
            else if (d_flag == 1 && checkdirectory(info) == 1)
            {
                if (checkexecutable(info) == 1)
                {
                    chdir(full_path);
                    printf("%s\n", full_path);
                }
                else
                {
                    printf("Missing permissions for task!\n");
                }
            }
        }
        if (checkdirectory(info) == 1)
        {
            if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".\0") != 0)
            {
                // printf("directory %s\n", full_path);
                seek_e(full_path, to_find, f_flag, d_flag);
            }
        }
    }
    closedir(dir1);

    closedir(dir);
}
void run_background(int backgroundid[500], int *number, char *instructions)
{
    // int number = 5;
    // int backgroundid[number];
    // FILE* fptr = fopen("/files")
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
        execvp(small_instructions[0], small_instructions);
    }
    else if (getid > 0)
    {
        printf("Processstarted with PID %d\n", getid);
        backgroundid[*number] = getid;
        (*number) = (*number) + 1;
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

void pastevents_delete(char *home_dir)
{
    FILE *fptr = open_c_file("w", home_dir);
    FILE *fptr1 = open_b_file("w", home_dir);
    fclose(fptr);
    fclose(fptr1);
}

void run(char *instructions[2000], int instruction_count, char *directory, char *home_directory, char *code_store_directory, char *input, char *new_input_xxx)
{
    for (int i = 0; i < instruction_count; i++)
    {
        char previous[1024];
        if (strcmp(instructions[i], "warp") == 0)
        {

            /* code */
            char *newinput_path;
            newinput_path = make_path_for_spaces(instructions, i, instruction_count);
            char previous[4096];
            int start = strlen(directory) - 1;
            char doubledot[4] = "..";
            char minus[4] = "-";
            char delimiter[] = " ";
            char *token4 = strtok(instructions[i + 1], delimiter);
            if (token4[0] == '.' && token4[1] == '.')
            {
                strcpy(previous, current_directory());
                // make_path_for_minus
                chdir(newinput_path);
                // printf("YES\n");
            }
            else if (token4[i] == '.' && token4[i] != '.')
            {
                strcpy(previous, current_directory());

                chdir(newinput_path);
            }
            else if (token4[0] == '-')
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
                printf("previous directory = %s\n", previous);
                if (instructions[i + 1][0] != '/')
                {
                    // printf("YES\n");

                    // printf("%s\n", directory);
                    filecat(previous, instructions[i + 1]);
                    printf("final directory = %s\n", previous);

                    if (chdir(previous) != 0)
                    {
                        printf("NO such directory.\n");
                    }
                }
            }

            // printf()
            i = i + 2;
            // free(newinput_path);
        }
        else if (strcmp(instructions[i], "peek") == 0)
        {
            ls(instructions, i, instruction_count);
        }
        else if (strcmp(instructions[i], "pastevents") == 0)
        {
            if (strcmp(instructions[i + 1], "purge") == 0)
            {
                int z = 1;
                pastevents_delete(code_store_directory);
            }
            else if (strcmp(instructions[i + 1], "execute") == 0)
            {
                int l = 1;
                pastevents_execute(instructions[i + 2][0] - '0', code_store_directory, directory, home_directory, code_store_directory, input, new_input_xxx);
            }
            else
            {
                FILE *fptr12 = open_b_file("r", code_store_directory);
                fseek(fptr12, 0, SEEK_END);
                int size_of_file = ftell(fptr12);
                printf("%d", size_of_file);
                for (int i = 1; i < size_of_file / 5; i++)
                {
                    printf("%d --- %s\n", i, get_instructions_for_i(i, code_store_directory));
                }
                fclose(fptr12);
            }
        }
        else
        {
            // printf("totoal - %s\n", new_input_xxx);
            execute_system_call(new_input_xxx);
        }
    }
}
void pastevents_execute(int n, char *home_dir, char *directory, char *home_directory, char *code_store_directory, char *input, char *new_input_xxx)
{
    char *instruction[2];
    // f)
    instruction[0] = (char*)malloc(sizeof(char)*500);
    instruction[0] = get_instructions_for_i(n, home_dir);
    run(instruction, 1, directory, home_dir, code_store_directory, input, new_input_xxx);
}
void print_background_status(int number, int backgroundid[500]);

void run_final(char* input, char* input_store, int number, int backgroundid[500])
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
    int fork123 = fork();
    if (fork123 == 0)
    {
        separate_foreground_background(&background, &foreground, input);
        for (int i = 0; i < background.number; i++)
        {
            // printf("gopal\n");
            if (foreground.arr[i])
            {
                int fork1 = fork();
                if (fork1 == 0)
                {
                    char *new_input_xxx = (char *)malloc(sizeof(char) * 5000);
                    strcpy(new_input_xxx, foreground.arr[i]);
                    // printf("foreground = %s\n", foreground.arr[i]);
                    char *instructions[2000];
                    char delimiter1[4] = " \t";
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
                    // printf("\n");
                    run(instructions, instruction_count, directory, home_directory, code_store_directory, input_store, new_input_xxx);
                }
                else if (fork1 > 0)
                {
                    wait(NULL);
                }
            }
            else if (background.arr[i])
            {
                printf("background = %s\n", background.arr[i]);
                // int fork213 = fork();

                run_background(backgroundid, &number, background.arr[i]);
            }
        }
    }
    else if (fork123 > 0)
    {
        // print_background_status(number, backgroundid);
    }
    store(input_store, code_store_directory);
    free(input_store);
}
void print_cur_directory()
{
    char directory[256];
    getcwd(directory, sizeof(directory));
    printf("curren directory - %s\n", directory);
}
void print_background_status(int number, int backgroundid[500])
{
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
int main()
{

    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    // char home_directory[directory_name_length];
    strcpy(home_directory, pw->pw_dir);
    // char code_store_directory[directory_name_length];
    getcwd(code_store_directory, sizeof(code_store_directory));
    strcpy(colors[0], "red");
    strcpy(colors[1], "blue");
    strcpy(colors[2], "green");
    strcpy(colors[2], "violet");
    int backgroundid[500];
    int number = 0;
    while (1)
    {
        // Print appropriate prompt with username, systemname and directory before accepting input
        // prompt();
        // 1st part
        struct passwd *pw = getpwuid(getuid());
        printf("<%s@", pw->pw_name);
        char hostname[256];
        gethostname(hostname, sizeof(hostname));
        printf("%s:", hostname);
        char directory[256];
        getcwd(directory, sizeof(directory));
        struct stat info;

        char *differnce = different(code_store_directory, directory);
        if (differnce)

        {
            printf("%s>", differnce);
        }
        else
        {
            printf("~>");
        }
        // free(differnce);
        // 2nd part

        // 3rd part
        char input[4096];
        char *input_store = (char *)malloc(sizeof(char) * 4096);

        fgets(input, 4096, stdin);
        run_final(input,input_store, number,backgroundid);
    }
    return 0;
}

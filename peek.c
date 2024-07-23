#include "headers.h"
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
        printf("incorrect path. no such directory exists\n");
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
        printf("incorrect path. no such directory exists\n");
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
        printf("incorrect path. no such directory exists\n");
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
        printf("incorrect path. no such directory exists\n");
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
    while ((instruction_index != instructions_count) && instructions[instruction_index][0] == '-'&&strlen(instructions[instruction_index])!=1)
    {
        if (strcmp(instructions[instruction_index], "-l") == 0 && check_valid_flag(instructions[instruction_index]))
        {
            long_flag = 1;
        }
        else if (strcmp(instructions[instruction_index], "-a") == 0 && check_valid_flag(instructions[instruction_index]))
        {
            hidden_flag = 1;
        }
        else if (strcmp(instructions[instruction_index], "-al") == 0 || strcmp(instructions[instruction_index], "-la") == 0)
        {
            hidden_flag = 1;
            long_flag = 1;
        }
        if (check_valid_flag(instructions[instruction_index]))
        {
            printf("Invalid flag %s\n", instructions[instruction_index]);
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
            // printf("YES\n");
        if (instructions[instruction_index][0] == '~')
        {
            instructions[instruction_index] = make_path_for_tilda(home_directory, instructions[instruction_index]);
            // strcpy(instructions[instruction_index], home_directory);
        }
        if (strcmp(instructions[instruction_index],"-\0")==0)
        {
            // printf("%s\n", );
            strcpy(instructions[instruction_index], previous);
        }
        if (instruction_index == instructions_count)
        {
            // if(instructions[i+1])
            char curr_directory[256];
            getcwd(curr_directory, sizeof(curr_directory));
            if (hidden_flag == 0 && long_flag == 0)
            {
                // printf("YES\n");
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
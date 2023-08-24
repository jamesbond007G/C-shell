#include "headers.h"
#include <sys/wait.h>
typedef struct process
{
    char *arr[300];
    int number;

} process;
char *filecat(char *a, char *b)
{
    char temp[2];
    temp[0] = '/';
    temp[1] = '\0';
    strcat(a, temp);
    strcat(a, b);
    return NULL;
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
            background->arr[background->number++] = (char *)malloc(sizeof(char) * 4000);
            strcpy(background->arr[background->number++], final_strings[lol1]);
        }
        foreground->arr[background->number++] = (char *)malloc(sizeof(char) * 4000);
        strcpy(foreground->arr[foreground->number++], final_strings[lol1]);
    }
    return;
}
// int checkdirectory(struct stat info)
// {
//     return S_ISDIR(info.st_mode);
// }
// void find_file(char *path_entered, char *to_find, char* home_directory)
// {
//     DIR *dir = opendir(path_entered);
//     // printf()
//     if (dir == NULL)
//     {
//         // free(path_entered);
//         // printf("incorrect path. no such directory exists");
//         return;
//     }
//     if (dir != NULL)
//     {

//         struct dirent *en;
//         struct dirent *entry;
//         int count_no_of_files_and_folders = 0;
//         while ((entry = readdir(dir)) != NULL)
//         {
//             //  all_files_of_directory[i] = (char *)malloc(sizeof(char) * 300);
//             count_no_of_files_and_folders++;
//         }
//         char *all_files_of_directory[count_no_of_files_and_folders];
//         for (int i = 0; i < count_no_of_files_and_folders; i++)
//         {
//             all_files_of_directory[i] = (char *)malloc(sizeof(char) * 300);
//         }
//         int i = 0;
//         DIR *dir1 = opendir(path_entered);
//         if (dir1 != NULL)
//         {
//             while ((entry = readdir(dir1)) != NULL)
//             {
//                 all_files_of_directory[i++] = entry->d_name;

//                 if (strcmp(all_files_of_directory[i - 1], to_find) == 0)
//                 {
//                     printf("%s\n", all_files_of_directory[i - 1]);
//                 }
//                 // printf("%s\n", all_files_of_directory[i - 1]);
//                 if (is_dirall_files_of_directory[i - 1])
//                     char *new_path = (char *)malloc(sizeof(char) * 4096);
//                 strcpy(new_path, path_entered);
//                 filecat(new_path, all_files_of_directory[i - 1]);
//                 find_file(new_path, to_find);
//                 // free(new_path);
//                 // free(new_path);
//             }
//         }
//         else
//         {
//             // free(path_entered);

//             return;
//         }
//         closedir(dir1);
//         closedir(dir);
//     }
//     // free(path_entered);
// }

// void seek(char *instructions[2000], int instruction_index, int instructions_count)
// {
//     int f_flag;
//     int d_flag;
//     int e_flag;
//     char curr_directory[256];
//     getcwd(curr_directory, sizeof(curr_directory));
//     while ((instruction_index != instructions_count) && instructions[instruction_index][0] == '-')
//     {
//         if (strcmp(instructions[instruction_index], "-d") == 0)
//         {
//             d_flag = 1;
//         }
//         else if (strcmp(instructions[instruction_index], "-f") == 0)
//         {
//             f_flag = 1;
//         }
//         else if (strcmp(instructions[instruction_index], "-e") == 0)
//         {
//             e_flag = 1;
//         }
//         instruction_index++;
//     }
//     if (f_flag == 1)
//     {
//         find_file();
//     }
//     else if (d_flag == 1)
//     {
//         find_directory();
//     }
//     else if (e_flag == 1)
//     {
//         do_e_flag();
//     }
// }
int checkdirectory(struct stat info)
{
    return S_ISDIR(info.st_mode);
}
void seek_d(char *path_entered, char *to_find)
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
            if (checkdirectory(info) == 1)
            {
                printf("%s\n", full_path);
            }
        }
        if (checkdirectory(info) == 1)
        {
            if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".\0") != 0)
            {
                // printf("directory %s\n", full_path);
                seek_d(full_path, to_find);
            }
        }
    }
    closedir(dir1);

    closedir(dir);
}
void seek_f(char *path_entered, char *to_find)
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
        int n_for_comparing = 0;
        for (int i = 0; i < strlen(entry->d_name); i++)
        {
            if (entry->d_name[i] == '.')
            {
                n_for_comparing = i;
                break;
            }
        }
        if (strncmp(entry->d_name, to_find,n_for_comparing) == 0)
        {
            if (checkdirectory(info) != 1)
            {
                printf("%s\n", full_path);
            }
        }
        if (checkdirectory(info) == 1)
        {
            if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".\0") != 0)
            {
                // printf("directory %s\n", full_path);
                seek_f(full_path, to_find);
            }
        }
    }
    closedir(dir1);

    closedir(dir);
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
void run_background()
{
    int number = 5;
    int backgroundid[number];
    for (int i = 0; i < number; i++)
    {
        int getid = fork();
        if (getid == 0)
        {
            int sleep_duration = i + 5;
            sleep(sleep_duration);
        }
        else if (getid > 0)
        {
            printf("process id = %d\n", getid);
            backgroundid[i] = getid;
        }
    }
    for (int i = 0; i < number; i++)
    {
        if (backgroundid[i] > 0)
        {
            pid_t result = waitpid(backgroundid[i], NULL, WNOHANG);
            if (result > 0)
            {
                printf("Background process %d with PID %d has finished.\n", i + 1, result);
                backgroundid[i] = 0;
            }
        }
    }
}
void execute_system_call(char *instructions)
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
        small_instructions[count++] = token;
        token = strtok(NULL, delimiter1);
    }
    small_instructions[count] = NULL;
    execvp(small_instructions[0], small_instructions);
    return;
}
int main()
{
    // process foreground;
    // process background;
    // foreground.number = 0;
    // background.number = 0;
    // for (int i = 0; i < 300; i++)
    // {
    //     foreground.arr[i] = (char *)malloc(sizeof(char) * 4000);
    //     background.arr[i] = (char *)malloc(sizeof(char) * 4000);
    // }
    // char input[4096];
    // fgets(input, 4096, stdin);
    // execute_system_call(input);
    char *path_entered = (char *)malloc(sizeof(char) * 4000);
    char *to_find = (char *)malloc(sizeof(char) * 4000);
    strcpy(path_entered, "/home/gopal/Desktop");
    strcpy(to_find, "gopal1.c");
    // find_file(path_entered, to_find);
    // seek(path_entered, to_find);
    seek_e(path_entered, to_find, 1, 0);
    // run_background();
    // separate_foreground_background(&background, &foreground, input);
    // for (int i = 0; i < background.number; i++)
    // {
    //     printf("background %d %s\n", i + 1, background.arr[i]);
    //     // printf("background %d %s\n",i+1, background->arr[i]);
    // }
    // for (int i = 0; i < foreground.number; i++)
    // {
    //     printf("foreground %d %s\n", i + 1, foreground.arr[i]);
    // }
    // for (int i = 0; i < 100; i++)
    // {
    //     free(foreground.arr[i]);
    //     free(background.arr[i]);
    // }
    // free(foreground)
    return 0;
}

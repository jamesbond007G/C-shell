#include "headers.h"
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
void seek_normal(char *path_entered, char *to_find, char *initial)
{
    DIR *dir = opendir(path_entered);
    if (dir == NULL)
    {
        // printf("incorrect path. no such directory exists");
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
        filecat(full_path, all_files_of_directory[i - 1]);
        // strcat(full_path, temp);
        // strcat(full_path, all_files_of_directory[i - 1]);
        stat(full_path, &info);
        int n_for_comparing = strlen(entry->d_name);
        for (int j = 0; j < strlen(entry->d_name); j++)
        {
            if (entry->d_name[j] == '.')
            {
                n_for_comparing = j;
                break;
            }
        }
        if (n_for_comparing > strlen(to_find) - 1 && strncmp(entry->d_name, to_find, n_for_comparing) == 0 && strcmp(entry->d_name, "..\0") != 0 && strcmp(entry->d_name, ".\0") != 0)
        {
            printf(green_color"%s\n"reset_color, differentc (initial,full_path));
        }
        if (checkdirectory(info) == 1)
        {
            if (strcmp(entry->d_name, "..\0") != 0 && strcmp(entry->d_name, ".\0") != 0)
            {
                // printf(blue_color"directory %s\n"reset_color, differentc (initial,full_path));
                seek_normal(full_path, to_find, initial);
            }
        }
    }
    closedir(dir1);

    closedir(dir);
}
void seek_d(char *path_entered, char *to_find, char *initial)
{
    DIR *dir = opendir(path_entered);
    if (dir == NULL)
    {
        // printf("incorrect path. no such directory exists");
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
                printf(blue_color"%s\n"reset_color, differentc (initial, full_path));
            }
        }
        if (checkdirectory(info) == 1)
        {
            if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".\0") != 0)
            {
                // printf(blue_color"directory %s\n"reset_color, differentc (initial, full_path));
                seek_d(full_path, to_find, initial);
            }
        }
    }
    closedir(dir1);

    closedir(dir);
}
void seek_f(char *path_entered, char *to_find, char *initial)
{
    DIR *dir = opendir(path_entered);
    // printf("%s\n", path_entered);
    if (dir == NULL)
    {
        // printf("incorrect path. no such directory exists\n");
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
        int n_for_comparing = strlen(entry->d_name);
        for (int i = 0; i < strlen(entry->d_name); i++)
        {
            if (entry->d_name[i] == '.')
            {
                n_for_comparing = i;
                break;
            }
        }
        // printf("%s\n", entry->d_name);
        if (n_for_comparing > strlen(to_find) - 1 && strncmp(entry->d_name, to_find, n_for_comparing) == 0)
        {
            if (checkdirectory(info) == 0)
            {
                printf(green_color"%s\n"reset_color, differentc (initial, full_path));
            }
        }
        if (checkdirectory(info) == 1)
        {
            if (strcmp(entry->d_name, "..\0") != 0 && strcmp(entry->d_name, ".\0") != 0)
            {
                // printf("directory %s\n", full_path);
                seek_f(full_path, to_find, initial);
            }
        }
    }
    closedir(dir1);

    closedir(dir);
}
void print_whole_file(char *full_path)
{
    char line[10000];
    FILE *fptr = fopen(full_path, "r");
    char c;
    while (fgets(line, sizeof(line), fptr) != NULL)
    {
        printf("%s", line);
    }
}
void seek_e(char *path_entered, char *to_find, int f_flag, int d_flag, char *initial)
{
    DIR *dir = opendir(path_entered);
    if (dir == NULL)
    {
        // printf("incorrect path. no such directory exists");
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
        if (strcmp(entry->d_name, "..\0") == 0)
        {
            continue;
        }
        else if (strcmp(entry->d_name, ".\0") == 0)
        {
            continue;
        }
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
        int n_for_comparing = strlen(entry->d_name); // Initialize with a default value
        for (int i = 0; i < strlen(entry->d_name); i++)
        {
            if (entry->d_name[i] == '.')
            {
                n_for_comparing = i;
                break;
            }
        }
        if (n_for_comparing >= strlen(to_find) - 1 && strncmp(entry->d_name, to_find, n_for_comparing) == 0)
        {
            if (f_flag == 1 && checkdirectory(info) != 1)
            {
                if (check_readable(info) == 1)
                {
                    // printf("gopal\n");
                    print_whole_file(full_path);

                    printf("\n");
                    printf(green_color"%s\n"reset_color, differentc (initial, full_path));
                }
                else
                {
                    printf("Missing permissions for task!\n");
                }
                return;
            }
            else if (d_flag == 1 && checkdirectory(info) == 1)
            {
                // printf("YES\n");
                if (checkexecutable(info) == 1)
                {
                    strcpy(previous, current_directory());
                    chdir(full_path);
                    printf(blue_color"%s\n"reset_color, differentc (initial, full_path));
                }
                else
                {
                    printf("Missing permissions for task!\n");
                }
                return;
            }
            
        }
        if (checkdirectory(info) == 1)
        {
            if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".\0") != 0)
            {
                // printf("directory %s\n", full_path);
                seek_e(full_path, to_find, f_flag, d_flag, initial);
            }
        }
    }
    closedir(dir1);

    closedir(dir);
}
void seek_e_normal(char *path_entered, char *to_find, int f_flag, int d_flag, char *initial)
{
    DIR *dir = opendir(path_entered);
    if (dir == NULL)
    {
        // printf("incorrect path. no such directory exists\n");
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
        if (strcmp(entry->d_name, "..\0") == 0)
        {
            continue;
        }
        else if (strcmp(entry->d_name, ".\0") == 0)
        {
            continue;
        }
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
        int n_for_comparing = strlen(entry->d_name); // Initialize with a default value
        for (int i = 0; i < strlen(entry->d_name); i++)
        {
            if (entry->d_name[i] == '.')
            {
                n_for_comparing = i;
                break;
            }
        }
        if (n_for_comparing >= strlen(to_find) - 1 && strncmp(entry->d_name, to_find, n_for_comparing) == 0)
        {

            if (checkexecutable(info) == 1)
            {

                printf(green_color"%s\n"reset_color, differentc (initial, full_path));
                chdir(full_path);
            }
            else
            {
                printf("Missing permissions for task!\n");
            }
            return;
            if (d_flag == 1)
                if (check_readable(info) == 1)
                {
                    // printf("gopal\n");
                    print_whole_file(full_path);
                    printf("\n");
                    printf(blue_color"%s\n"reset_color, differentc (initial, full_path));
                }
                else
                {
                    printf("Missing permissions for task!\n");
                }
            return;
        }
        if (checkdirectory(info) == 1)
        {
            if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".\0") != 0)
            {
                // printf("directory %s\n", full_path);
                seek_e_normal(full_path, to_find, f_flag, d_flag, initial);
            }
        }
    }
    closedir(dir1);

    closedir(dir);
}

int seek_e_count_f(char *path_entered, char *to_find, int f_flag, int d_flag)
{
    DIR *dir = opendir(path_entered);
    if (dir == NULL)
    {
        // printf("incorrect path. no such directory exists");
        return 0;
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
    int sum_store = 0;
    while ((entry = readdir(dir1)) != NULL)
    {
        if (strcmp(entry->d_name, "..\0") == 0)
        {
            continue;
        }
        else if (strcmp(entry->d_name, ".\0") == 0)
        {
            continue;
        }
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
        int n_for_comparing = strlen(entry->d_name); // Initialize with a default value
        for (int i = 0; i < strlen(entry->d_name); i++)
        {
            if (entry->d_name[i] == '.')
            {
                n_for_comparing = i;
                break;
            }
        }
        if (n_for_comparing >= strlen(to_find) - 1 && strncmp(entry->d_name, to_find, n_for_comparing) == 0)
        {
            if (f_flag == 1 && checkdirectory(info) != 1)
            {
                sum_store++;
            }
            else if (d_flag == 1 && checkdirectory(info) == 1)
            {
                int la = 1;
                //    sum_store++
            }
        }
        if (checkdirectory(info) == 1)
        {
            if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".\0") != 0)
            {
                // printf("directory %s\n", full_path);
                sum_store += seek_e_count_f(full_path, to_find, f_flag, d_flag);
            }
        }
    }
    closedir(dir1);

    closedir(dir);
    return sum_store;
}

int seek_e_count_d(char *path_entered, char *to_find, int f_flag, int d_flag)
{
    DIR *dir = opendir(path_entered);
    if (dir == NULL)
    {
        printf("incorrect path. no such directory exists");
        return 0;
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
    int sum_store = 0;
    while ((entry = readdir(dir1)) != NULL)
    {
        if (strcmp(entry->d_name, "..\0") == 0)
        {
            continue;
        }
        else if (strcmp(entry->d_name, ".\0") == 0)
        {
            continue;
        }
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
        int n_for_comparing = strlen(entry->d_name); // Initialize with a default value
        for (int i = 0; i < strlen(entry->d_name); i++)
        {
            if (entry->d_name[i] == '.')
            {
                n_for_comparing = i;
                break;
            }
        }
        if (n_for_comparing >= strlen(to_find) - 1 && strncmp(entry->d_name, to_find, n_for_comparing) == 0)
        {
            if (f_flag == 1 && checkdirectory(info) != 1)
            {
                int la = 1;
            }
            else if (d_flag == 1 && checkdirectory(info) == 1)
            {
                // printf("gopal\n");
                sum_store++;
                //    sum_store++
            }
        }
        if (checkdirectory(info) == 1)
        {
            if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".\0") != 0)
            {
                // printf("directory %s\n", full_path);
                sum_store += seek_e_count_d(full_path, to_find, f_flag, d_flag);
            }
        }
    }
    closedir(dir1);

    closedir(dir);
    return sum_store;
}
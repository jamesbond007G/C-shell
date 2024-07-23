#include "headers.h"
int number;
int backgroundid[500];
char home_directory[directory_name_length];
char code_store_directory[directory_name_length];
char directory[256];
char previous[4096];
int main()
{
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    strcpy(home_directory, pw->pw_dir);
    getcwd(code_store_directory, sizeof(code_store_directory));

    number = 0;
    while (1)
    {
        // Print appropriate prompt with username, systemname and directory before accepting input
        // prompt();
        char directory[256];
        char hostname[256];
        // 1st part
        struct stat info;
        int fg = fork();
        char *input_store = (char *)malloc(sizeof(char) * 4096);
        char input[4096];
        if (fg == 0)
        {
            printf("<%s@", pw->pw_name);
            gethostname(hostname, sizeof(hostname));
            printf("%s:", hostname);
            // char hostname[256];
            gethostname(hostname, sizeof(hostname));
            // printf("%s:", hostname);
            getcwd(directory, sizeof(directory));
            // printf("gopal = %s\ngoapl  =%s\n", code_store_directory, directory);
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

            fgets(input, 4096, stdin);
        }
        else if (fg > 0)
        {
            int status;
            waitpid(fg, &status, 0);
        }

        run_final(input, input_store, &number, backgroundid);
        // printf("%d\n",number);
        // sleep(3);

        for (int i = 0; i < number; i++)
        {
            if (backgroundid[i] > 0)
            {

                char path_of_a_process_file[256];

                strcpy(path_of_a_process_file, "/proc");
                char *try = string(200);
                int y = snprintf(try, sizeof(try), "%d", backgroundid[i]);
                filecat(path_of_a_process_file, try);
                filecat(path_of_a_process_file, "status");

                FILE *fptr1 = fopen(path_of_a_process_file, "r");
                if (fptr1 == NULL && backgroundid[i] > 0)
                {

                    printf("Process with PID %d is completed.\n", backgroundid[i]);
                    backgroundid[i] = 0;
                    continue;
                }
                if (fptr1)
                {
                    char information_of_process[128];
                    while (fgets(information_of_process, sizeof(information_of_process), fptr1))
                    {
                        if (strncmp(information_of_process, "State:\t", 6) == 0)
                        {
                            if (strstr(information_of_process, "Z"))
                            {
                                printf("Process with PID %d is completed.\n", backgroundid[i]);
                                backgroundid[i] = 0;
                            }

                            break;
                        }
                    }
                }

                // printf("YES\n\n");
                if (fptr1)
                {
                    fclose(fptr1);
                }
            }
        }
    }
    return 0;
}

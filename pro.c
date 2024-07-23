#include "headers.h"

void proclore(int pid)
{
    char *path = string(300);
    char *nnn = string(100);
    snprintf(nnn, sizeof(nnn), "%d", pid);
    strcpy(path, "/proc");
    filecat(path, nnn);
    filecat(path, "stat");
    int pid1, gid;
    pid1 = pid; 
    // FILE *fptr1111111 = fopen(path, "r");
    char* status= string(4);
    // if (fptr1111111)
    // {
        // fscanf(fptr1111111, "%d %*s %c %d", &pid1, &status, &gid);
        // fclose(fptr1111111);
    // }
    // else
    // {
        // printf("invalid process\n");
        // return;
    // }
    printf("pid:\t%d\n", pid1);
    printf("Process Status:\t");

    char *path2 = string(300);
    strcpy(path2, "/proc");
    filecat(path2, nnn);
    filecat(path2, "/status");
    FILE *fpt11111 = fopen(path2, "r");
    char line1[16];
    char line2[16];

    while (fgets(line2, 15, fpt11111))
    {
        if (strncmp(line2, "State:", 6) == 0)
        {
            sscanf(line2, "State:\t%s",status);
            break;
        }
    }
    while (fgets(line1, 15, fpt11111))
    {
        if (strncmp(line1, "Tgid:", 5) == 0)
        {
            sscanf(line1, "Tgid:\t%d", &gid);
            break;
        }
    }
    if (pid1 == gid)
    {
        printf("%s", status);
        printf("+\n");
    }
    else
    {
        printf("%s\n", status);

    }
    printf("Process Group = %d\n", gid);

    if (fpt11111)
    {
        char line[500];
        while (fgets(line, 20, fpt11111))
        {
            if (strncmp(line, "VmSize:", 7) == 0)
            {
                int vsize;
                sscanf(line, "VmSize:\t%d", &vsize);
                printf("Virtual Memory: %d\n", vsize);
                break;
            }
        }
        fclose(fpt11111);
    }

    char *path3 = string(500);
    strcpy(path3, "/proc");
    filecat(path3, nnn);
    filecat(path3, "exe");
    char *final_oath = string(500);
    ssize_t len = readlink(path3, final_oath, sizeof(final_oath) - 1);
    if (len != -1)
    {
        final_oath[len] = '\0';
        printf("Executable Path: %s\n", final_oath);
    }
}


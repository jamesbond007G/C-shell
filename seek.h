#ifndef SEEK_H_
#define SEEK_H_
int read_bytes_from_file(int i, char *home_dir);
void seek_normal(char *path_entered, char *to_find, char* initial);
void seek_d(char *path_entered, char *to_find, char* initial);
void seek_f(char *path_entered, char *to_find, char* initial);
void print_whole_file(char *full_path);
void seek_e(char *path_entered, char *to_find, int f_flag, int d_flag, char * initial);
int seek_e_count_d(char *path_entered, char *to_find, int f_flag, int d_flag);
int seek_e_count_f(char *path_entered, char *to_find, int f_flag, int d_flag);
void seek_e_normal(char *path_entered, char *to_find, int f_flag, int d_flag, char *initial);

#endif 
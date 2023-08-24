// #ifndef __PROMPT_H
// #define __PROMPT_H

// void prompt();
// void print_whole_file(char *full_path);
// int check_valid_flag(char *instruction);
// int check_past_events_in_input(char *input);
// char home_directory[directory_name_length];
// char code_store_directory[directory_name_length];
// char directory[256];
// typedef struct process
// {
//     char *arr[100];
//     int number;

// } process;
// void check_process_state(pid_t pid);
// void separate_foreground_background(process *background, process *foreground, char *input);
// char *format_string(char *str);
// char *string(int length);
// char *changed_file_name_for_comparison(char *a);
// int strcmp2(char *a, char *b);
// int strcmp1(char *a, char *b);
// int compare_strings(const void *a, const void *b);
// char *different(char *a, char *b);
// char *current_directory()
// char *make_path_for_minus(char *a, char *b);
// char *make_path_for_tilda(char *a, char *b);
// char *make_path_for_spaces(char *instructions[2000], int i, int instruction_count);
// void print_user(struct stat *info);
// void print_group(struct stat *info)
// void print_permission(__mode_t k);
// int checkdirectory(struct stat info);
// int checkexecutable(struct stat info);
// void printcolor(char *input, char *path_entered);
// void printdetails(char *input, char *path_entered);
// void lshidden(char *path_entered);
// void ls(char *instructions[2000], int instruction_index, int instructions_count);
// FILE *open_c_file(const char *mode, char *home_directory_start_from_where);
// FILE *open_b_file(const char *mode, char *home_directory_start_from_where)
// int read_bytes_from_file(int i, char *home_dir)
// void seek_normal(char *path_entered, char *to_find)
// void seek_d(char *path_entered, char *to_find)
// void seek_f(char *path_entered, char *to_find)
// int check_exists_command_file(char instruction[4096], char *home_dir)
// int get_end_for_i(int i, char *home_dir);
// int get_begin_for_i(int i, char *home_dir);
// char *get_instructions_for_i(int i, char *home_dir);
// void store(char instruction[4096], char *home_dir);
// void execute_system_call(char *instructions);
// int check_readable(struct stat info);
// void seek_e(char *path_entered, char *to_find, int f_flag, int d_flag);
// void run_background(int backgroundid[500], int *number, char *instructions);
// char *filecat(char *a, char *b);
// void pastevents_delete(char *home_dir);
// // void pastevents_delete(char *home_dir)
// void warp(char *instructions[2000], int i, int instruction_count);
// int min(int a, int b);
// char previous[4096];
// void run(char *instructions[2000], int instruction_count, char *directory, char *home_directory, char *code_store_directory, char *input, char *new_input_xxx);
// void pastevents_execute(int n, char *home_dir, char *directory, char *home_directory, char *code_store_directory, char *input, char *new_input_xxx);
// // void print_background_status(int number, int backgroundid[500]);
// void run_final(char *input, char *input_store, int *number, int backgroundid[500]);
// void print_cur_directory();


// #endif
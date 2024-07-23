#ifndef PASTEVENTS_H_
#define PASTEVENTS_H_
#define directory_name_length 5000
extern int number;
extern int backgroundid[500];
extern char home_directory[directory_name_length];
extern char code_store_directory[directory_name_length];
extern char directory[256];
extern char previous[4096];
int get_end_for_i(int i, char *home_dir);
int get_begin_for_i(int i, char *home_dir);
char *get_instructions_for_i(int i, char *home_dir);
void pastevents_delete(char *home_dir);
void pastevents_execute(int n, char *home_dir, char *directory, char *home_directory, char *code_store_directory, char *input, char *new_input_xxx);
int check_past_events_in_input(char *input);

#endif
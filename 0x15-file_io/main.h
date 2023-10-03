#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
void print_error(const char *message);

int main(int argc, char *argv[]);
int open_source_file(const char *source_filename);
int open_destination_file(const char *destination_filename);
int copy_file_contents(int source_fd, int destination_fd);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */

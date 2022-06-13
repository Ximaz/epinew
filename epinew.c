#include <time.h>
#include <stdio.h>
#include <epinew.h>
#include <stdlib.h>
#include <string.h>

static char const *kinds[] = {
    "The program",
    "The function",
    "The header",
    "The implementation of"
};

static char *make_epitech_header(char const *filename, kind_t kind)
{
    time_t time_ptr = time(NULL);
    char const *str_kind = kinds[kind];
    struct tm* current_time = localtime(&time_ptr);
    char const format[] = "/*\n** EPITECH PROJECT, %d\n** %s\n** File description:\n** %s %s\n*/\n";
    unsigned int const header_len = strlen(format) + 4 + 2 * strlen(filename) + strlen(str_kind);
    char *header = (char *)calloc(header_len + 1, sizeof(char));

    if (header) {
        sprintf(header, format, current_time->tm_year + 1900, filename, str_kind, filename);
        header[header_len] = 0;
    }
    return header;
}

static int make_file(char const *filename, char *content)
{
    FILE *fp = fopen(filename, "w");

    if (!fp) {
        free(content);
        return 1;
    }
    fwrite(content, strlen(content), 1, fp);
    free(content);
    fclose(fp);
    return 0;
}

static int make_program(char const *filename)
{
    char *buffer;
    char *header = make_epitech_header(filename, PROGRAM);
    char const content[] = "int main(int argc, char **argv)\n{\n    return 0;\n}\n";

    if (!header)
        return 1;
    buffer = (char *) calloc(strlen(header) + strlen(content) + 1, sizeof(char));
    if (!buffer) {
        free(header);
        return 1;
    }
    buffer = strcat(buffer, header);
    buffer = strcat(buffer, content);
    free(header);
    return make_file(filename, buffer);
}

static int make_source(char const *filename)
{
    int err = 0;
    char *header = make_epitech_header(filename, SOURCE);

    if (!header)
        return 1;
    err = make_file(filename, header);
    return err;
}

static int make_header(char const *filename)
{
    char *buffer;
    char *header = make_epitech_header(filename, HEADER);
    char const content[] = "#ifndef _MY_HEADER_NAME_H_\n#define _MY_HEADER_NAME_H_\n#endif\n";

    if (!header)
        return 1;
    buffer = (char *) calloc(strlen(header) + strlen(content) + 1, sizeof(char));
    if (!buffer) {
        free(header);
        return 1;
    }
    buffer = strcat(buffer, header);
    buffer = strcat(buffer, content);
    free(header);
    return make_file(filename, buffer);
}

int handle_flag(char const *flag, char const *filename)
{
    if (strcmp(flag, "-P") == 0)
        return make_program(filename);
    if (strcmp(flag, "-S") == 0)
        return make_source(filename);
    if (strcmp(flag, "-H") == 0)
        return make_header(filename);
    return -1;
}

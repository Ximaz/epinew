#ifndef _NEW_H_
#define _NEW_H_

typedef struct s_flag
{
    char const *flag;
    char const *desc;
} flag_t;

typedef enum kind_e
{
    PROGRAM = 0,
    SOURCE,
    HEADER
} kind_t;

static unsigned int const supported_flags = 4;
static flag_t const flags[] = {
    { "-h", "Display the help section" },
    { "-P", "Kind : program" },
    { "-S", "Kind : sources" },
    { "-H", "Kind : header" }
};

int handle_flag(char const *flag, char const *filename);

#endif

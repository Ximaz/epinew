#include <stdio.h>
#include <string.h>
#include <epinew.h>

void show_flags(void)
{
    unsigned int i = 0;
    flag_t flag = { 0, 0 };

    if (supported_flags < 1)
        return;
    printf("Flags :\n");
    for (; i < supported_flags; i++) {
        flag = flags[i];
        printf("        %s : %s.\n", flag.flag, flag.desc);
    }
}

void usage(char const *bin_name)
{
    printf("Usage : %s [KIND] filename\n", bin_name);
    show_flags();
}

int main(int argc, char const **argv)
{
    if (argc < 2) {
        usage(argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "-h") == 0) {
        usage(argv[0]);
        return 0;
    }
    if (argc < 3) {
        usage(argv[0]);
        return 1;
    }
    return handle_flag(argv[1], argv[2]);
}

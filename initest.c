#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "iniman.h"

#define VALUE_LEN 512
#define MODE_GET 0
#define MODE_WRITE 1
#define MODE_DEL_ENT 2
#define MODE_DEL_SEC 3

static char buffer[VALUE_LEN];

int main(int argc, char **argv)
{
    char *filename, *section, *entry, *value = buffer;
    int mode;

    if (argc < 2)
    {
        return -1;
    }

    if (!strcmp(argv[1], "-de"))
    {
        if (argc != 5) return -1;
        mode = MODE_DEL_ENT;
        entry = argv[4];
        section = argv[3];
        filename = argv[2];
    }

    if (!strcmp(argv[1], "-ds"))
    {
        if (argc != 4) return -1;
        mode = MODE_DEL_SEC;
        section = argv[3];
        filename = argv[2];
    }

    if (!strcmp(argv[1], "-we"))
    {  
        if (argc != 6) return -1;
        mode = MODE_WRITE;
        value = argv[5];
        entry = argv[4];
        section = argv[3];
        filename = argv[2];
    }

    if (!strcmp(argv[1], "-ge"))
    {  
        if (argc != 5) return -1;
        mode = MODE_GET;
        entry = argv[4];
        section = argv[3];
        filename = argv[2];
    }

    InitPrivateProfile(NULL);

    switch (mode)
    {
        case MODE_WRITE:
            WritePrivateProfileString(section, entry, value, filename);
            FlushAllPrivateProfile();
            break;

        case MODE_GET:
            GetPrivateProfileString(section, entry, "", value, VALUE_LEN, filename);
            printf("%s\n", value);
            break;
        
        case MODE_DEL_ENT:
            DeletePrivateProfileEntry(section, entry, filename);
            FlushAllPrivateProfile();
            break;

        case MODE_DEL_SEC:
            DeletePrivateProfileSection(section, filename);
            FlushAllPrivateProfile();
            break;

        default:
            break;
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc != 2) {
        fprintf(stderr, "usage: enqueue <makor>\n");
        return 1;
    }
    
    FILE *f = fopen("queue", "a");
    fwrite(argv[1], 1, strlen(argv[1]), f);
    fwrite("\n", 1, 1, f);
    fclose(f);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("queue", "r");
    if (!f)
        goto empty;

    int csize = 10;
    char *fcontents, *p;

    fcontents = p = malloc(csize);
    
    while(fread(p, 1, csize, f) != 0) {
        fcontents = realloc(fcontents, csize*2);
        p = fcontents + csize;
        csize *= 2;
    }
    if (ferror(f)) {
        fclose(f);
        return 1;
    }
    fclose(f);

    p = strchr(fcontents, '\n');
    if (!p) 
        goto empty;
    *p = '\0';

    f = fopen("queue", "w");
    fwrite(p+1, 1, strlen(p+1), f);
    fclose(f);

    printf("dequeue: %s\n", fcontents);

    return 0;

empty:
    printf("dequeue: queue empty\n");
    return 0;
}
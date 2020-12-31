#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "file not exists %s", argv[1]);
    }

    for (int i = 1; i < argc; i++) {
        FILE* f;
        int c;
        f = fopen(argv[i], "r");
        if (!f) {
            perror(argv[i]);
            exit(1);
        }
        while ((c = fgetc(f)) != EOF) {
            if (c == '\t') {
                if(fputs("\\t", stdout) == EOF) exit(1);
                break;
            }
            else if (c == '\n') {
                if(fputs("$\n", stdout) == EOF) exit(1);
                break;
            }
            else {
                if (putchar(c) < 0) exit(1);
                break;
            
        }
        fclose(f);
    }
    exit(0);
}

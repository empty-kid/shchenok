#include <stdio.h>

int main(void) {
    FILE *a = fopen("input.txt", "r");
    FILE *b = fopen("output.txt", "w");
    int w, s, p;
    char str[20002];
    fscanf(a, "%100s", &str);
    printf("%s", str);
    while(fgets(str, sizeof(str), a)) {
        printf("%s\n", str);
    }
    fclose(a);
    fclose(b);
    return 0;
}

#include <stdio.h>
#include <string.h>

void strings(FILE *a, int ind) {
    char s[102];
    if (fgets(s, 102, a)) {
        if (s[strlen(s) - 1] == '\n') {
            s[strlen(s) - 1] = '\0';
        }
        if (ind % 2 == 0) {
            printf("%s\n", s);
            strings(a, ind + 1);
        }
        else {
            strings(a, ind + 1);
            printf("%s\n", s);
        }
    }
}

int main(void) {
    FILE *a = fopen("input.txt", "r");
    strings(a, 1);
    // char str[100][102];
    // int ind = 0;
    // while (fgets(str[ind], 102, a)) {
    //     if (str[ind][strlen(str[ind]) - 1] == '\n') {
    //         str[ind][strlen(str[ind]) - 1] = '\0';
    //     }
    //     if ((ind + 1) % 2 == 0) {
    //         printf("%s\n", str[ind]);
    //     }
    //     ind++;
    // }
    // for (int i = ind - 1; i >= 0; i-=2) {
    //     printf("%s\n", str[i]);
    // }
    // fclose(a);
    return 0;
}

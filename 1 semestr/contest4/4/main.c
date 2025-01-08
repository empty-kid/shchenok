#include <stdio.h>
#include <string.h>

int main(void) {
    char s[256];
    scanf("%255s", s);

    for (int i = 0; i < strlen(s); i++) {
        int count1 = 0;
        int count2 = 0;

        for (int j = 0; j < strlen(s); j++) {
            if (j > i) {
                if (s[j] == 'A' && j % 2 == 0) {
                    count1++;
                }else if(s[j] == 'A' && j % 2 != 0) {
                    count2++;
                }
            }else if(j < i) {
                if (s[j] == 'A' && (j+1) % 2 == 0) {
                    count1++;
                }else if(s[j] == 'A' && (j+1) % 2 != 0) {
                    count2++;
                }
            }
        }
        if (count1 == count2) {
            printf("%d ", i+1);
        }
    }

    return 0;
}

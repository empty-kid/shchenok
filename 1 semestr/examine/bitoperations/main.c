#include <stdio.h>

int main(void) {
    int n1 = 0x770a;
    int n2 = 0x1fea;
    int n3 = 0x0ac0;
    int n4 = 0xddd5;
    unsigned x, y, z;
    for (int i = 0; i < 16; i++) {
        unsigned b_n1 = (n1 >> i) & 1;
        unsigned b_n2 = (n1 >> i) & 1;
        unsigned b_n3 = (n1 >> i) & 1;
        unsigned b_n4 = (n1 >> i) & 1;
        for (unsigned b_x = 0; b_x < 2; b_x++) {
            for (unsigned b_y = 0; b_y < 2; b_y++) {
                for (unsigned b_z = 0; b_z < 2; b_z++) {
                    if ((b_x ^ b_z) == b_n1 && ) {

                    }

                }
            }
        }
    }
    return 0;
}
#include <stdio.h>

typedef struct {
    int size;
    int count;
} Block;

int main() {
    int M;
    scanf("%d", &M);

    Block blocks[19]; // M < 19
    int total_blocks = 0;

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &blocks[i].size, &blocks[i].count);
        total_blocks += blocks[i].count;
    }

    // �������� � �������� �����, ������� ������� �� 1 �����
    int current_level_size = 1; // ���������� ������ � ������� �����
    int current_level_length = 0; // ����� �������� �����

    // ���� ���������� ����� ��� ������� ������
    for (int level = 0; level < total_blocks; level++) {
        // ����� ����� ����� ��� �������� ������
        int found = 0;

        for (int i = M - 1; i >= 0; i--) {
            if (blocks[i].count > 0) {
                // ��������� ����� �������� ������
                int length = blocks[i].size * current_level_size;

                // ���������, ���� ��� ������ ������� ��� �� ������ ����������� ������
                if (level == 0 || length < current_level_length) {
                    // ���������� ���� ����
                    blocks[i].count--;
                    current_level_length = length;
                    found = 1;
                    break;
                }
            }
        }

        if (!found) {
            printf("No");
            return 0;
        }

        // ��������� � ���������� ������, �������� ���������� ������ �� 1
        current_level_size++;
    }

    printf("Yes");
    return 0;
}

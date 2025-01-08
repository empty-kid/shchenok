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

    // Начинаем с верхнего яруса, который состоит из 1 блока
    int current_level_size = 1; // Количество блоков в текущем ярусе
    int current_level_length = 0; // Длина текущего яруса

    // Ищем подходящие блоки для каждого уровня
    for (int level = 0; level < total_blocks; level++) {
        // Нужно найти блоки для текущего уровня
        int found = 0;

        for (int i = M - 1; i >= 0; i--) {
            if (blocks[i].count > 0) {
                // Вычисляем длину текущего уровня
                int length = blocks[i].size * current_level_size;

                // Проверяем, если это первый уровень или он меньше предыдущего уровня
                if (level == 0 || length < current_level_length) {
                    // Используем один блок
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

        // Переходим к следующему уровню, уменьшая количество блоков на 1
        current_level_size++;
    }

    printf("Yes");
    return 0;
}

#include <iostream>
#include <vector>

// Функция для вывода горизонтального среза
void printSlice(const std::vector<std::vector<std::vector<int>>>& world, int level) {
    // Проверяем, чтобы уровень был в пределах от 0 до 9
    if (level < 0 || level > 9) {
        std::cerr << "Invalid level. Level must be between 0 and 9." << std::endl;
        return;
    }

    // Выводим срез
    for (int i = 0; i < world.size(); ++i) {
        for (int j = 0; j < world[i].size(); ++j) {
            // Если на этом уровне есть блок, выводим 1, иначе 0
            if (level < world[i][j].size() && world[i][j][level]) {
                std::cout << "1 ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    // Размеры ландшафта
    const int rows = 5;
    const int cols = 5;
    const int maxBlocks = 10;

    // Ввод высот блоков
    std::vector<std::vector<std::vector<int>>> world(rows, std::vector<std::vector<int>>(cols));

    std::cout << "Enter matrix of heights (max height = 10):" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int height;
            std::cin >> height;

            // Заполняем трёхмерный массив
            for (int k = 0; k < height; ++k) {
                world[i][j].push_back(1); // 1 означает присутствие блока на этом уровне
            }
        }
    }

    // Ввод уровня среза
    int level;
    std::cout << "Enter slice level (0-9): ";
    std::cin >> level;

    // Выводим срез
    std::cout << "Slice at level " << level << ":" << std::endl;
    printSlice(world, level);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solveTask1() {
    // Пример матрицы из условия задачи
    int N = 3;
    int M = 4;
    vector<vector<int>> grid = {
        {2, -3, 2, 3},
        {10, 2, 2, 2},
        {-3, 20, 2, 2}
    };

    // dp[i][j] будет хранить максимальную сумму баллов до этой ячейки
    vector<vector<int>> dp(N, vector<int>(M, 0));
    
    // Базовый случай: старт
    dp[0][0] = grid[0][0];

    // Заполнение первой строки (можно прийти только слева)
    for (int j = 1; j < M; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Заполнение первого столбца (можно прийти только сверху)
    for (int i = 1; i < N; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Заполнение остальной части таблицы
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    // Восстановление пути с конца
    vector<pair<int, int>> path;
    int curr_i = N - 1;
    int curr_j = M - 1;

    while (curr_i > 0 || curr_j > 0) {
        path.push_back({curr_i, curr_j});
        if (curr_i == 0) {
            curr_j--;
        } else if (curr_j == 0) {
            curr_i--;
        } else {
            // Выбираем, откуда пришли (где было больше баллов)
            if (dp[curr_i - 1][curr_j] > dp[curr_i][curr_j - 1]) {
                curr_i--;
            } else {
                curr_j--;
            }
        }
    }
    path.push_back({0, 0}); // Добавляем стартовую точку

    // Переворачиваем путь, чтобы он шел от старта к финишу
    reverse(path.begin(), path.end());

    // Вывод результата
    cout << "Маршрут в координатах ячеек:\n";
    for (const auto& p : path) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    solveTask1();
    return 0;
}

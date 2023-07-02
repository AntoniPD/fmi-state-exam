//
// Created by Antoni Dobrenov on 30.06.23.
//

#include <iostream>

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

int find(int field[MAX_ROWS][MAX_COLS], int m, int n, int row, int col, bool visited[MAX_ROWS][MAX_COLS], int &areaSize) {
    if (row >= m || col >= n || row < 0 || col < 0 || visited[row][col] || field[row][col] == 0) {
        return 0;
    }

    visited[row][col] = true;
    areaSize++;

    int area = field[row][col];
    area += find(field, m, n, row + 1, col, visited, areaSize);
    area += find(field, m, n, row - 1, col, visited, areaSize);
    area += find(field, m, n, row, col + 1, visited, areaSize);
    area += find(field, m, n, row, col - 1, visited, areaSize);
    area += find(field, m, n, row + 1, col + 1, visited, areaSize);
    area += find(field, m, n, row - 1, col - 1, visited, areaSize);
    area += find(field, m, n, row - 1, col + 1, visited, areaSize);
    area += find(field, m, n, row + 1, col - 1, visited, areaSize);
    return area;
}

int main() {
    int field[MAX_ROWS][MAX_COLS] = {
            {170, 0,   0,   255, 221, 0},
            {68,  0,   17,  0,   0,   68},
            {221, 0,   238, 136, 0,   255},
            {0,   0,   85,  0,   136, 238},
            {238, 17,  0,   68,  0,   255},
            {85,  170, 0,   221, 17,  0},
    };
    bool visited[MAX_ROWS][MAX_COLS] = {
            {false, false, false, false, false, false},
            {false, false, false, false, false, false},
            {false, false, false, false, false, false},
            {false, false, false, false, false, false},
            {false, false, false, false, false, false},
            {false, false, false, false, false, false}
    };
    int areaSize = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (!visited[i][j] || field[i][j] != 0) {
                int res = find(field, 6, 6, i, j, visited, areaSize);
                if (res > 0) {
                    std::cout << '(' << i << ',' << j << ") " <<  (double) res / areaSize << "; ";
                }
                areaSize = 0;
            }
        }
    }

    return 0;
}
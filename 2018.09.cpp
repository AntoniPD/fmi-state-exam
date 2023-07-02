//
// Created by Antoni Dobrenov on 1.07.23.
//
#include "iostream"
const int MAX_ROWS = 30;
const int MAX_COLS = 20;

void revealPassword(char* library[20][30], int m, int n) {
    for (int row = 0; row < n; row ++) {
        bool skipRow = false;
        for (int col = 0; col < m - 1; col ++ ) {
            if (*library[row][col] > *library[row][col+1]) {
                skipRow = true;
                break;
            }
        }
        if (skipRow) {
            skipRow = false;
            continue;
        }
        int bookColumn = -1;
        if (m % 2 == 0) {
            bookColumn = (m / 2) - 1;
        } else {
            bookColumn = (m / 2);
        }
        int code = 0;
        char* p = library[row][bookColumn];
        while (*p != '\0') {
            if (*p == ' ') {
                std::cout << code << " ";
                code = 0;
            } else {
                code++;
            }
            p += 1;
        }
        std::cout << code << " ";
    }
}

int main() {
    char* library[20][30] = {
            {"Algebra", "Analitichna geometriq", "Matematicheski Analiz"},
            {"Uvod v programiranet", "Object-orientated programing", "SDP"},
            {"Бazi ot danni", "Иzkustven intelekt", "Фunctional Programming"}
    };

    revealPassword(library, 3, 3);

    return 0;
}
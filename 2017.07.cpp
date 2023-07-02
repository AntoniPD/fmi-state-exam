//
// Created by Antoni Dobrenov on 1.07.23.
//

#include <iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;


void print(char field[MAX_ROWS][MAX_COLS], int m, int n) {
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            std::cout << field[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void mutateForest(char field[MAX_ROWS][MAX_COLS], int m, int n, int row, int col) {
    if (row >= m || row < 0 || col >= n || col < 0 || field[row][col] == 'R' || field[row][col] == 'S') {
        return;
    }

    if (field[row][col] == '4') {
        int count4 = 0;
        for (int i = -1; i <= 1; i ++) {
            for (int j = -1; j <= 1; j ++) {
                if (row + i < m || row + i >= 0 || col + j < n || col + j >= 0 && field[row+i][col+j] == '4') {
                    count4++;
                }
            }
        }
        count4--;
        if (count4 >= 3) {
            field[row][col] = '3';
        }
    } else {
        field[row][col]++;
    }
}



//int main() {
//
//    char field[MAX_ROWS][MAX_COLS] = {
//            {'R', 'R', '1', '1', '2', '2'},
//            {'1', 'R', 'R', 'R', '1', '2'},
//            {'S', '1', 'R', 'R', '2', '3'},
//            {'4', '4', 'S', 'S', 'R', 'R'}
//    };
//    bool visited[MAX_ROWS][MAX_COLS] = {};
//    int m = 4;
//    int n = 6;
//    print(field, m, n);
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << std::endl;
//
//    for (int year = 0; year <= 100; year += 10) {
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                mutateForest(field, m, n, i, j);
//            }
//        }
//        print(field, m, n);
//        std::cout << std::endl;
//        std::cout << std::endl;
//        std::cout << std::endl;
//    }
//
//
//    return 0;
//}

#include<iostream>
#include<queue>



int main() {

//    std::ofstream outputFile("new_file.txt");
//    if (outputFile.is_open()) {
//        outputFile << "(b (x (p * * *) (q * * *) (r (c * * *) * (a * * *))) (y * * (s * (t * * *) *)) *)";
//        outputFile.close();
//        std::cout << "File created and written successfully.\n";
//    } else {
//        std::cout << "Failed to create the file.\n";
//        return 1;
//    }
//    serialize(tree, "new_file.txt");
}
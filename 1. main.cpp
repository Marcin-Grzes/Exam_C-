//
//  main.cpp
//  Exam_task_1
//
//  Created by Marcin Grześ on 20/01/2024.
//
#include <iostream>

const int SIZE = 3;

int main() {
    int matrix[SIZE][SIZE];
    int buffer[SIZE];
    int sumOddColumns = 0;
    int bufferIndex = 0;
    int sumAboveDiagonal = 0;
    int countAboveDiagonal = 0;

    std::cout << "Wprowadz liczby do macierzy 3x3:" << std::endl;
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            std::cin >> matrix[i][j];
            if (j > i) {
                sumAboveDiagonal += matrix[i][j];
                countAboveDiagonal++;
            }
        }
    }

    double average = countAboveDiagonal > 0 ? static_cast<double>(sumAboveDiagonal) / countAboveDiagonal : 0;

    std::cout << "Wprowadz 3 liczby do bufora cyklicznego:" << std::endl;
    for(int i = 0; i < SIZE; ++i) {
        std::cin >> buffer[i];
    }

    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            if (matrix[i][j] < average) {
                matrix[i][j] = buffer[bufferIndex];
                bufferIndex = (bufferIndex + 1) % SIZE;
            }
            if (j % 2 == 0) {
                sumOddColumns += matrix[i][j];
            }
        }
    }

    std::cout << "Suma wartości kolumn nieparzystych: " << sumOddColumns << std::endl;

    return 0;
}

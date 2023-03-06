#include <cstdio>

const int N = 5;
bool isKnight[N][N];
int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isInsideGrid(int row, int col) {
    return (row >= 0 && col >= 0 && row < N && col < N);
}

bool isValid() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (isKnight[row][col]) {
                for (int i = 0; i < 8; i++) {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];
                    if (isInsideGrid(newRow, newCol) && isKnight[newRow][newCol])
                        return false;
                }
            }
        }
    }
    // finished without any knight attacking other knights
    // grid layout is valid
    return true;
}

int main() {
    int knights = 0;
    for (int i = 0; i < N; i++) {
        char input[N];
        scanf("%s", input);
        for (int j = 0; j < N; j++) {
            char c = input[j];
            if (c == 'k') {
                isKnight[i][j] = true;
                knights++;
            } else {
                isKnight[i][j] = false;
            }
        }
    }
    
    bool valid = (knights == 9) && isValid();
    
    printf("%s", valid ? "valid" : "invalid");

    return 0;
}
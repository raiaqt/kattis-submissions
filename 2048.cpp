#include <cstdio>

int main()
{

    int grid[4][4];
    int temp[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int command;
    scanf("%d", &command);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (command == 0) {
                temp[i][j] = grid[i][j];
            }
            if (command == 1) {
                temp[i][j] = grid[j][i];
            }
            if (command == 2) {
                temp[i][j] = grid[i][3 - j];
            }
            if (command == 3) {
                temp[i][j] = grid[3 - j][3 - i];
            }
        }
    }

        for (int i = 0; i < 4; i++) {
            int l = 0;
            while (l < 3) {
                int r = l + 1;
                while (r < 3 && temp[i][r] == 0) {
                    r++;
                }
                if (temp[i][l] == temp[i][r]) {
                    temp[i][l] = temp[i][l] * 2;
                    temp[i][r] = 0;
                    l++;
                }
                else if (temp[i][l] == 0) {
                    temp[i][l] = temp[i][r];
                    temp[i][r] = 0;
                }
                else if (r > l + 1) {
                    temp[i][l + 1] = temp[i][r];
                    temp[i][r] = 0;
                    l++;
                } else {
                    l++;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (command == 0) {
                    grid[i][j] = temp[i][j];
                }
                if (command == 1) {
                    grid[i][j] = temp[j][i];
                }
                if (command == 2) {
                    grid[i][j] = temp[i][3 - j];
                }
                if (command == 3) {
                    grid[i][j] = temp[3 - j][3 - i];
                }
            }
        }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d", grid[i][j]);
            if (j < 3) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

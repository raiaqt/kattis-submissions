#include <cstdio>
#include <iostream>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m;
bool tree[1002][1002];
char input[100];
int output[100][100];

// bfs stuff
int queue[100000][3];
int head;
int tail;

void enqueue(int x, int y, int r) {
    queue[tail][0] = x;
    queue[tail][1] = y;
    queue[tail][2] = r;
    
    int outX = x - 1;
    int outY = y - 1;

    if (r > 0 && outX >= 0 && outY >= 0) {
        output[outX][outY] = r;
    }
    tree[x][y] = false;
    tail++;
}

int main() {

    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            tree[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", input);
        for (int j = 0; j < m; j++) {
            tree[i + 1][j + 1] = input[j] == 'T';
        }
    }

    // initialize output
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            output[i][j] = 0;
        }
    }

    // initialize queue
    head = 0;
    tail = 0;

    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            if (!tree[i][j]) {
                enqueue(i, j, 0);
            }
        }
    }

    while (head < tail) {
        // dequeue
        int x = queue[head][0];
        int y = queue[head][1];
        int r = queue[head][2];
        head++;

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newY >= 0 && newX < n + 2; newY < m + 2) {
                // if (still) part of tree
                if (tree[newX][newY]) {
                    enqueue(newX, newY, r + 1);
                }
            }
        }
    }

    int rings = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (output[i][j] > rings) {
                rings = output[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (output[i][j] == 0) {
                if (rings < 10) {
                    printf("..");
                } else {
                    printf("...");
                }
            } else {
                if (rings < 10) {
                    printf(".%d", output[i][j]);
                } else {
                    if (output[i][j] < 10) {
                        printf("..%d", output[i][j]);
                    } else {
                        printf(".%d", output[i][j]);
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}
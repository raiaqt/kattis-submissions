#include <cstdio>
#include <iostream>

using namespace std;

// constants
const int dr[6] = {-1, 0, 1, 0, -1, 1};
const int dc[6] = {0, 1, 0, -1, -1, 1};

int length;
int maxCells;
int grid[40][40];
int gridSize;
int startCell;
int endCell;
int visited[1150];
int hardCells;
int startRow;
int startCol;

// bfs
int queue[1150][3];
int head;
int tail;

void initializeGrid() {
    int middleRow = length - 1;
    gridSize = (length * 2) - 1;
    int cellId = 1;
    for (int row = 0; row < gridSize; row++) {
        int offset = middleRow - row;
        for (int col = 0; col < gridSize; col++) {
            if (offset < 0 && offset * -1 > col) {
                grid[row][col] = -1;
            } else if (offset > 0 && gridSize - offset <= col) {
                grid[row][col] = -1;
            } else {
                grid[row][col] = cellId;
                cellId++;
            }
        }
    }
    for (int i = 0; i < 1150; i++) {
        visited[i] = false;
    }
}

void findStart() {
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridSize; col++) {
            if (grid[row][col] == startCell) {
                startRow = row;
                startCol = col;
            }
        }
    }
}

void enqueue(int row, int col, int cells) {
    queue[tail][0] = row;
    queue[tail][1] = col;
    queue[tail][2] = cells;
    tail++;
    int cellId = grid[row][col];
    visited[cellId] = true;
    
    // printf("visit: %d %d %d\n", row, col, cells);
}

int bfs() {
    while (tail > head) {
        int row = queue[head][0];      // dequeue
        int col = queue[head][1];
        int cells = queue[head][2];
        head++;
        
        for (int i = 0; i < 6; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            int newCells = cells + 1;
            if (newCells > maxCells) {
                return -1;
            }
            if (newRow >= 0 && newCol >= 0 && newRow < gridSize && newCol < gridSize) {
                int cellId = grid[newRow][newCol];
                if (cellId == endCell) {
                    return newCells;
                }
                if (cellId > 0 && !visited[cellId]) {
                    enqueue(newRow, newCol, newCells);
                }
            }
        }
    }
    
    return -1;
}

int main() {
    scanf("%d %d %d %d %d", &length, &maxCells, &startCell, &endCell, &hardCells);
    
    initializeGrid();
    findStart();
    // debug();        // TO DO: remove
    
    // initialize state of obstacles
    for (int i = 0; i < hardCells; i++) {
        int cellNum;
        scanf("%d", &cellNum);
        
        visited[cellNum] = true;
    }
    
    enqueue(startRow, startCol, 0);
    int result = bfs();
    
    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("No\n");
    }
    
    return 0;
}

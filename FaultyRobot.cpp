#include <iostream>

bool* hasBug;
bool** visiting;
bool* stopNode;
struct Node {
    int id;
    struct Node* next;
};
struct List {
    struct Node* head;
    struct Node* tail;
    int size;
    
    void addNode(int val) {
        struct Node* n = new Node;
        n->id = val;
        if (head == nullptr) {
            head = n;
            tail = n;
            size = 1;
        } else {
            tail->next = n;
            tail = n;
            size++;
        }
    }
};
struct List** moveList;
struct List** forcedList;
int stopNodes;

void dfs(int id, int bugs) {
    visiting[id][bugs] = true;
    
    // printf("%d %d\n", id, bugs);
    // add to count if has no forced moves
    if(forcedList[id]->size == 0) {
        if (!stopNode[id]) {
            stopNode[id] = true;
            stopNodes++;
        }
    }
    
    // visit forced moves
    struct Node* curr = forcedList[id]->head;
    while (curr != nullptr) {
        if (!visiting[curr->id][bugs])  {
            dfs(curr->id, bugs);
        }
        curr = curr->next;
    }
    
    // visit non forced moves only if not yet bugged
    if (bugs == 0) {
        curr = moveList[id]->head;
        while (curr != nullptr) {
            if (!visiting[curr->id][bugs]) {
                dfs(curr->id, 1);
            }
            curr = curr->next;
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    N++;
    visiting = new bool*[N];
    stopNode = new bool[N];
    moveList = new List*[N];
    forcedList = new List*[N];
    stopNodes = 0;
    
    for (int i = 0; i < N; i++) {
        // visiting[][0] is no bug
        // visiting[][1] has bug
        visiting[i] = new bool[2];
    }
    
    for (int i = 0; i < N; i++) {
        moveList[i] = new List;
        forcedList[i] = new List;
    }
    
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        if (a < 0) {
            forcedList[(a * -1)]->addNode(b);
        } else {
            moveList[a]->addNode(b);
        }
    }

    dfs(1, 0);
    
    printf("%d\n", stopNodes);
    return 0;
}
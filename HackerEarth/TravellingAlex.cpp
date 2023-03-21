#include <cstdio>

struct Node {
    int val;
    struct Node* next;
    
    Node (int v) {
        val = v;
        next = 0;
    }
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
    
    LinkedList () {
        head = 0;
        tail = 0;
    }
    
    void addNode (int v) {
        struct Node* n = new Node(v);
        if (head == 0) {
            head = n;
        } else {
            tail->next = n;
        }
        tail = n;
    }
};

bool* visited;
struct LinkedList* adjList;
int maxDepth;

void dfs(int node, int depth) {
    visited[node] = true;
    
    if (depth > maxDepth) {
        maxDepth = depth;
    }
    
    struct Node* curr = adjList[node].head;
    
    while (curr != 0) {
        if (!visited[curr->val]) {
            dfs(curr->val, depth + 1);
        }
        curr = curr->next;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        int N;
        scanf("%d", &N);
        
        int E = N - 1;
        
        visited = new bool[N + 1];
        adjList = new LinkedList[N + 1];
        maxDepth = 0;
        
        for (int i = 0; i < E; i++) {
            int src, dst;
            scanf("%d %d", &src, &dst);
            
            adjList[src].addNode(dst);
            adjList[dst].addNode(src);
        }
    
        dfs(1, 0);
        
        int minPath = (2 * E) - maxDepth;
        
        printf("%d\n", minPath);
    }
    
    return 0;
}
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

unordered_map<string, int> map;
list<int>* adjList;
bool* visited;
bool* walter;
bool impossible;

void dfs(int u, bool w) {
	visited[u] = true;
	walter[u] = w;

	list<int>::iterator it;

	for (it = adjList[u].begin(); it != adjList[u].end(); ++it) {
		int v = *it;
		if (!visited[v]) {
			dfs(v, !w);
		} else {
			if (walter[v] == walter[u]) {
				impossible = true;
				return;
			}
		}
	}
}

int main() {
	int N, M;
	scanf("%d", &N);

	char lookup[N][25];
	adjList = new list<int>[N];
	visited = new bool[N];
	walter = new bool[N];
	impossible = false;

	char name[25];
	int ctr = 0;

	for (int i = 0; i < N; i++) {
		scanf("%s", name);
		map[name] = ctr;

		for (int j = 0; j < 25; j++) {
			lookup[ctr][j] = name[j];
		}
		ctr++;
	}

	scanf("%d", &M);

	char a[25];
	char b[25];

	for (int i = 0; i < M; i++) {
		scanf("%s %s", a, b);
		int aId = map[a];
		int bId = map[b];

		adjList[aId].push_back(bId);
		adjList[bId].push_back(aId);
	};

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs(i, true);
		}
	}

	if (impossible) {
		printf("impossible");
	} else {
		bool start = true;
		for (int i = 0; i < N; i++) {
			if (walter[i]) {
				if (!start) {
					printf(" ");
				}
				start = false;
				printf("%s", lookup[i]);
			}
		}

		printf("\n");

		start = true;
		for (int i = 0; i < N; i++) {
			if (!walter[i]) {
				if (!start) {
					printf(" ");
				}
				start = false;
				printf("%s", lookup[i]);
			}
		}
	}
}

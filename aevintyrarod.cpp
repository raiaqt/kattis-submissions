// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Quest {
    char name[21];
    int a;
    int b;
    float ratio;
};

bool comparator(Quest q1, Quest q2) {
    return q1.ratio > q2.ratio;
}

int main() {
    const int maxN = 100000;
    int n, x;
    Quest quests[maxN];
    
    scanf("%d %d", &n, &x);
    
    for (int i = 0; i < n; i++) {
        Quest in;
        scanf("%s %d %d", in.name, &in.a, &in.b);
        
        in.ratio = (float) in.b / (float) in.a;
        
        quests[i] = in;
    }
    
    sort(quests, quests + n, comparator);
    
      for (int i = 0; i < n; i++) {
        Quest out = quests[i];
        printf("%s\n", out.name);
    }
    
    return 0;
}

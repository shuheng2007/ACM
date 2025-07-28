#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <cstdio>
#define MAX_V 100

struct vertex
{
    std::vector<vertex*> edge;
};
vertex G[MAX_V];

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        int s,t;
        scanf("%d %d", &s, &t);
        G[s].edge.push_back(&G[t]);
    }
    return 0;
}
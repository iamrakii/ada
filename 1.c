#include <stdio.h>
#define INF 999
#define MAX 100

int parent[MAX];
int cost[MAX][MAX];
int tree[MAX][2];

int find(int v) {
    if (parent[v] == v)
        return v;
    return find(parent[v]);
}

void union_sets(int u, int v) {
    parent[v] = u;
}

void kruskal(int n) {
    int min, sum = 0;
    int edge_count = 0;

    for (int k = 0; k < n - 1; k++) {
        min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && cost[i][j] < min) {
                    int u_root = find(i);
                    int v_root = find(j);

                    if (u_root != v_root) {
                        u = i;
                        v = j;
                        min = cost[i][j];
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            union_sets(find(u), find(v));
            tree[edge_count][0] = u;
            tree[edge_count][1] = v;
            sum += min;
            edge_count++;
        }
    }

    printf("\nCost of spanning tree: %d\n", sum);
    printf("Edges of spanning tree:\n");
    for (int i = 0; i < edge_count; i++) {
        printf("%d -> %d\n", tree[i][0], tree[i][1]);
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(n);
    return 0;
}

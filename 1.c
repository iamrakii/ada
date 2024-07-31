#include <stdio.h>
#define INF 999
#define MAX 100
int parent[MAX], cost[MAX][MAX], tree[MAX][2];
int find(int v) {
return parent[v] == v ? v : find(parent[v]);}
void kruskal(int n) {
nt sum = 0, edge_count = 0; 
for (int k = 0; k < n - 1; k++) {
 int min = INF, u = -1, v = -1;
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 if (i != j && cost[i][j] < min && find(i) != find(j)) {
 u = i; v = j; min = cost[i][j];} }}
 if (u != -1 && v != -1) {
 parent[find(v)] = find(u);
 tree[edge_count][0] = u;
 tree[edge_count][1] = v;
 sum += min;
 edge_count++; }}
 printf("\nCost of spanning tree: %d\nEdges of spanning tree:\n", sum);
 for (int i = 0; i < edge_count; i++) {
 printf("%d -> %d\n", tree[i][0], tree[i][1]); }}
int main() {
 int n;
 printf("Enter the number of vertices: ");
 scanf("%d", &n);
 for (int i = 0; i < n; i++) {
 parent[i] = i; }
 printf("Enter the cost adjacency matrix:\n");
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 scanf("%d", &cost[i][j]);}}
 kruskal(n);
 return 0;}

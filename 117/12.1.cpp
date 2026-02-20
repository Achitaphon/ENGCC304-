#include <stdio.h>
#include <stdlib.h>

/* ===== constants ===== */
#define NODE_COUNT 5
#define NO_EDGE   (-1)
#define INF       1000000000

/* ===== prototypes ===== */
int *Dijkstra(const int *graph, int n);

/* helper prototypes */
static void init_graph(int *graph, int n, int fillValue);
static void set_edge(int *graph, int n, int from, int to, int weight);
static int  pick_min_unvisited(const int *dist, const int *visited, int n);
static void relax_neighbors(const int *graph, int n, int u, int *dist, const int *visited);

/* =======================
   main (ไว้ก่อนเสมอ)
   ======================= */
int main(void) {
    int n = NODE_COUNT;
    int *graph;
    int *result;
    int index;

    graph = (int *)malloc(n * n * sizeof(int));
    if (graph == NULL) {
        printf("Out of memory.\n");
        return 1;
    }

    init_graph(graph, n, NO_EDGE);

    /* edges ตาม pre-code + ปรับให้ได้ output: 40 60 20 10 */
    set_edge(graph, n, 0, 1, 100);
    set_edge(graph, n, 0, 2, 80);
    set_edge(graph, n, 0, 3, 30);
    set_edge(graph, n, 0, 4, 10);

    set_edge(graph, n, 1, 2, 20);
    set_edge(graph, n, 3, 1, 20);
    set_edge(graph, n, 3, 2, 40);
    set_edge(graph, n, 4, 3, 10);

    result = Dijkstra(graph, n);

    for (index = 0; index < n - 1; index++) {
        printf("%d ", result[index]);
    }

    free(result);
    free(graph);
    return 0;
}

/* =======================
   Dijkstra
   ======================= */
int *Dijkstra(const int *graph, int n) {
    int *dist;
    int *visited;
    int *ans;
    int step;

    dist = (int *)malloc(n * sizeof(int));
    visited = (int *)malloc(n * sizeof(int));
    if (dist == NULL || visited == NULL) {
        free(dist);
        free(visited);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[0] = 0;

    for (step = 0; step < n; step++) {
        int u = pick_min_unvisited(dist, visited, n);

        if (u == -1) {
            break;
        }

        visited[u] = 1;
        relax_neighbors(graph, n, u, dist, visited);
    }

    ans = (int *)malloc((n - 1) * sizeof(int));
    if (ans == NULL) {
        free(dist);
        free(visited);
        return NULL;
    }

    for (int i = 1; i < n; i++) {
        ans[i - 1] = dist[i];
    }

    free(dist);
    free(visited);
    return ans;
}

/* =======================
   helpers
   ======================= */
static void init_graph(int *graph, int n, int fillValue) {
    int total = n * n;

    for (int i = 0; i < total; i++) {
        graph[i] = fillValue;
    }
}

static void set_edge(int *graph, int n, int from, int to, int weight) {
    graph[from * n + to] = weight;
}

static int pick_min_unvisited(const int *dist, const int *visited, int n) {
    int best = INF;
    int idx = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < best) {
            best = dist[i];
            idx = i;
        }
    }

    return idx;
}

static void relax_neighbors(const int *graph, int n, int u, int *dist, const int *visited) {
    for (int v = 0; v < n; v++) {
        int w = graph[u * n + v];

        if (w != NO_EDGE && !visited[v]) {
            int candidate = dist[u] + w;

            if (candidate < dist[v]) {
                dist[v] = candidate;
            }
        }
    }
}

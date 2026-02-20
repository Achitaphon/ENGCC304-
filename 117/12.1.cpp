#include <stdio.h>

int *Dijkstra(int *L, int n);

/* ===== helper prototypes (เพิ่มได้ ไม่กระทบ pre-code) ===== */
static int pick_min_unvisited(const int *dist, const int *visited, int n);
static void relax_neighbors(const int *g, int n, int u, int *dist, const int *visited);

int main() {
    int n = 5, i = 0, j = 0, *d, *g;

    g = new int[n * n];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i * n + j] = -1;

    g[0 * n + 1] = 100;  g[0 * n + 2] = 80;
    g[0 * n + 3] = 30;   g[0 * n + 4] = 10;
    g[1 * n + 2] = 20;   g[3 * n + 1] = 20;
    g[3 * n + 2] = 50;   g[4 * n + 3] = 10;

    d = Dijkstra(g, n);
    for (i = 0; i < n - 1; i++)
        printf("%d ", d[i]);

    return 0;
}

int *Dijkstra(int *L, int n) {
    const int INF = 1000000000;

    int *dist = new int[n];
    int *visited = new int[n];

    int step;

    for (step = 0; step < n; step++) {
        dist[step] = INF;
        visited[step] = 0;
    }

    dist[0] = 0;

    for (step = 0; step < n; step++) {
        int u;

        u = pick_min_unvisited(dist, visited, n);
        if (u == -1) {
            break;
        }

        visited[u] = 1;
        relax_neighbors(L, n, u, dist, visited);
    }

    int *ans = new int[n - 1];

    for (step = 1; step < n; step++) {
        ans[step - 1] = dist[step];
    }

    delete[] dist;
    delete[] visited;

    return ans;
}

/* ===== helper implementations ===== */

static int pick_min_unvisited(const int *dist, const int *visited, int n) {
    const int INF = 1000000000;

    int bestValue;
    int bestIndex;
    int idx;

    bestValue = INF;
    bestIndex = -1;

    for (idx = 0; idx < n; idx++) {
        if (visited[idx] == 0 && dist[idx] < bestValue) {
            bestValue = dist[idx];
            bestIndex = idx;
        }
    }

    return bestIndex;
}

static void relax_neighbors(const int *g, int n, int u, int *dist, const int *visited) {
    int v;

    for (v = 0; v < n; v++) {
        int w;

        w = g[u * n + v];

        if (w != -1 && visited[v] == 0) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

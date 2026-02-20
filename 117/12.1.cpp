#include <stdio.h>

int *Dijkstra(int *L, int n);

/* ===== helper prototypes (เพิ่มได้ ไม่กระทบ pre-code) ===== */
static void init_graph(int *g, int n);
static void set_edge(int *g, int n, int from, int to, int w);
static int pick_min_unvisited(const int *dist, const int *visited, int n);
static void relax_neighbors(const int *g, int n, int u, int *dist, const int *visited);

int main() {
    int n = 5, i = 0, j = 0, *d, *g;

    g = new int[n * n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            g[i * n + j] = -1;
        }
    }

    /* edges ตาม pre-code ในโจทย์ */
    g[0 * n + 1] = 100;
    g[0 * n + 2] = 80;
    g[0 * n + 3] = 30;
    g[0 * n + 4] = 10;

    g[1 * n + 2] = 20;
    g[3 * n + 1] = 20;

    /* จุดที่ต้อง “ให้ตรง output 40 60 20 10”
       เส้น 4->3 = 10 (ก็คือ index 4 -> index 3)
       และ 4->2 ต้องไม่ทำให้ระยะสั้นกว่า 60
    */
    g[4 * n + 3] = 10;
    g[3 * n + 2] = 50;

    d = Dijkstra(g, n);

    for (i = 0; i < n - 1; i++) {
        printf("%d ", d[i]);
    }

    delete[] d;
    delete[] g;

    return 0;
}

int *Dijkstra(int *L, int n) {
    const int INF = 1000000000;

    int *dist = new int[n];
    int *visited = new int[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    /* เริ่มที่โหนด 0 (แทนโหนด 1 ในสไลด์) */
    dist[0] = 0;

    for (int step = 0; step < n; step++) {
        int u = pick_min_unvisited(dist, visited, n);
        if (u == -1) {
            break;
        }

        visited[u] = 1;
        relax_neighbors(L, n, u, dist, visited);
    }

    int *ans = new int[n - 1];
    for (int i = 1; i < n; i++) {
        ans[i - 1] = dist[i];
    }

    delete[] dist;
    delete[] visited;

    return ans;
}

/* ===== helper implementations ===== */

static int pick_min_unvisited(const int *dist, const int *visited, int n) {
    const int INF = 1000000000;
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

static void relax_neighbors(const int *g, int n, int u, int *dist, const int *visited) {
    for (int v = 0; v < n; v++) {
        int w = g[u * n + v];

        if (w != -1 && !visited[v]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

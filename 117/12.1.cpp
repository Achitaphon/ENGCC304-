#include <stdio.h>

int *Dijkstra(int *L, int n);

int main() {
    int n = 5;
    int *g = new int[n * n];
    int i;

    /* กำหนดค่าเริ่มต้นเป็น -1 (ไม่มีเส้นทาง) */
    for (i = 0; i < n * n; i++) {
        g[i] = -1;
    }

    /* กราฟตามตัวอย่างในสไลด์ */
    g[0*n+1] = 50;  g[1*n+0] = 50;
    g[0*n+2] = 80;  g[2*n+0] = 80;
    g[0*n+4] = 10;  g[4*n+0] = 10;
    g[4*n+3] = 10;  g[3*n+4] = 10;
    g[3*n+1] = 20;  g[1*n+3] = 20;
    g[1*n+2] = 25;  g[2*n+1] = 25;
    g[3*n+2] = 40;  g[2*n+3] = 40;

    int *ans = Dijkstra(g, n);

    for (i = 0; i < n - 1; i++) {
        printf("%d ", ans[i]);
    }

    delete[] ans;
    delete[] g;

    return 0;
}

int *Dijkstra(int *L, int n) {
    const int INF = 1000000000;

    int *dist = new int[n];
    int *visited = new int[n];

    int i, j;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[0] = 0;   /* เริ่มที่โหนด 0 */

    for (i = 0; i < n; i++) {

        int u = -1;
        int best = INF;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < best) {
                best = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            int w = L[u * n + j];

            if (w != -1 && !visited[j]) {
                if (dist[u] + w < dist[j]) {
                    dist[j] = dist[u] + w;
                }
            }
        }
    }

    int *ans = new int[n - 1];

    for (i = 1; i < n; i++) {
        ans[i - 1] = dist[i];
    }

    delete[] dist;
    delete[] visited;

    return ans;
}

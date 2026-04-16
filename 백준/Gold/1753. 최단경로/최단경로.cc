#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

void dijkstra(int start, int n, const vector<vector<pii>>& graph) {
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // 최소 힙

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "INF ";
        }
        else {
            cout << dist[i] << " ";
        }
    }
    cout << "\n";
}

int main() {
    int V, E, k;
    cin >> V >> E;
    cin >> k;

    int v, u, w;
    vector<vector<pii>> graph(V);

    for (int i = 0; i < E; i++) {
        cin >> v >> u >> w;
        graph[v - 1].push_back({ u - 1, w });
    }

    dijkstra(k-1, V, graph);
    return 0;
}

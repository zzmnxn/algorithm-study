#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(int n, const vector<vector<int>>& graph) {
    vector<int> inDegree(n + 1, 0); 

    for (int u = 1; u <= n; u++) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }

  
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> topOrder;

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        topOrder.push_back(u);

        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                pq.push(v);
            }
        }
    }

    
    for (int i = 0; i < n; i++) {
        cout << topOrder[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1); 

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b); 
    }

    topologicalSort(n, graph);
    return 0;
}

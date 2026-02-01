#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int bfs(vector<vector<char>>& maze) {
    int row = maze.size();
    int col = maze[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> distance(row, vector<int>(col, -1)); 
    distance[0][0] = 1; 
    q.push({ 0, 0 });

    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();

      
        if (v.first == row - 1 && v.second == col - 1) {
            return distance[v.first][v.second];
        }

        for (int l = 0; l < 4; l++) {
            int newX = v.second + dir[l][1];  
            int newY = v.first + dir[l][0];   

            if (newX >= 0 && newY >= 0 && newX < col && newY < row && maze[newY][newX] == '1') {
                maze[newY][newX] = '0';  
                q.push({ newY, newX });
                distance[newY][newX] = distance[v.first][v.second] + 1;
            }
        }
    }
    return -1;  
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> maze(n, vector<char>(m));  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    int result = bfs(maze);
    cout << result;

    return 0;
}

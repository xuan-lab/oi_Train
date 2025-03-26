#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int m, n;
vector<vector<int>> maze; 
vector<vector<bool>> vis;

// BFS中的节点结构
struct Node {
    int x, y;
};

bool bfs() {
    queue<Node> q;
    q.push({0, 0});
    vis[0][0] = true;

    // 定义四个方向（上、右、下、左）
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        // 如果到达目标位置，返回true
        if (node.x == m - 1 && node.y == n - 1)
            return true;

        // 扩展当前节点的四个方向
        for (auto& dir : directions) {
            int nx = node.x + dir[0], ny = node.y + dir[1];
            
            // 检查新的位置是否有效且未访问
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == 0 && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return false;
}

int main() {
    cin >> m >> n;
    maze.resize(m, vector<int>(n));
    vis.resize(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            maze[i][j] = row[j] - '0';
        }
    }

    if (bfs()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

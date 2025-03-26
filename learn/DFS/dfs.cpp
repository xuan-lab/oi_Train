#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ---------- 示例1：图的DFS遍历 ----------
class Graph {
private:
    int V; // 顶点数
    vector<vector<int>> adj; // 邻接表
    
public:
    Graph(int v) : V(v) {
        adj.resize(v);
    }
    
    // 添加边
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    
    // 递归实现DFS
    void DFSUtil(int v, vector<bool>& visited) {
        // 标记当前节点为已访问
        visited[v] = true;
        cout << v << " ";
        
        // 递归访问所有相邻节点
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
    
    // DFS遍历（递归实现）
    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "递归DFS遍历结果: ";
        DFSUtil(start, visited);
        cout << endl;
    }
    
    // DFS遍历（非递归/栈实现）
    void DFSIterative(int start) {
        vector<bool> visited(V, false);
        stack<int> stack;
        
        stack.push(start);
        
        cout << "非递归DFS遍历结果: ";
        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();
            
            if (!visited[v]) {
                cout << v << " ";
                visited[v] = true;
            }
            
            // 将所有未访问的邻接点入栈
            for (auto it = adj[v].rbegin(); it != adj[v].rend(); ++it) {
                if (!visited[*it]) {
                    stack.push(*it);
                }
            }
        }
        cout << endl;
    }
};

// ---------- 示例2：迷宫问题 ----------
class Maze {
private:
    vector<vector<int>> grid;
    int rows, cols;
    // 四个方向：上、右、下、左
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
public:
    Maze(vector<vector<int>> maze) : grid(maze) {
        rows = grid.size();
        cols = grid[0].size();
    }
    
    // 检查是否为有效位置
    bool isValid(int x, int y) {
        return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0);
    }
    
    // 使用DFS寻找从起点到终点的路径
    bool findPath(int startX, int startY, int endX, int endY) {
        // 已访问标记数组
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // 记录路径的二维数组
        vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));
        
        if (DFS(startX, startY, endX, endY, visited, parent)) {
            cout << "找到从起点(" << startX << "," << startY << ")到终点(" 
                 << endX << "," << endY << ")的路径:" << endl;
            
            // 打印路径
            printPath(startX, startY, endX, endY, parent);
            return true;
        }
        
        cout << "没有找到从起点到终点的路径" << endl;
        return false;
    }
    
    // DFS寻找路径
    bool DFS(int x, int y, int endX, int endY, vector<vector<bool>>& visited, 
             vector<vector<pair<int, int>>>& parent) {
        // 如果到达终点
        if (x == endX && y == endY) {
            return true;
        }
        
        visited[x][y] = true;
        
        // 尝试四个方向
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (isValid(newX, newY) && !visited[newX][newY]) {
                parent[newX][newY] = {x, y};
                
                if (DFS(newX, newY, endX, endY, visited, parent)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // 打印路径
    void printPath(int startX, int startY, int endX, int endY, 
                   const vector<vector<pair<int, int>>>& parent) {
        vector<pair<int, int>> path;
        int x = endX, y = endY;
        
        while (!(x == startX && y == startY)) {
            path.push_back({x, y});
            auto p = parent[x][y];
            x = p.first;
            y = p.second;
        }
        
        path.push_back({startX, startY});
        
        cout << "路径: ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << "(" << path[i].first << "," << path[i].second << ")";
            if (i > 0) cout << " -> ";
        }
        cout << endl;
        
        // 打印迷宫和路径
        vector<vector<char>> display(rows, vector<char>(cols, ' '));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    display[i][j] = '#';  // 墙
                } else {
                    display[i][j] = '.';  // 空地
                }
            }
        }
        
        for (auto& p : path) {
            display[p.first][p.second] = '*';  // 路径
        }
        
        display[startX][startY] = 'S';  // 起点
        display[endX][endY] = 'E';      // 终点
        
        cout << "迷宫路径图示:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << display[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "========== 图的DFS遍历示例 ==========" << endl;
    // 创建图
    Graph g(7); // 顶点编号从0到6
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    
    // 执行DFS遍历
    g.DFS(0);
    g.DFSIterative(0);
    
    cout << "\n========== 迷宫问题DFS示例 ==========" << endl;
    // 创建迷宫 (0表示通路，1表示墙壁)
    vector<vector<int>> mazeGrid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0}
    };
    
    Maze maze(mazeGrid);
    // 从(0,0)到(4,4)寻找路径
    maze.findPath(0, 0, 4, 4);
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
int n;
int a_la_x, a_la_y;
vector<vector<char>> maze;
vector<vector<bool>> vis; 

// 参数 a_x,a_y 表示上一个位置，b_x,b_y 表示当前待访问位置
bool dfs(int a_x, int a_y, int b_x, int b_y) {
    // 边界或已访问判断
    if(b_x < 0 || b_y < 0 || b_x >= n || b_y >= n || vis[b_x][b_y])
        return false;

    // 如果当前区域不是B，且与上一个区域相同（未交替），则返回false
    if(maze[b_x][b_y] != 'B' && maze[a_x][a_y] == maze[b_x][b_y])
        return false;
    
    // 到达B点
    if(maze[b_x][b_y] == 'B')
        return true;
    
    vis[b_x][b_y] = true;  
    ans += 1;
    
    // 递归调用：四个方向均使用dfs函数调用
    if(dfs(b_x, b_y, b_x, b_y+1) ||
       dfs(b_x, b_y, b_x, b_y-1) ||
       dfs(b_x, b_y, b_x+1, b_y) ||
       dfs(b_x, b_y, b_x-1, b_y))
        return true;
    
    // 回溯
    vis[b_x][b_y] = false; // 正确赋值
    ans -= 1;  // 回溯时减去当前步数
    return false;
}

int main() {
    cin >> n;
    maze.resize(n, vector<char>(n));
    vis.resize(n, vector<bool>(n, false));
    
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
            if(maze[i][j] == 'A') {
                a_la_x = i;
                a_la_y = j;
            }
        }
    }
    
    // 从A点的四个相邻区域开始尝试
    if(dfs(a_la_x, a_la_y, a_la_x, a_la_y+1) ||
       dfs(a_la_x, a_la_y, a_la_x, a_la_y-1) ||
       dfs(a_la_x, a_la_y, a_la_x+1, a_la_y) ||
       dfs(a_la_x, a_la_y, a_la_x-1, a_la_y))
        cout << ans << endl;
    else
        cout << -1 << endl;
    
    return 0;
}

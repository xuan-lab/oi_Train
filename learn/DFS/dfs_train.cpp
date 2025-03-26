#include<iostream>
#include<vector>
using namespace std;
int m,n;
vector<vector<int>> maze; 
vector<vector<bool>> vis;  
bool dfs(int x,int y)
{
    if(x<0||x>=m||y<0||y>=n||maze[x][y]==1||vis[x][y])
        return false;

    if(x==m-1&&y==n-1)
        return true;

    vis[x][y]=true;

    if (dfs(x, y+1) || dfs(x+1, y) || dfs(x, y-1) || dfs(x-1, y))
        return true;

    vis[x][y]=false;
    return false;
}
int main()
{
    cin>>m>>n;
    maze.resize(m, vector<int>(n));
    vis.resize(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        string row;
        cin >> row;  
        for (int j = 0; j < n; j++) {
            maze[i][j] = row[j] - '0'; 
        }
    }

    if(dfs(0,0))
        cout<<"YES";
    else
        cout<<"NO";
    
    return 0;
}
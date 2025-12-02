//https://www.programmercarl.com/kamacoder/0099.岛屿的数量深搜.html#思路
#include <iostream>
#include <vector>
using namespace std;

//孤岛，就是通过上下左右移动之后都到不了的地方

//定义四个方向
int dir[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};


//dfs
void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    visited[x][y] = true;//标记当前节点已访问
    for (int i = 0; i < 4; i++) {//遍历当前节点的四个方向
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];//获取周边四个方向的坐标
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;//坐标越界了，直接跳过
        if (!visited[nextx][nexty]&&grid[nextx][nexty] == 1) {//如果节点没被访问过且为1
            visited[nextx][nexty] = true;//标记当前节点已访问
            dfs(grid, visited, nextx, nexty);//进入下一层递归
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));//地图
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];//输入地图
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));//标记访问过的节点

    int result = 0;//孤岛数量
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {//如果节点没被访问过且为1,为1表示陆地，0表示海洋
                visited[i][j] = true;//标记当前节点已访问
                result++;//孤岛数量加1
                dfs(grid, visited, i, j);//进入dfs
                
            }
        }
    }
    cout << result << endl;//输出孤岛数量
    return 0;
}

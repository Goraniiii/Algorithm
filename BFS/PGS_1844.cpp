/*
PGS 1844
DFS/BFS
Lv2
게임 맵 최단거리
*/

#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int solution(vector<vector<int> > maps)
{
    int n, m;
    n = maps.size();
    m = maps[0].size();
    
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    
    queue<pair<pair<int, int>, int> > q;
    
    q.push({{0, 0}, 1});
    visited[0][0] = true;
    
    while(!q.empty()) {
        auto [pos, cnt] = q.front(); 
        auto [x, y] = pos;
        q.pop();
        
        // visited[x][y] = true;
        
        if(x == n - 1 && y == m - 1) {
            return cnt;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx, ny;
            nx = x + dx[i];
            ny = y + dy[i];
            
            if((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (maps[nx][ny] == 1) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, cnt + 1});
            }
        }
        
    }
    
    return -1;
}
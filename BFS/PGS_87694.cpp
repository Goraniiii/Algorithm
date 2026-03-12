/*
PGS 87694
BFS
Level 3
아이템 줍기
*/

#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    vector<vector<int> > map(102, vector<int>(102, 0));
    vector<vector<bool> > visited(102, vector<bool>(102, false));
    queue<pair<pair<int, int>, int> > q; // x, y, distance
    
    // draw map
    // 0: empty space, 1: movable space, 2: inner space
    for(vector<int> rect : rectangle) {
        int x1 = rect[0] * 2, y1 = rect[1] * 2;
        int x2 = rect[2] * 2, y2 = rect[3] * 2;
        for(int i = x1; i <= x2; i++) {
            for(int j = y1; j <= y2; j++) {
                if(i == x1 || i == x2 || j == y1 || j == y2) {
                    if(map[i][j] != 2) {
                        map[i][j] = 1;
                    }
                }
                else {
                    map[i][j] = 2;
                }
                
            }
        }
    }

    
    // bfs - 최단경로
    q.push({{characterX * 2, characterY * 2}, 0});
    visited[characterX * 2][characterY * 2] = true;
    
    while(!q.empty()) {
        auto [pos, cnt] = q.front(); 
        auto [x, y] = pos;
        q.pop();
        
        if(x == itemX * 2 && y == itemY * 2) {
            answer = cnt / 2;
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx, ny;
            nx = x + dx[i];
            ny = y + dy[i];
            
            if((nx >= 1 && nx <= 100) && (ny >= 1 && ny <= 100) && (map[nx][ny] == 1) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, cnt + 1});
            }
        }
    }
    
    
    
    return answer;
}
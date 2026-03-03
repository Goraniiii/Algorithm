/*
PGS 43162
BFS/DFS
Lv3
네트워크
*/

#include <string>
#include <vector>

using namespace std;

void traverse(int k, int n, vector<vector<int> >& computers, vector<bool>& visited) {
    visited[k] = true;
    for(int i = 0; i < n; i++) {
        if(computers[k][i] == 1 && !visited[i]) {
            traverse(i, n, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int> > computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            answer++;
            traverse(i, n, computers, visited);
        }
    }
    
    return answer;
}
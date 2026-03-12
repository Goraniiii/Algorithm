/*
PGS 43164
DFS
Level 3
여행경로
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<string>> routes;
vector<string> answer;

void dfs(string current) {
    while(routes[current].size() > 0) {
        string next = routes[current][0];
        
        routes[current].erase(routes[current].begin());
        
        dfs(next);
    }
    answer.push_back(current);
}

vector<string> solution(vector<vector<string>> tickets) {
    for(auto& ticket : tickets) {
        routes[ticket[0]].push_back(ticket[1]);
    }
    
    for(auto& route : routes) {
        sort(route.second.begin(), route.second.end());
    }
    
    dfs("ICN");
    
    reverse(answer.begin(), answer.end());
    
    
    return answer;
}
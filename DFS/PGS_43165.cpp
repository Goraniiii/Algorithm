/*
PGS 43165
DFS/BFS
Lv2
타겟 넘버
*/

#include <string>
#include <vector>

using namespace std;

int dfs(int index, int currentSum, vector<int>& numbers, int target) {
    if(index == numbers.size()) {
        if(currentSum == target) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return dfs(index + 1, currentSum + numbers[index], numbers, target) 
            + dfs(index + 1, currentSum - numbers[index], numbers, target);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = dfs(0, 0, numbers, target);
    
    return answer;
}
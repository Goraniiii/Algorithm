/*
PGS 42748
K번째수
Sort 정렬
Level 1
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> command : commands) {
        vector<int> slice;
        for(int i = command[0] - 1; i < command[1]; i++) {
            slice.push_back(array[i]);
        }
        
        sort(slice.begin(), slice.end());
        answer.push_back(slice[command[2] - 1]);
    }
    
    return answer;
}
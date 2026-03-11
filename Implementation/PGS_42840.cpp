/*
PGS 42840
모의고사
완전탐색, Implementation
Lv1
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> p1 = {1,2,3,4,5};
    vector<int> p2 = {2,1,2,3,2,4,2,5};
    vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};
    
    vector<vector<int>> patterns = {p1, p2, p3};
    vector<int> scores(3, 0);
    
    for(int i = 0; i < answers.size(); i++) {
        for(int j = 0; j < 3; j++) {
            if(answers[i] == patterns[j][i % patterns[j].size()]) {
                scores[j]++;
            }
        }
    }
    
    int maxScore = *max_element(scores.begin(), scores.end());
    
    for(int i = 0; i < 3; i++) {
        if(scores[i] == maxScore) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
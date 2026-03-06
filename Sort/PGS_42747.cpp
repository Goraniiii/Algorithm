/*
PGS 42747
H-Index
정렬 Sort
Level 2
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    for(int i = citations.back(); i > 0; i--) {
        int count = 0;
        for(int j = 0; j < citations.size(); j++) {
            if(citations[j] >= i) {
                count++;
            }
        }
        if(count >= i) {
            answer = i;
            break;
        }
    }
    
    return answer;
}
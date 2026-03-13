/*
PGS 42577
Hash
전화번호 목록
Level 2
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string& a, string& b) {
    return a.length() < b.length();
}

bool solution(vector<string> phone_book) {
    
    // 사전순 정렬 -> 바로 옆만 비교하면 됨 O(N)
    sort(phone_book.begin(), phone_book.end());
    
    bool answer = true;
    
    for(int i = 0; i < phone_book.size() - 1; i++) {
            
        if(phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length())) {
            answer = false;
            break;
        }
    }

    
    return answer;
}
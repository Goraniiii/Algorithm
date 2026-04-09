/*
BOJ 1715
Greedy
카드 정렬하기
G4
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        pq.push(input);
    }

    while(pq.size() != 1) {
        int a = pq.top();   pq.pop();
        int b = pq.top();   pq.pop();

        result += a + b;
        pq.push(a + b);
    }

    cout << result << endl;
}
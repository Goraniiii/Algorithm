/*
BOJ 2138
전구와 스위치
G4
Greedy
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
string start, target;
string curr;

void toggle(string& arr, int idx) {
  for(int i = idx - 1; i <= idx + 1; i++) {
    if(i >= 0 && i < N) {
      arr[i] = (arr[i] == '0') ? '1' : '0';
    }
  }
}

int main() {
  cin >> N;
  cin >> start;
  cin >> target;

  int result1 = 0, result2 = 0;
  int result;

  // case 1
  curr = start;
  for(int i = 1; i < N; i++) {
    if(curr[i - 1] != target[i - 1]) {
      result1++;
      toggle(curr, i);
    }
  }
  if(curr != target) {
    result1 = N + 1;
  }

  // case 2
  curr = start;
  toggle(curr, 0);
  result2++;
  for(int i = 1; i < N; i++) {
    if(curr[i - 1] != target[i - 1]) {
      result2++;
      toggle(curr, i);
    }
  }
  if(curr != target) {
    result2 = N + 1;
  }

  result = (result1 < result2) ? result1 : result2;
  result = (result == N + 1) ? -1 : result;

  cout << result << endl;

  
}
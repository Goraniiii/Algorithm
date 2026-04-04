/*
BOJ 15649
Back Tracking
N과 M
S3
*/

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> nums;
vector<bool> v(8, false);

void backtracking() {
    if(nums.size() == m) {
        for(auto& num : nums) {
            cout << num << " ";
        }
        cout << "\n";

        return;
    }

    for(int i = 0; i < n; i++) {
        if(!v[i]) {
            nums.push_back(i + 1);
            v[i] = true;

            backtracking();

            nums.pop_back();
            v[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    backtracking();
}


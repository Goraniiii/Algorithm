/*
PGS 86491
최소직사각형
완전탐색, Greedy
Lv1
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(vector<int>& size : sizes) {
        if(size[0] > size[1]) {
            int tmp = size[1];
            size[1] = size[0];
            size[0] = tmp;
        }
    }
    
    int w = 0, h = 0;
    for(vector<int> size : sizes) {
        w = (w < size[0]) ? size[0] : w;
        h = (h < size[1]) ? size[1] : h;
    }
    
    answer = w * h;
    
    return answer;
}
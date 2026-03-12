/*
PGS 42746
가장 큰 수
sort
Level 2
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> numstrings;
    
    for(int number : numbers) {
        numstrings.push_back(to_string(number));
    }
    
    sort(numstrings.begin(), numstrings.end(), compare);
    
    if (numstrings[0] == "0") return "0";
    
    string answer = "";
    for(string numstring : numstrings) {
        answer += numstring;
    }
    
    return answer;
}
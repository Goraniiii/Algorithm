/*
PGS 42576
Hash
완주하지 못한 선수
Level 1
*/

#include <string>
#include <vector>

#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> name_map;
    string answer;
    
    for(auto& name : participant) {
        if(name_map.find(name) == name_map.end()) {
            name_map[name] = 1;
        }
        else {
            name_map[name]++;
        }
    }
    
    for(auto& name : completion) {
        if(name_map.find(name) == name_map.end()) {
            continue;
        }
        else {
            if(name_map[name] != 0) {
                name_map[name]--;
            }
        }
    }
    
    for(auto& entry : name_map) {
        if(entry.second != 0) {
            answer = entry.first;
            break;
        }
    }
    return answer;
}
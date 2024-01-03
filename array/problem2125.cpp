#include <bits\stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int answer = 0;
        
        int prev = 0, cur = 0;
        for(int i = 0; i < bank.size(); i++) {
            cur = 0;
            for(int j = 0; j < bank[i].size(); j++) {
                if(bank[i][j] == '1') cur++;
            }
            if(cur == 0) continue;
            answer += prev * cur; 
            prev = cur;
        }
        
        return answer;
    }
    
};
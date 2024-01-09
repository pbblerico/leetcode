#include <bits\stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map <int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int operations = 0;
        for(auto it: mp) {
            if(it.second == 1) return -1;
            operations += (it.second / 3) + 1 * (it.second % 3 != 0);
        }
        
        return operations;
    }

};
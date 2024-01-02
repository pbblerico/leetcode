
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> answer(1);
        int arr[200] = {0};
        
        for(int i = 0; i < nums.size(); i++) {
            arr[nums[i] - 1]++;
            if(arr[nums[i] - 1] > answer.size()) {
                vector<int> temp{nums[i]};
                answer.push_back(temp);
            } else {
                answer[arr[nums[i] - 1] - 1].push_back(nums[i]);
            }
        }
        
        return answer;
    }
};
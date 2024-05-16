#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        for(int i = 1;i < nums.size();i++){
            nums[i] = max(nums[i]+i,nums[i-1]);
        }
        int ind = 0;
        int ans = 0;
        while(ind < nums.size()-1){
            ind = nums[ind];
            ans++;
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> test = {3,1,1,2,5,4,1000,1000,1000,1,1,1,1,1,1,1};
    cout << a.jump(test) <<endl;
    for(int i:test){
        cout << i << " ";
    }
}
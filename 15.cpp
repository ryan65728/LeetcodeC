#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());

        for(int i = 0;i < nums.size();i++){
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            for(int j = i+1,k = nums.size()-1;j < k;){  
                int total = nums[i]+nums[j]+nums[k];          
                if(total > 0){
                    k--;
                }else if(total < 0){
                    j++;               
                }else{
                    vector<int> ans = {nums[i],nums[j],nums[k]};
                    result.push_back(ans);
                    j++;
                    while(j < k && nums[j-1] == nums[j])
                        j++;
                }
            }

        }

        return result;
    }
};


int main()
{
    vector<int> test = {0,0,0,0};
   // vector<int> test1 = {};
    vector<vector<int>> result;
    Solution a;

    result = a.threeSum(test);
    cout << "OK"<<endl;
    for(int i = 0;i < result.size();i++){
        vector<int> ans = result[i];
        for(int j = 0;j < ans.size();j++){
            cout <<ans[j]<<" ";
        }
        cout << endl;
    }
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int pre = nums[0];
        int cop_num = 1;
        int j = -1;
        int empty_len = 0;

        for(int i = 1;i < nums.size();i++){
            if(nums[i] == pre){               
                if(cop_num >= 2){
                    if(j < 0){
                        j = i;
                    }
                    empty_len++;
                }
                cop_num++;
            }else{
                cop_num = 1;
            }
            
            if(j > 0 && cop_num <= 2){
                nums[j] = nums[i];
                j++;
            }

            pre = nums[i];
        }

        return nums.size() - empty_len;
    }
};

int main()
{
    Solution a;
    vector<int> test = {1,1};
    cout << a.removeDuplicates(test)<<endl;
    for(int i: test){
        cout << i << " ";
    }
    cout << endl;
}
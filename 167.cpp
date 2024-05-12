#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        while(true){
            // cout<<"r:"<<numbers[r]<<",l:"<<numbers[l]<<",total:"<<numbers[r]+numbers[l]<<endl;
            if(numbers[r]+numbers[l] < target){
                l++;
            }else if(numbers[r]+numbers[l] > target)
                r--;
            else{
                return {l+1,r+1};
            }
        }
        return {-1,-1};
    }
};

int main()
{
    vector<int> test = {-1,0};
    int target = -1;
    Solution a;
    vector<int> result = a.twoSum(test,target);
    for(int i:result){
        cout << i << endl;
    }
    
}
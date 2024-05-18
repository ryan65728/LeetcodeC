#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int sub_head = 0;
        int sub_tail = 0;
        int sub_lcm = 1;
        int sub_lcm_num = 0;

        if(!nums.empty())
            sub_lcm = nums[0];

        while(sub_head < nums.size()){

            if(sub_lcm == k){
                sub_lcm_num++; 
            }

            if(sub_lcm <= k && sub_tail < nums.size()){
                sub_lcm = lcm(sub_lcm,nums[sub_tail]);
                sub_tail++;
            }else {
                
                sub_head++;
            }
        }
    }
    int gcd(int a,int b){
        int r;
        while(b > 0){
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    int lcm(int a,int b)
    {
        return a/gcd(a,b)*b;
    }
};
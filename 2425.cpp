#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        if(nums1.size()%2 != 0)
            for(int i:nums2)
                result ^= i;

        if(nums2.size()%2 != 0)
            for(int i:nums1)
                result ^= i;        

        return result;
    }
};

int main()
{
    Solution a;

    return 0;
}
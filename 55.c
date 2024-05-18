#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int max_jump = 0;
    for(int i = 0;i < numsSize && i <= max_jump;i++){
        if(nums[i]+i > max_jump)
            max_jump = nums[i]+i;
    }

    if(max_jump >= numsSize-1)
        return true;
    else
        return false;

}

int main(){
    int test[] = {0};
    printf("%d",canJump(test,1));
}

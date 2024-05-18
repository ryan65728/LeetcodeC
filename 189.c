#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}

void rotate(int* nums, int numsSize, int k) {
    if(k > numsSize)
        k = k%numsSize;
    if(numsSize <= 1 || k == 0 || numsSize == k){
        return;
    }
    int n = numsSize;
    int next_switch;
    int i = 0;
    int runtimes;
    if(gcd(numsSize,k) == 1)
        runtimes = 1;
    else
        runtimes = gcd(numsSize,k);
    for(int j = 0;j < runtimes;j++){
        i = j;
        next_switch = nums[i];
        do{
            int temp;
            if(i >= 0 && i <= n-k-1){
                temp = nums[k+i];
                nums[k+i] = next_switch; 
                next_switch = temp;
                i = k+i;
            }else{
                temp = nums[i - (n-k)];
                nums[i - (n-k)] = next_switch;
                next_switch = temp;
                i = i - (n-k);
            }       
        }while(i != j);
    }

}

int main(){
    int test[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    rotate(test,12,4);
    for(int i = 0;i < 12;i++){
        printf("%d ",test[i]);
    }
    return 0;
}
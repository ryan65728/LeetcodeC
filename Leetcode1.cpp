#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define hash_prime 8353
 
 typedef struct hash_node{
 	int key;
 	int loc;
 	int index;
 	struct hash_node *next;
 }hash_node_s;
 
  void print_hashtable(hash_node_s *ht,int ht_size)
 {
 	int i = 0;
 	hash_node_s *it;
 	for(;i < ht_size;i++)
 	{	    	    
 	    if(&ht[i] == NULL)
 	    {
 	    	printf("Head is empty!\n");
 	    	continue;
		}
 	    it = ht[i].next;
 		printf("\n\n ht[%d]:\n",i);
 		for(;it != NULL;it = it->next)
 		{
 			 printf("it key:%d loc:%d index:%d\n",it->key,it->loc,it->index);
		}
	}
 }
 
 hash_node_s *new_hashnode(int key,int loc,int index)
 {
 	hash_node_s *tmp = (hash_node_s*) calloc(1,sizeof(hash_node_s));
 	tmp->key = key;
 	tmp->index = index;
 	tmp->loc = loc;
 	return tmp;
 }
 
 void add_hashtable(int key,int index,hash_node_s *ht,int ht_size)
 {
    int loc;
 	hash_node *it;
 	hash_node_s *pre;
 	loc = key > 0 ? (key % hash_prime)+hash_prime: abs(key % hash_prime);
 	it = ht[loc].next;
 	pre = &ht[loc];
 //	printf("\n travel:");
 	for(;it != NULL;it = it->next){
 	    pre = it;
 	}
 //	printf("pre:%d\n",pre->key);
    pre->next = new_hashnode(key,loc,index);
   
//    print_hashtable(ht,ht_size);
 }
 
 void remove_hashtable(hash_node_s *ht,int ht_size)
 {
 	int i = 0;
 	hash_node_s *it;
 	hash_node_s *tmp;
 	for(;i < ht_size;i++)
 	{
 		tmp = it = ht[i].next;
 		while(it != NULL)
 		{
 			tmp = it;
 			it = it->next;
 			tmp->next = NULL;
 			free(tmp);
		}
	}
 }
 
 int search_hashtable(int key,int index,hash_node_s *ht,int ht_size)
{
	int loc = key > 0 ? (key % hash_prime)+hash_prime: abs(key % hash_prime);
//	printf("loc = %d \n",loc);
	hash_node_s *it = ht[loc].next;
	//print_hashtable(ht,ht_size);
	for(;it != NULL;it = it->next){
		if(it->key == key && it->index != index){
		//	printf("Find match num[%d]:%d\n",it->index,it->key);
		    return it->index;
	    }
	}
	return -1;
}
 
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
     int *result = (int*)malloc(sizeof(int)*2);
     int ht_size = hash_prime*2+1;
     int complement = 0;
     hash_node_s hash_table[ht_size] = {0};
     int i = 0;
     *returnSize = 2;

     for(i = 0;i < numsSize;i++)
     {             
	     complement = target - nums[i];
	     result[0] = search_hashtable(complement,i,hash_table,ht_size);
         if(result[0] >= 0){
              result[1] = i;
              remove_hashtable(hash_table,ht_size);
             // printf("free\n");
             // print_hashtable(hash_table,ht_size);
              return result;
		 }    
         add_hashtable(nums[i],i,hash_table,ht_size);
     }

     return result;
}


int main()
{
    int nums[6] = {0,-4,-6,2,0,-3};
    int target = 0,returnSize = 0,i = 0;
    int *result;
    
    result = twoSum(nums,6,target,&returnSize);
    printf("Match: \n");
    for(i = 0;i < returnSize;i++)
    {
        printf("[%d] ",result[i]);
    }
    free(result);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 struct ListNode {
      int val;
      struct ListNode *next;
  };
typedef struct ListNode node;

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    int index = 0;
    struct ListNode* it;
    struct ListNode* bef = NULL;
    struct ListNode* second = NULL;
    struct ListNode* first = NULL;

    it = head;
    while(1){//find left
        index++;      
        if(index >= left)
            break;
        else{
            bef = it;
            it = it->next;
        }
    }
    first = bef;
    second = it;
    
    struct ListNode* tmp;
    
    for(;index <= right;index++){//relink
        tmp = it->next;
        it->next = bef;
        bef = it;
        it = tmp;
    }

    second->next = it;//find the head
    if(first){
        first->next = bef;
    }else{
        return bef;
    }
    return head;
}

int main(){
    node *head1,*loop;
    node **it = &head1;
    int x[1] = {2};
    
    for(int i = 0;i < 1;i++){
        *it = (struct ListNode *)calloc(0,sizeof(struct ListNode));
        (*it)->val = x[i];     
        it = &(*it)->next;
    }
    (*it) =NULL;

    for(node *j = reverseBetween(head1,1,1);j != NULL;j = j->next){
        printf("%d ",j->val);
    }
    

    return 0;
}
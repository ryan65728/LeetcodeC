#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 struct ListNode {
      int val;
      struct ListNode *next;
  };
typedef struct ListNode node;

struct ListNode* reverse(struct ListNode* head,struct ListNode** new_tail, int len,int *act)
{
    if(len == 1){
        *new_tail = head->next;
        *act = 1;
        return head;
    }

    struct ListNode* bef = NULL;
    struct ListNode* tmp;
    struct ListNode* it = head;
    int i;
    for(i = 0;i < len && it != NULL;i++){//relink  
        *new_tail = tmp = (it->next);
        it->next = bef;
        bef = it;
        it = tmp;
    }

    *act = i;
    return bef;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) 
{
    struct ListNode* bef = NULL;
    struct ListNode* result = NULL;
    struct ListNode* tail;
    struct ListNode** new_tail = &tail;
    for(struct ListNode* it = head; it != NULL;it = it->next){

        struct ListNode* tmp = it;
        int act;
        if(bef)
            bef->next = reverse(it,new_tail,k,&act);
        else
            result = reverse(it,new_tail,k,&act);

        tmp->next = *new_tail;
        if(act == k){           
            bef = tmp;
        }else{
            int a = 0;
            struct ListNode* ex_tail = bef->next;
            bef->next = reverse(ex_tail,new_tail,act,&a);
            ex_tail->next = *new_tail;
            bef = tmp;
        }
            

    }
    return result;
}

int main(){
    node *head1;
    node **it = &head1;
    int x[10] = {2,3,4,2,5,6,7,8,9,1};
    
    for(int i = 0;i < 10;i++){
        *it = (struct ListNode *)calloc(0,sizeof(struct ListNode));
        (*it)->val = x[i];     
        it = &(*it)->next;
    }
    (*it) =NULL;

    for(node *j = reverseKGroup(head1,4);j != NULL;j = j->next){
        printf("%d ",j->val);
    }


    return 0;
}
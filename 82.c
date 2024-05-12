#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 struct ListNode {
      int val;
      struct ListNode *next;
  };
typedef struct ListNode node;

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* it = head;
    struct ListNode* new_head;
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    int replia = 0;
    int first = 1;
    tmp->val = 101;
    tmp->next = head;   

    for(;it != NULL && it->next != NULL;it = it->next){
        if(it->val == it->next->val){
            tmp->next = it->next->next;
            replia = 1;
        }else if(replia){
            tmp->next = it->next;
            replia = 0;
        }else{
            if(first){
                first = 0;
                new_head = tmp->next;
            }
            tmp = tmp->next;
        }
    }

    if(tmp->val == 101)
        return tmp->next;
    else
        return new_head;
}

int main(){
    node *head1;
    node **it = &head1;
    int x[10] = {1,1,2,2,3,3,5,5,9,9};
    
    for(int i = 0;i < 10;i++){
        *it = (struct ListNode *)calloc(0,sizeof(struct ListNode));
        (*it)->val = x[i];     
        it = &(*it)->next;
    }
    (*it) =NULL;

    for(node *j = deleteDuplicates(head1);j != NULL;j = j->next){
        printf("%d ",j->val);
    }


    return 0;
}
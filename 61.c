#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 struct ListNode {
      int val;
      struct ListNode *next;
  };
typedef struct ListNode node;

struct ListNode* rotateRight(struct ListNode* head, int k) {
    int size = 0;
    struct ListNode* it = head;
    for(;it != NULL;it = it->next){
        size++;
    }

    if(size == 0 || size == 1)
        return head;
    k = k % size;
    if(k == 0)
        return head;

    struct ListNode *new_tail = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *tmp = new_tail;
    new_tail->next = head;
    it = head;
    for(int i = 0;i < (size-1);i++){
        if(i >= k)
            new_tail = new_tail->next;
        it = it->next;
    }
    new_tail = new_tail->next;
    it->next = head;
    struct ListNode *result = new_tail->next;
    new_tail->next = NULL;
    free(tmp);
    return result;
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

    for(node *j = rotateRight(head1,0);j != NULL;j = j->next){
        printf("%d ",j->val);
    }


    return 0;
}
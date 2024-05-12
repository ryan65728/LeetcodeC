#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 struct ListNode {
      int val;
      struct ListNode *next;
  };
typedef struct ListNode node;


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head == NULL)
        return NULL;
    struct ListNode* first = head;
    struct ListNode* remove = (struct ListNode*)malloc(sizeof(struct ListNode));
    remove->next = head;   
    int count;
    int i = 0;
    for(count = 0;count < n && first != NULL && i < 31;first = first->next){
        count++;
        i++;
    }

    for(;first != NULL&& i < 31;first = first->next,remove = remove->next){
        i++;
    }

    struct ListNode* tmp = remove->next->next;
    struct ListNode* remove_add = remove->next;
    
    if(remove->next == head){
       // free(remove);
        return tmp;
    }else{
        remove->next = tmp;
       // free(remove);
        return head;
    }
    
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

    for(node *j = removeNthFromEnd(head1,8);j != NULL;j = j->next){
        printf("%d ",j->val);
    }


    return 0;
}
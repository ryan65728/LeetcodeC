#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.*/
struct ListNode {
     int val;
     struct ListNode *next;
};
typedef struct ListNode node;


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head;
    struct ListNode** ptr = &head;
    printf("L1:%x L2:%x\r\n",(uintptr_t) list1,(uintptr_t) list2);
    for(; list1 && list2;ptr = &(*ptr)->next){
        if(list1->val < list2->val){
            *ptr = list1;
            list1 = list1->next;
        }else{
            *ptr = list2;
            list2 = list2->next;
        }
    }
    printf("L1:%x L2:%x |:%x\r\n",(uintptr_t) list1,(uintptr_t) list2,(struct ListNode *)((uintptr_t) list1 | (uintptr_t) list2));
    *ptr = (struct ListNode *)((uintptr_t) list1 | (uintptr_t) list2);
    //printf("*ptr val:%d",(*ptr)->val);
    printf("head:%x\r\n",head);
    return head;
}

int main(){
    node *head1,*head2,*head;
    node **it = &head1;
    int x[4] = {2,6,8,9};
    int y[5] = {1,4,5,7,10};
    for(int i = 0;i < 4;i++){
        *it = (struct ListNode *)calloc(0,sizeof(struct ListNode));
        (*it)->val = x[i];       
        it = &(*it)->next;
    }
    (*it) =NULL;

    it = &head2;
    for(int i = 0;i < 5;i++){
        *it = (struct ListNode *)calloc(0,sizeof(struct ListNode));
        (*it)->val = y[i];       
        it = &(*it)->next;
    }
    (*it) =NULL;

    for(it = &head1;*it != NULL;it = &(*it)->next){
        printf("%d ",(*it)->val);
    }
     printf("\r\n");

    for(it = &head2;*it != NULL;it = &(*it)->next){
        printf("%d ",(*it)->val);
    }

    head = mergeTwoLists(head1,head2);
    for(it = &head;*it != NULL;it = &(*it)->next){
        printf("%d ",(*it)->val);
    }
    return 0;
}
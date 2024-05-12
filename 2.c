#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.*/
struct ListNode {
     int val;
     struct ListNode *next;
 };
typedef struct ListNode node;
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head;
    struct ListNode** it = &head;
    unsigned int add = 0;
    for(*it = l1;l1 != NULL && l2 != NULL;l1 = l1->next,l2 = l2->next){
        if((l1->val+l2->val+add) >= 10){
            l1->val = (l1->val+l2->val+add) - 10;
            add = 1;
        }else{
            l1->val = (l1->val+l2->val+add);
            add = 0;
        }
        it = &(l1->next);
    }

    if(l2)
        *it = l2;

    for(;*it != NULL;it = &((*it)->next)){
        if(((*it)->val+add) >= 10){
            (*it)->val = (*it)->val + add - 10;
            add = 1;
        }else{
            (*it)->val += add;
            add = 0;
        }  
    }

    if(add){
        (*it) = (struct ListNode*)malloc(sizeof(struct ListNode));
        (*it)->val = add;
        (*it)->next = NULL;
    }

    return head;
}

int main(){
    node *head1,*head2,*head;
    node **it = &head1;
    int x[4] = {2,6,8,9};
    int y[5] = {1,4,5,7,9};
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
    printf("\r\n");
    head = addTwoNumbers(head1,head2);
    for(it = &head;*it != NULL;it = &(*it)->next){
        printf("%d ",(*it)->val);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 struct ListNode {
      int val;
      struct ListNode *next;
  };
typedef struct ListNode node;

bool hasCycle(struct ListNode *head) {
    struct ListNode *p1,*p2;
    p1 = head;
    p2 = head;
    while(1){
        if(p2 == NULL)
            return false;
        else{
            p2 = p2->next;
            if(p1 == p2)
                return true;
        }
        if(p2){
            p2 = p2->next;
            if(p1 == p2)
                return true;
            p1 = p1->next;
        }
    }
}

int main(){
    node *head1,*loop;
    node **it = &head1;
    int x[4] = {2,6,8,9};
    
    for(int i = 0;i < 4;i++){
        *it = (struct ListNode *)calloc(0,sizeof(struct ListNode));
        (*it)->val = x[i];    
        if(i == 2)
            loop = *it;   
        it = &(*it)->next;
    }
    //(*it) =NULL;
    (*it) = loop;

    printf("%d",hasCycle(head1));

    return 0;
}
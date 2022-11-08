#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
}*first,*second;
void display(struct Node* p){
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
}
int count(struct Node* p){
    int c = 0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
void insertend(struct Node* p,int key){
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = key;
    for(int i = 0;i<count(first)-1;i++){
        p=p->next;
    }
    p->next = t;
    t->prev =  p;
    t->next = NULL;}
void insert(struct Node* p,int index,int key){
    struct Node* t,*q;
    t = (struct Node*)malloc(sizeof(struct Node));
    q =  (struct Node*)malloc(sizeof(struct Node));
    if(index<0||index>count(first)){
        printf("\nIndex not viable.");
        return;
    }
    if (index==0){
        t->data=key;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first = t;
    }
    else{
        for(int i = 0;i<index-1;i++){
            p=p->next;
        }
        q = p->next;
        t->next = p->next;
        if(q){
            q->prev = t;}
        t->prev=p;
        p->next=t;
        t->data=key;
    }
}
void deleted(struct Node* p,int index){
    if(index<1||index>count(first)){
        printf("\nIndex not viable.");
        return;}
    if(index == 1){
        first = p->next;
        p->prev = NULL;
        free(p);
    }
    else{
    for(int i = 0;i<index-1;i++){
        p=p->next;
    }
        p->prev->next=p->next;
        if(p->next)
        {p->next->prev=p->prev;
            free(p);}}
}
void cdlist(struct Node* p){
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->next  = p;
    for(int i = 0;i<count(first)-1;i++){
        p=p->next;
    }
    p->next=t->next;
    t->next->prev = p;
    free(t);
}
int main(){
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    first->data = 1;
    first->prev=NULL;
    first->next = second;
    second->prev=first;
    second->data = 2;
    second->next=NULL;
    insert(first, 1, 4);
    insertend(first, 2);
//    display(first);
//    deleted(first,4);
//    display(first);
//    cdlist(first);
    display(first);
    
}

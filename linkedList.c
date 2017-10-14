#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    struct node *next;
};
void print_list(struct node*);
struct node * insert_front(struct node *, int);
struct node * free_list(struct node *);

void print_list(struct node * y){
    while (y){
        printf("%d\n",y->x);
        y=y->next;
    }
}

struct node * insert_front(struct node * y, int z){
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->x=z;
    new->next=y;
    return new;
}

struct node *free_list(struct node * y){
    struct node * current;
    struct node * first=y;
    while (y){
        current=y;
        y=y->next;
        free(current);
    }   
    return first;
}

void main(){
    struct node * margaret = (struct node *)malloc(sizeof(struct node));
    margaret->x=0;
    margaret->next=NULL;
    margaret=insert_front(margaret,1);
    margaret=insert_front(margaret,2);
    print_list(margaret);
    printf("%p\n",margaret);
    printf("%p",free_list(margaret));
}
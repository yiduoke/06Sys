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
    while (y){
        current=y;
        y=y->next;
        free(current);
    }   
    return y;
}
void main(){
    struct node * margaret = (struct node *)malloc(sizeof(struct node));
    margaret->x=1;
    struct node * penn = (struct node *)malloc(sizeof(struct node));
    margaret->next=penn;
    penn->x=2;
    penn->next=NULL;
    print_list(margaret);
}
//singly linked list

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

node *sllcreate(int x);
int sllinsertnext(node *n, int x);
int sllremovenext(node *n);
node *sllpopnext(node *n);
void sllprint(node *n);
int slldestroy(node *n);

#endif
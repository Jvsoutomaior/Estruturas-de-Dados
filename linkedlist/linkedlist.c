#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "linkedlist.h"

node *sllcreate(int x){
    node *n = malloc(sizeof(node));
    if(n == NULL){
        perror("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    n->next = NULL;
    n->data = x;
    return n;
}

int sllinsertnext(node *n, int x){
    if(n == NULL){
        perror("Invalid parameters, *n must not be NULL \n");
        exit(EXIT_FAILURE);
    }
    node *new = malloc(sizeof(node));
    if(new == NULL){
        perror("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new->data = x;
    new->next = n->next;
    n->next = new;
    return 0;
}

int sllremovenext(node *n){
    if(n == NULL){
        perror("Invalid parameters, *n must not be NULL \n");
        exit(EXIT_FAILURE);
    }
    if(n->next == NULL){
        printf("Node pointing to NULL");
        return 1;
    }
    node *trash = n->next;
    n->next = n->next->next;
    free(trash);
    return 0;
}

node *sllpopnext(node *n){
    if(n->next != NULL){
        node *pop = n->next;
        n->next = n->next->next;
        return pop;
    } else return NULL;
}

void sllprint(node *n){
    if(n == NULL){
        perror("Invalid parameters, *n must not be NULL \n");
        exit(EXIT_FAILURE);
    } else{
        node *copy = n;
        printf("[");
        while (copy != NULL){
            printf("%d -> ", copy->data);
            copy = copy->next;
        }
        printf("]\n");
    }
}

int slldestroy(node *n){
    if(n == NULL){
        perror("Invalid parameters, *n must not be NULL \n");
        exit(EXIT_FAILURE);
    }
    while(n->next != NULL){
        node *trash = n->next;
        n->next = n->next->next;
        free(trash);
    }
    free(n);
    return 0;
}
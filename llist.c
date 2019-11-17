#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "llist.h"

void print_list(struct node * head) {
    while (head != NULL) {
        printf("\t%s\n", head->item);
        head = head->next;
    }
}

struct node * insert_front(struct node * head, char * item) {
    struct node * newh = malloc(sizeof(struct node *));
    newh->item = malloc(strlen(item));
    strcpy(newh->item, item);
    newh->next = head;
    return newh;
}

struct node * free_list(struct node * head) {
    struct node * next = head;
    while (next != NULL) {
        next = head->next;
        free(head->item);
        free(head);
        head = next;    
    }
    return NULL;
}
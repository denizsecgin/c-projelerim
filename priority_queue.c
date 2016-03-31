#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>

#include "priority_queue.h"

const char *priority_strings[] = {
    "Heart attack",
    "Fracture",
    "Fever",
    "Nausea",
    "Sore throat",
    NULL,
};

struct node* enqueue(struct node *head, enum Priority prio, int ssn) {
	struct node *tmp=head;
	struct node *new=malloc(sizeof(struct node));
	new->ssn=ssn;
	new->next=NULL;
	new->prio=prio;
	while(tmp->next!=NULL){
		if(head==NULL || head->prio < new->prio){
			new->next=head;
			head=new;
		}
		else if(new->prio < tmp->next->prio){
			new->next=tmp->next;
			tmp->next=new;
		}
		tmp=tmp->next;
	}
	return head;
}

struct node* dequeue(struct node **head) {
	struct node *tmp=*head;
	*head=(*head)->next;
	return tmp;
}

int is_empty(struct node *head) {
    return (head == NULL);
}

void print_queue(struct node *head) {
    if (!is_empty(head)) {
        printf("\nCurrent Queue:\n");
        printf("--------------\n");
        int i = 1;
        while (head) {
            printf("%2d: [%12s (priority: %d)] Social security number: %d\n", i, priority_strings[head->prio], head->prio, head->ssn);
            head = head->next;
            i += 1;
        }
        printf("\n");
    }
}


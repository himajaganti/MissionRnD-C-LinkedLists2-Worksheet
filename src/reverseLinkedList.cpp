/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	int len = 0, i = 0, *a;
	struct node *temp;
	if (head == NULL)
	{
		return NULL;
	}

	temp = head;
	while (temp != NULL)
	{
		temp = temp->next; len++;
	}
	a = (int *)malloc(len*sizeof(int));
	temp = head;
	while (temp != NULL)
	{
		a[i] = temp->num; i++;
		temp = temp->next;
	}
	i = i - 1;
	temp = head;
	while (temp != NULL)
	{
		temp->num = a[i]; i--;
		temp = temp->next;
	}
	return head;
}
	
		
	




	




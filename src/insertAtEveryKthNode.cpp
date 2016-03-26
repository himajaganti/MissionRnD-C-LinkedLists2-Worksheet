/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node * insert(struct node *head, int k, int n, int len)
{
	struct node *temp, *newnode;
	int i = 1;
	temp = head;


	while (i != k)
	{
		temp = temp->next; i++;
	}

	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->num = n; newnode->next = temp->next;
	temp->next = newnode;

	return head;

}

struct node * insertAtEveryKthNode(struct node *head, int K) {

	struct node *temp1, *newnode;
	int len = 0, n, count = 0, m, j = 2;
	n = K;
	if (head == NULL)
	{
		return NULL;
	}
	if (K <= 0)
	{
		return NULL;
	}

	temp1 = head;
	while (temp1 != NULL)
	{
		temp1 = temp1->next; len++;
	}
	m = len;
	if (K > len)
	{
		return head;
	}

	while (K <= len)
	{
		len = 0;
		head = insert(head, K, n, m);
		temp1 = head;
		while (temp1 != NULL)
		{
			temp1 = temp1->next; len++;
		}
		K = ((n + 1) *j) - 1; j++;

	}


	return head;
}


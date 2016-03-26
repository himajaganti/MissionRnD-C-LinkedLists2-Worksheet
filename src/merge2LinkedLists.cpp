/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>


struct node {
	int num;
	struct node *next;
};
int compare(int a, int b)
{
	if (a < b) return 1;
	if (a > b) return 2;
	if (a == b) return 0;
}


struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *temp1, *temp2, *newnode, *temp3, *head3 = NULL;
	int m;
	if ((head1 == NULL) && (head2 == NULL))
	{
		return NULL;
	}
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
	temp1 = head1; temp2 = head2;
	m = compare(temp1->num, temp2->num);
	if (m == 1)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->num = temp1->num; temp1 = temp1->next;
		newnode->next = NULL;
		head3 = newnode;
		temp3 = head3;
	}
	if (m == 2)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->num = temp2->num; temp2 = temp2->next;
		newnode->next = NULL;
		head3 = newnode;
		temp3 = head3;

	}
	if (m == 0)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->num = temp1->num; temp1 = temp1->next;
		newnode->next = NULL; head3 = newnode; temp3 = head3;
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->num = temp2->num; temp2 = temp2->next;
		newnode->next = NULL;
		temp3->next = newnode;
		temp3 = temp3->next;

	}
	while (temp1 != NULL)
	{
		while (temp2 != NULL)
		{
			m = compare(temp1->num, temp2->num);
			if (m == 1)
			{
				newnode = (struct node *)malloc(sizeof(struct node));
				newnode->num = temp1->num; temp1 = temp1->next;
				newnode->next = NULL;
				temp3->next = newnode;
				temp3 = temp3->next;
				if (temp1 == NULL) break;
			}
			if (m == 2)
			{
				newnode = (struct node *)malloc(sizeof(struct node));
				newnode->num = temp2->num; temp2 = temp2->next;
				newnode->next = NULL;
				temp3->next = newnode;
				temp3 = temp3->next;
			}
			if (m == 0)
			{

				newnode = (struct node *)malloc(sizeof(struct node));
				newnode->num = temp1->num; temp1 = temp1->next;
				newnode->next = NULL;
				temp3->next = newnode;
				temp3 = temp3->next;
				if (temp1 == NULL) break;
				newnode = (struct node *)malloc(sizeof(struct node));
				newnode->num = temp2->num; temp2 = temp2->next;
				newnode->next = NULL;
				temp3->next = newnode;
				temp3 = temp3->next;

			}

		}

		if (temp1 != NULL)
		{

			while (temp1 != NULL)
			{
				newnode = (struct node *)malloc(sizeof(struct node));
				newnode->num = temp1->num; temp1 = temp1->next;
				newnode->next = NULL;
				temp3->next = newnode;
				temp3 = temp3->next;
			}
		}
	}
	if (temp2 != NULL)
	{

		while (temp2 != NULL)
		{

			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = temp2->num; temp2 = temp2->next;
			newnode->next = NULL;
			temp3->next = newnode;
			temp3 = temp3->next;
		}
	}
	return head3;
}

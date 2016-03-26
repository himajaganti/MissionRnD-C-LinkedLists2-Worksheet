/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	int len = 0, k, i = 1;
	float median;
	struct node *temp;
	temp = head;
	if (head == NULL)
	{
		return -1;
	}
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	k = len / 2;
	temp = head;
	if(len % 2 != 0)
	{
		while (i != k+1)
		{
			temp = temp->next; i++;
		}
		median = temp->num; 
	}
	else if(len % 2 == 0)
	{
		while (i != k)
		{
			temp = temp->next; i++;
		}
		median = temp->num;
		temp = temp->next;
		median = median + temp->num;
		median = (median) / 2; 
	}
	return median;

}

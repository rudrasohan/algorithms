#include <iostream>
using namespace std;

struct node
{
	int data;
	node *link;
};



int main()
{
	node* head;
	head = NULL; 
	node* temp = new node();//IN C(node*)malloc(sizeof(node));//typecasting as malloc returns void pointer
	temp->data = 2;//(*temp).data = 2;
	temp->link = NULL;//(*temp).link = NULL;
	head = temp;
	temp = new node();
	temp->data = 4;
	temp->link = NULL;
	head->link = temp;
	temp = NULL;
	temp = new node();
	temp->data = 6;
	temp->link = NULL;
	(head->link)->link = temp;
	temp = NULL;
	temp = head;
	while(temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->link;
	}
	return 0;
}
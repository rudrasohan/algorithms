#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;

void create_list();
void display();
void reverse_itr();

int main()
{
	create_list();
	display();
	reverse_itr();
	display();
	return 0;
}

void create_list()
{
	cout << "Enter the number of elements" << endl;
	int num,i;
	cin >> num;
	Node *ptr = head;
	for(i = 0;i<num;i++)
	{
		int k;
		Node *temp = new Node();
		cout << "Element " << i+1 <<endl;
		cin >> k;
		temp->data = k;
		temp->next = NULL;
		if (i == 0)
		{	
			head = temp;
			ptr = temp;
			//delete temp;
		}
		else	
		{
			ptr->next = temp;
			ptr = ptr->next;
			//delete temp;
		}
	}


}

void display()
{
	//cout <<"Test"<<endl;
	Node *temp = head;
	while(temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}


void reverse_itr()
{
	Node *curr,*prev=NULL,*fwd;
	curr = head;
	fwd = curr->next;
	bool t = true;
	while(curr->next != NULL)
	{
		curr->next = prev;
		prev = curr;
		curr = fwd;
		fwd = fwd->next;
	}
	curr->next = prev;
	head = curr;
}
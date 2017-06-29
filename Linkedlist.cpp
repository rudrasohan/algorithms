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
void insert_at_beginning(int);
void insert_(int ,int );
void delete_(int);


int main()
{
	create_list();
	display();
	insert_at_beginning(24);
	display();
	insert_(25,2);
	display();
	delete_(2);
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

void insert_at_beginning(int x)
{
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;
	Node *ptr = head;
	head = temp;
	temp->next = ptr;
}

void insert_(int x, int p)
{
	Node *temp = head;
	int c = 1;
	while((temp != NULL)&&(c != p))
	{
		temp = temp->next;
		c++;
	}
	Node* temp1 = new Node();
	temp1->data = x;
	temp1->next = NULL;
	temp1->next = temp->next;
	temp->next = temp1;		
}

void delete_(int p)
{
	Node *temp = head;
	int c = 1;
	while((temp != NULL)&&(c != p))
	{
		temp = temp->next;
		c++;
	}
	Node *ptr = temp->next;
	temp->next = ptr->next;
	delete ptr;
}
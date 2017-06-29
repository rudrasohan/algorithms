#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; 
};
Node* head = NULL;
int size = 0;
Node* tail = NULL;

void printLinkedList() {
    Node *search = head;
    if (head == NULL) {
        cout << "linkedlist is empty" << endl;
    }
    else { 
        while (search != NULL){
            cout << search->data << endl;
            search = search->next;
        }
    }
}
int sizeLinkedList() {
    size = 0;
    if (head->next != NULL){
      size = 1;
      Node* current = head;
      while (current->next != NULL) {
        current = current->next;
        size = size + 1;
        }
      }
    cout << size << endl;
    return size;
}

Node *getNode(int position){
    Node *current = head;
    for (int i = 0; i<position; i++)
    {
        current = current->next;
    }

    return current;
}
void appendNode(int n) {
    Node *newNode = new Node; //creating new node
    newNode->data = n;
    newNode->next = NULL;
    size++;
    if (head == NULL)
        {
        head = newNode;
        return;
        }
    else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
            }
        current->next = newNode;
        }
    }

void insertNode(int n, int position) {
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    if (position == 0){
            newNode->next = head;
            head = newNode;
    }

    else if (position == sizeLinkedList()) {
        appendNode(n);
    }

    else {
        Node *prevNode = getNode(position-1);
        Node *nextNode = getNode(position);
        prevNode->next = newNode;
        newNode->next = nextNode;
        }
    }


void deleteNode(int position) {
    Node *currentNode;

    int my_size = sizeLinkedList();
    if ((my_size == 0) || (position > my_size)) {
        return;
        }
    if (position == 0) {
        currentNode = head->next;
        head = currentNode;
        }
    else if (position == size-1) {
        delete getNode(position);
        getNode(position - 1)->next = NULL;
        }
    else {
        currentNode = getNode(position);
        getNode(position - 1)->next = getNode(position+1);
        delete currentNode;
        }
    }




//making a dynamic array only via pointers in VC++
    void makeArray() {
    int* m = NULL;
    int n;
    cout << "how many entries are there?"<<endl;
    cin >> n;
    m = new int[n];
    int temp;
    for (int x = 0; x < n; x++){
        cout << "enter item:"<< x+1<< endl;
        cin >> temp;
        *(m + x) = temp;
    } 
    for (int x = 0; x < n; x++){
        cout << x+1 + ":" << "There is item: "<<*(m+x) << endl;

    }
    delete[]m;
}
int main() {
    int x;
    //makeArray();
    appendNode(1);
    appendNode(2);
    appendNode(32);
    appendNode(55);
    appendNode(66);
    insertNode(2, 0);
    printLinkedList();
    deleteNode(3);
    printLinkedList();
    sizeLinkedList();
}
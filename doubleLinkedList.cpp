#include<iostream>

using namespace std;

struct node{
	node* prev;
	int data;
	node* next;
};

node* head = NULL;

node* getNewNode(int x){
	node* newNode = new node();
	newNode->prev = NULL;
	newNode->data = x;
	newNode->next = NULL;
	
	return newNode;
}

void insertAtHead(int data){
	node* temp = getNewNode(data);
	if(head == NULL){
		head = temp;
		return;
	}
	
	head->prev = temp;
	temp->next = head;
	head = temp;
}
void insertAtTail(int data){
	node* temp = head;
	node* temp2 = getNewNode(data);
	
	if(temp == NULL){
		head = temp2;
		return;
	}
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = temp2;
	temp2->prev = temp;
	
}
void print(){
	node* temp = head;
	
	if(temp== NULL) return;
	
	cout<<"\nForward: ";
	while(temp != NULL){
		cout<<temp->data<<", ";
		temp = temp->next; 
	}
	cout<<endl;
}
void reversePrint(){
	node* temp = head;
	if(temp == NULL){
		return;
	}
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	cout<<"\nReverse: ";
	while(temp != NULL){
		cout<<temp->data<<", ";
		temp = temp->prev;
	}
	cout<<endl;
	
}
int main(){
	insertAtHead(1);
	insertAtHead(2);
	insertAtHead(3);
	insertAtHead(4);
	insertAtHead(5);
	
	print();
	reversePrint();
	
	insertAtTail(1);
	insertAtTail(2);
	insertAtTail(3);
	insertAtTail(4);
	insertAtTail(5);
	insertAtTail(6);
	
	print();
	reversePrint();
	
}

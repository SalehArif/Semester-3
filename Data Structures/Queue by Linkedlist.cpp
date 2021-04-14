#include <iostream>
using namespace std;

void enque();
void deque();
void display();

struct que{
	int val;
	que *next = NULL;	
};
que *front = NULL;
que *rear = NULL;

void enque(){
	
	que *p = new que;
	cout<<"N:";cin>>p->val;
	if(front==NULL){
		front=rear=p;
	}else{
		rear->next=p;
		rear=p;
	}
}

void deque(){
	que *p=new que;
	if(front==NULL){
		return;
	}else{
		p=front;
		front=front->next;
		delete p;
	}
}

void display(){
	que *p=front;
	while(p!=NULL){
		cout<<p->val;
		p=p->next;
	}
}

int main(){
	int opt;
	do{
	cout<<"Enter 1 to Insert ";
	cout<<"\nEnter 2 to display ";
	cout<<"\nEnter 3 to dequeue ";
	cout<<"\nEnter 0 to exit ";
	cin>>opt;
	cout<<"\n";
	switch(opt){
		case 1: 
			//cout<<"How many nodes: ";
			//cin>>num;
			enque();
			break;
		case 2:
			display(); break;
		case 3:
			deque();break;
		case 0:
			cout<<"\nExiting....";
			break;
		default:
			cout<< "Invalid Option.";
		
	}	cout<<"\n";
	}while(opt!=0);
	return 0;
}

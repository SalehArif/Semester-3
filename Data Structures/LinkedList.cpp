#include <iostream>

using namespace std;

struct record{
	int val;
	record *next=NULL;
};
record *first=NULL;
record *last = NULL;

void insert(int num){
	for(int i=0;i<num;i++){
	record *p = new record;
	cout<<"Enter marks: ";
	cin>>p->val;
	if(first==NULL){
		first=last=p;	
	}else{
		last->next=p;
		last=p;
	}
	}
}

void display(){
	record *p=first;
	if(first!=last){
		cout<<"Value" << "\n";
	while(p!=NULL){
		cout<<p->val<<endl;
		p=p->next;
	}}else if(first==NULL){
		cout<<"No record.\n";
	}else{
		cout<<first->val << endl;
	}
	cout<<"\n";
}

void Delete(){
	record *p=first,*k,*l;
	while(p->next!=NULL){
		k=p;
		p=p->next;
		//cout<<k->val<<" "<<p->val<<" "<<l->val<<endl;
		if(p->val+k->val < p->next->val){
			l=p->next;
			p->next=l->next;
			delete l;
		}
	}
	
	
}


int main(){
	insert(8);
	Delete();
	display();
	return 0;
}

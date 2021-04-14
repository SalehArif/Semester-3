//Name: Saleh Arif
//Reg Num: SP19-BCS-027

#include <iostream>
using namespace std;

void insert_circ(int num);
void insert(int num);
void display();
void print_r();
void reverse();
bool palindrome();
void swap_val(int x,int y);
void swap_l(int pos,int pos1);
void joseph(int num);

struct record{
	int val;
	record *next=NULL;
};
record *first=NULL;
record *last = NULL;

record* search(int x);

int main(){
	int opt,num,pos,pos1;
	do{
	cout<<"Enter 1 to Insert ";
	cout<<"\nEnter 2 to display ";
	cout<< "\nEnter 3 to print reverse ";
	cout<<"\nEnter 4 to reverse ";
	cout<<"\nEnter 5 to Check Palindrome ";
	cout<< "\nEnter 6 to swap value ";
	cout<< "\nEnter 7 to swap locations ";
	cout<< "\nEnter 8 for Josephus Problem ";
	cout<<"\nEnter 0 to exit ";
	cin>>opt;
	cout<<"\n";
	switch(opt){
		case 1: 
			cout<<"How many nodes: ";
			cin>>num;
			insert(num);
			break;
		case 2:
			display(); break;
		case 3:
			print_r();break;
		case 4:
			reverse();break;
		case 5:
			if(palindrome()){
				cout << "Is Palindrome\n"; 	
			}else{
				cout<<"Not Palindrome\n";
			}
			break;
		case 6:
			cout<<"Which values to swap: ";
			cin>>pos;
			cin>>pos1;
			swap_val(pos,pos1);break;
		case 7:
			cout<<"Which positions to swap: ";
			cin>>pos;
			cin>>pos1;
			swap_l(pos-1,pos1-1);break;
		case 8:
			cout<<"How many people to play with: ";
			cin>>pos;
			joseph(pos);break;
		case 0:
			cout<<"\nExiting....";
			break;
		default:
			cout<< "Invalid Option.";
		
	}	cout<<"\n";
	}while(opt!=0);
	return 0;
}

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

void insert_circ(int num){
	record *curr= new record;
	
	curr->val=num;
	if(last==NULL){
		last=curr;
		last->next = curr;
	}else{
		curr->next = last->next;
		last->next = curr;
		last = curr;
}
}

void display(){
	record *p=first;
	if(first!=last){
		cout<<"Value\tAddress" << "\n";
	while(p!=NULL){
		cout<<p->val <<"\t"<<p <<endl;
		p=p->next;
	}}else if(first==NULL){
		cout<<"No record.\n";
	}else{
		cout<<first->val << endl;
	}
	cout<<"\n";
}

void joseph(int num){
	for(int i=num;i>0;i--){
		insert_circ(i);
	}
	
	record *curr=last,*succ=last->next,*temp=NULL;
	while(num!=1){
		temp=curr;
		curr=curr->next->next;
		delete succ;
		temp->next=curr;
		succ=curr->next;
		num--;
	}
	cout<<"The winning position is "<<curr->val<<endl;
}

void print_r(){
	record *p= first,*k=last;
	if(first!=last){
	while(k!=first){
		p=first;
		while(true){
			if(p->next==k){
				k=p;
				p=p->next;
				break;
			}
			p=p->next;
		}
		cout<<p->val << endl;
	}	cout<<k->val<<endl;
	}else if(first==NULL){
		cout<<"NO record.\n";
	}else{
		cout<<last->val;
		cout<<"\n"<<first->val;
	}
	
}

void reverse(){
	
	if(first!=last){
	
	record *p=NULL,*k=last,*temp=first;	
	first=last; last=temp;
	
	while(k!=temp){
		p=temp;
		while(p->next!=k){
			p=p->next;
		}
		k->next=p;
		k=p;
		
	} last->next=NULL;
	}else if(first==NULL){
		cout<<"NO record.\n";
	}else{
		last->next=first;
		first->next=NULL;
	}
}

bool palindrome(){
	record *p=first, *k=first;
	int pos=0,count=0;
	while(p!=NULL){
		pos++;
		p=p->next;
	}
	p=first;
	for(int i=0;i<pos/2;i++){
		for(int j=0;i<=pos;j++){
			count++;
			if(count==pos-i){
				if(k->val!=p->val){
					return false;
				}
				break;
			}
			k=k->next;
		}
		k=first;
		count=0;
		p=p->next;
	}
	return true;
}


void swap_val(int x,int y){
	record *p = search(x), *k=search(y);
	int temp;
	if(p!=NULL && k!=NULL){
	temp=k->val;
	k->val=p->val;
	p->val=temp;
	}else{
		cout<<"One or both these values don't exist."<<endl;
	}
}

void swap_l(int pos,int pos1){
	
	record *p=first,*k=first,*temp=NULL,*tem=NULL;
	if(pos!=0 && pos1!=0){
	for(int i=1;i<pos;i++){
		p=p->next;
	}
	for(int i=1;i<pos1;i++){
		k=k->next;
	}
	
	temp=p->next;
	p->next=k->next;
	k->next=temp;
	tem = k->next->next;
	k->next->next=p->next->next;
	p->next->next=tem;
	}else if(first==NULL){
		cout<<"No nodes.";
	}else{
		if(pos==0){
			for(int i=1;i<pos1;i++){
				k=k->next;
			}
		}else if(pos1==0){
			for(int i=1;i<pos;i++){
				k=k->next;
			}
		}
		temp=k->next->next;
		tem=k->next;
		k->next->next=first->next;
		first->next=temp;
		k->next=first;
		first=tem;
	}
}

record * search(int x){
	record *p=first;
	while(p->val!=x && p!=NULL){
		p=p->next;
	}
	return p;
}

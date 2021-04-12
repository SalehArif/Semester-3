#include <iostream>
using namespace std;

struct rec{
	int num;
	rec *next=NULL;
};
rec *first=NULL;
rec *last=NULL;

void insert(int num){
	for(int i=0;i<num;i++){
	rec *p = new rec;
	cout<<"Enter marks: ";
	cin>>p->num;
	if(first==NULL){
		first=last=p;	
	}else{
		last->next=p;
		last=p;
	}
	}
}

void display(){
	rec *p=first;
	if(first!=last){
		cout<<"Value" << "\n";
	while(p!=NULL){
		cout<<p->num <<endl;
		p=p->next;
	}}else if(first==NULL){
		cout<<"No record.\n";
	}else{
		cout<<first->num << endl;
	}
	cout<<"\n";
}

void display(int a[],int len){
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";    
    }
    cout << "" << endl;
    
}

void swap_val(rec* p,rec* k){
	//record *p = search(x), *k=search(y);
	int temp;
	if(p!=NULL && k!=NULL){
	temp=k->num;
	k->num=p->num;
	p->num=temp;
	}else{
		cout<<"One or both these values don't exist."<<endl;
	}
}

//Linked List
void Bubb(){
	rec *p,*end=NULL;
	while(end!=first->next){
		p = first;
		while(p->next!=end){
			if(p->num > p->next->num){
				swap_val(p,p->next);
			}
			p=p->next;
		}
		end=p;
	}
}

void select(){
	rec *p =first,*k,*min;
	while(p->next!=NULL){
		k=p->next;
		min=p;
		while(k!=NULL){
			if(min->num > k->num){
				min=k;
			}
			k=k->next;
		}
		swap_val(p,min);
		p=p->next;
	}
}

void shift(rec *k,rec* p){
	if(p==k){
		return;
	}else{
		shift(k,p->next);
		p->next->num=p->num;
		//p=p->next;
	}
}

rec* search(rec *k){
	int temp = k->num;
	rec *p=first;
	while(p->next!=k){
		if(k->num<p->num){
			break;
		}
		p=p->next;
	}
	shift(k,p);
	p->num=temp;
	return p;
}

void insertion(){
	rec *p=first->next,*k=first,*save;
	
	while(p!=NULL){
		save=p;
		if(save->num<k->num){
			search(save);
			//k->num=save->num;
		}
		
		k=p;
		p=p->next;
	}
}

//Array
void Bubble(int a[], int len){
	int temp;
	for(int i=0;i<len-1;i++){
		for(int j=0;j<len-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}	
}

void Selection(int a[], int len){
	int temp,min;
	for(int i=0;i<len-1;i++){
		min=i;
		for(int j=i+1;j<len;j++){
			if(a[j]<a[min]){
				min=j;
			}
	}
	temp =a[i];
	a[i]=a[min];
	a[min]=temp;
	}
}

void InsertionSort(int a[],int len){
	int j,temp;
	
	for(int i=1;i<len;i++){
		j=i-1;temp=a[i];
	
		while(j>=0 && temp<a[j]){
			a[j+1]=a[j];
			j--;
	}
	a[j+1]=temp;
	}
}

void merge(int a[],int first,int mid,int last){
	int firstA=first, lastA=mid, firstB=mid+1, lastB=last, i=first;
	int temp[last+1];	
	while(firstA<=lastA && firstB<=lastB){
		if(a[firstA]<a[firstB]){
			temp[i]=a[firstA];
			firstA++;
		}else{
			temp[i]=a[firstB];
			firstB++;
		}
		i++;
	}
	while(firstA<=lastA){
		temp[i]=a[firstA];
		firstA++;
		i++;
	}
	while(firstB<=lastB){
		temp[i]=a[firstB];
		firstB++;
		i++;
	}
	
	i=first;
	while(i<=last){
		a[i]=temp[i];
		i++;
	}
}

void mergeDiv(int a[],int first,int last){
	int mid;
	if(first<last){
		mid = (first+last)/2;
		mergeDiv(a,first,mid);
		mergeDiv(a,mid+1,last);
		merge(a,first,mid,last);
		
	}
	
}

//Recursive
void BubbleR(int a[],int i,int j,int size){
	
	if(i==size-1){
		return;
	}
	else{
		//int j=0;
		//BubbleR1(a,i,j);
		int temp;
		if(j==size-i-1){
		return;
		}else{
		if(a[j]>a[j+1]){
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
		BubbleR(a,i,j+1,size);
	}
	BubbleR(a,i+1,0,size);
	}
}

void select(int a[], int i,int j,int size){
	int min,temp;
	if(i==size){
		return;
	}else{
		min=i;
		if(j==size){
			return;
		}else{
			if(a[j]<a[min]){
				min=j;
			}
			select(a,i,j+1,size);
		}
		temp = a[i];
		a[i]=a[min];
		a[min]=temp;
		select(a,i+1,i+1,size);
	}
}

void shift(int a[],int min,int i){
	if(min==i){
		return;
	}else{
		shift(a,min+1,i);
		a[min+1]=a[min];
	}
}

int search(int a[],int i,int j){
	int min;
	if(j==i){
		return min;
	}else{
		if(a[i]<a[j]){
			min=j;
			shift(a,min,i);
			return min;
		}
		search(a,i,j+1);
	}
}

void insertion(int a[],int i,int j,int size){
	int temp;
	if(i==size){
		return;
	}else{
		temp=a[i];
		if(temp<a[j]){
			j=search(a,i,0);
			a[j]=temp;
		}
		j=i;
		insertion(a,i+1,j,size);
	}	
}

int main(){
	int opt,num,len,*a;
	do{
		cout<<"Enter 1 to Insert in Linked List ";
		cout<<"\nEnter 2 to Insert in Array ";
		cout<<"\nEnter 3 to Bubble sort in Array ";
		cout<<"\nEnter 4 to Selection sort in Array ";
		cout<<"\nEnter 5 to Insertion sort in Array ";
		cout<<"\nEnter 6 to Merge sort in Array ";
		cout<<"\nEnter 7 to Bubble sort recursively ";
		cout<<"\nEnter 8 to Selection sort recursively ";
		cout<<"\nEnter 9 to Insertion sort recursively ";
		cout<<"\nEnter 10 to Bubble sort in Linked List ";
		cout<<"\nEnter 11 to Selection sort in Linked List ";
		cout<<"\nEnter 12 to Insertion sort in Linked List ";
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
			cout<<"Length of Array: ";cin>>len;
			a= new int[len];
			for(int i=0;i<len;i++){
				cout<<"Enter Value: ";cin>>a[i];
			}
			break;
		case 3:
			Bubble(a,len);display(a,len);
			break;
		case 4:
			Selection(a,len);display(a,len);
			break;
		case 5:
			InsertionSort(a,len);display(a,len);
			break;
		case 6:
			mergeDiv(a,0,len-1);display(a,len);		
			break;
		case 7:
			BubbleR(a,0,0,len);display(a,len);
			break;
		case 8:
			select(a,0,1,len);display(a,len);	
			break;
		case 9:
			insertion(a,1,0,len);display(a,len);
			break;
		case 10:
			Bubb();display();
			break;
		case 11:
			select();display();
			break;
		case 12:
			insertion();display();
			break;
		case 0:
			cout<<"\nExiting....";
			break;
		default:
			cout<< "Invalid Option.";
	}cout<<"\n\n";
	}while(opt!=0);
	
	
	return 0;
}

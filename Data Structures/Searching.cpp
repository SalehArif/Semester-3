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

void sort(int a[],int length){
	int temp;
	for(int i=0;i<length-1;i++){
		for(int j=i+1;j<length;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;	
			}
		}
	}
}

int bi_search(int a[],int val,int start,int end){
	int mid = (start+end)/2;
	if(a[mid]==val){
		return mid;
	}else if(start>end){
		return -1;
	}else{
		if(val>a[mid]){
			bi_search(a,val,mid+1,end);
		}else{
			bi_search(a,val,start,mid-1);
		}
	}
}

int bin_search(int a[], int val, int start,int length){
	int si = start; int li = length-1;
	int mid = (si+li)/2;
	while(si<=li && a[mid]!=val){
		if(a[mid]>val){
			li=mid-1;
		}else{
			si=mid+1;
		}mid = (si+li)/2;
	}
	if(a[mid]==val){
		return mid;	
	}else{
		return -1;
	}
}

int search(int a[],int val,int start,int length){
	if(a[start]==val){
		return start;
	}else if(start==length-1){
		return -1;
	}else{
		search(a,val,start+1,length);
	}
}

int l_search(rec *first,int val,int pos){
	rec *p=first;
	pos++;
	if(p->num==val){
		return pos;
	}else if(p->next==NULL){
		return -1;
	}else{
		l_search(p->next,val,pos);
	}
}


int main(){
	int opt,num,val,length,*a,ans;
	do{
		cout<<"Enter 1 to Insert in Linked List ";
		cout<<"\nEnter 2 to Insert in Array ";
		cout<<"\nEnter 3 to Linear Search in Array ";
		cout<<"\nEnter 4 to Linear Search in Linked List ";
		cout<<"\nEnter 5 to Binary Search recursively ";
		cout<<"\nEnter 6 to Binary Search ";
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
			cout<<"Length of Array: ";cin>>length;
			a= new int[length];
			for(int i=0;i<length;i++){
				cout<<"Enter Value: ";cin>>a[i];
			}
			break;
		case 3:
			cout<<"Enter value to search: ";cin>>val;
			ans = search(a,val,0,length);
			if(ans!=-1){
				cout<<"Value is Found at index "<<ans;
			}else{
				cout<<"Value is Not Found.";
			}
			break;
		case 4:
			cout<<"Enter value to search: ";cin>>val;
			ans=l_search(first,val,-1);
			if(ans!=-1){
				cout<<"Value is Found at Position "<<ans;
			}else{
				cout<<"Value is Not Found.";
			}
			break;
		case 5:
			cout<<"Enter value to search: ";cin>>val;
			sort(a,length);
			ans = bi_search(a,val,0,length);
			if(ans!=-1){
				cout<<"Value is Found at index "<<ans;
			}else{
				cout<<"Value is Not Found.";
			}
			break;
		case 6:
			cout<<"Enter value to search: ";cin>>val;
			sort(a,length);
			ans = bin_search(a,val,0,length);
			if(ans!=-1){
				cout<<"Value is Found at index "<<ans;
			}else{
				cout<<"Value is Not Found.";
			}
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


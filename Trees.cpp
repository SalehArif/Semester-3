//SP19-BCS-027
//Saleh Arif

#include <iostream>
using namespace std;

struct tree{
	tree *left=NULL;
	tree *right=NULL;
	int data;
};tree *root =NULL;

void insert(int x){
	tree *p = new tree;
	p->data=x;
	tree *k,*k1;
	if(root==NULL){
		root=p;
	}else{
		k=root;
		
		while(k!=NULL){
			k1=k;
			if(p->data>=k->data){
				k=k->right;
			}else{
				k=k->left;
			}
		}
		
		if(p->data>=k1->data){
			k1->right=p;
		}else{
			k1->left=p;
		}
		
	}


}

void preorder(tree *p){
	if(p!=NULL){
		cout<<p->data<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}

void inorder(tree *p){
	if(p!=NULL){
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}
}

void postorder(tree *p){
	if(p!=NULL){
		postorder(p->left);
		postorder(p->right);
		cout<<p->data<<" ";
	}
}

tree* search(int a){
	tree *p=root;
	while(p!=NULL && p->data!=a){
		if(a>=p->data){
				p=p->right;
			}else{
				p=p->left;
			}
	}
	
	return p;
}

void Delete(int a){
	tree *p= search(a),*p1=root,*z;
	
	if(p==root){
		if(p->left==NULL){
			root=p->right;
			delete p;
		}else if(p->right==NULL){
			root=p->left;
			delete p;
		}else{
			p=p->right;
			if(p->left==NULL){
				
				root->data=p->data;
				root->right=p->right;
				delete p;
			}else{
				
			while(p->left!=NULL){
				p1=p;
				p=p->left;
			}
			root->data=p->data;
			
			if(p->right!=NULL){
				p1->left=p->right;
			}else{
				p1->left=NULL;	
			}
			
			delete p;
		}
		
		}
	}
	
	else{
	while(p1->left!=p && p1->right!=p){  // finding previous node than deleting
		if(p->data>=p1->data){
			p1=p1->right;
		}else{
			p1=p1->left;
		}
	}
	
	if(p->left==NULL && p->right==NULL){ //leaf node
		if(p1->left==p){
			p1->left=NULL;
		}else{
			p1->right=NULL;
		}
		delete p;
		
	}else if(p->left==NULL || p->right==NULL){ // one branch
		if(p1->left==p && p->left!=NULL){
			p1->left=p->left;
		}else if(p1->left==p && p->left==NULL){
			p1->left=p->right;
		}else if(p1->right==p && p->right!=NULL){
			p1->right=p->right;
		}else if(p1->right==p && p->right==NULL){
			p1->right=p->left;
		}
		delete p;
	}else if (p->left!=NULL && p->right!=NULL){ //two branch
		
		z=p->right;
		while(z->left!=NULL){
			p1=z;
			z=z->left;
		}
		p->data=z->data;
		if(z->right!=NULL){
			p1->left=z->right;
		}
		if(p1->left==z){
			p1->left=NULL;
		}
		delete z;
	}
}
	
}

int Min(tree* p,int min){
	if(p!=NULL){
		if(p->data<min){
			min=p->data;
		}
		Min(p->left,min);
	}else{
		return min;
	}
}

int Max(tree* p,int max){
	if(p!=NULL){
		if(p->data>max){
			max=p->data;
		}
		Max(p->right,max);
	}else{
		return max;
	}
}

int main(){
	int opt,num,val;
	do{
		cout<<"Enter 1 to Insert";
		cout<<"\nEnter 2 For Preorder";
		cout<<"\nEnter 3 For Postorder";
		cout<<"\nEnter 4 For Inorder";
		cout<<"\nEnter 5 to Delete";
		cout<<"\nEnter 6 to Search ";
		cout<<"\nEnter 7 to Find Minimum ";
		cout<<"\nEnter 8 to Find Maximum ";
		cout<<"\nEnter 0 to Exit ";
		cin>>opt;
		cout<<"\n";
	switch(opt){
		case 1: 
			cout<<"How many nodes: ";
			cin>>num;
			for(int i=0;i<num;i++){
				cout<<"Insert Value: ";
				cin>>val;
				insert(val);
			}
			break;
		case 2:
			preorder(root);
			break;
		case 3:
			postorder(root);
			break;
		case 4:
			inorder(root);
			break;
		case 5:
			cout<<"Enter Value to Delete: ";cin>>val;
			Delete(val);
			break;
		case 6:
			cout<<"Enter Value to Search: ";cin>>val;
			if(search(val)==NULL){
				cout<<"Value not found.";
			}else{
				cout<<"Value found.";
			}
			break;
		case 7:
			cout<<"\nMin value: "<<Min(root,10);
			break;
		case 8:
			cout<<"\nMax value: "<<Max(root,0);
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

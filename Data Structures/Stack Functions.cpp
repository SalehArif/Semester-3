#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Stack{
	private:
		string *num;
		int size;
		int top;
	public:
		Stack(){
			size=5;
			top=-1;
			num = new string[5];
		}
		Stack(int s){
			size=s;
			top=-1;
			num = new string[s];
		}
		void push(){
			string val;
			if(isFull()){
				cout<<"Stack is full\n";
			}
			else{
				cout<<"Enter element: ";
				cin>>val;
				num[++top] = val;
			}
		}
		
		void push(string s){
			if(isFull()){
				cout<<"Stack is full\n";
			}
			else{
				num[++top] = s;	
			}
		}
		string pop(){
			if(isEmpty()){
				cout<<"No elements"<<endl;
				return NULL;
			}
			else{
				return num[top--];
			}
		}
		
		string peek(){
			if(isEmpty()){
				cout<<"No elements"<<endl;
				return NULL;
			}
			else{
				return num[top];
			}
		}
		
		void display(){
			cout<< "Stack is: ";
			for(int i=top;i>=0;i--){
				cout<<num[i];
			}
		}
		
		bool isFull(){
			if(top==size-1){
				return true;
			}else{
				return false;
			}
		}
		
		bool isEmpty(){
			if(top==-1){
				return true;
			}else{
				return false;
			}
		}
		
		bool balance(string s){
			string s2;
			for(string::size_type i=0;i<s.length();i++){
				s2=s[i];
				if(bropen(s2)){
					(*this).push(s2);
				}
				else if(brclose(s2)){
					if(s2==")" && peek()=="("){
						(*this).pop();	
					}else if(s2=="}" && peek()=="{"){
						(*this).pop();	
					}else if(s2=="]" && peek()=="["){
						(*this).pop();
					}
					
				}
			}
			if(isEmpty()){
				return true;	
			}else{
				while(!isEmpty()){
					pop();
				}
				return false;
			}
		}
		
		string postfix(string s){
			string s1,s2;
			for(string::size_type i=0;i<s.length();i++){
				s2=s[i];
				if(ispunct(s[i])){
					if(isEmpty() || bropen(s2) ||compare(s2,peek())){
						push(s2);
					}else if(brclose(s2)){
						while(!bropen(peek())){
							s1+=pop();
						}
						pop();
					}else{
						while(!isEmpty() && !compare(s2,peek())){
							s1+=pop();
						}
						push(s2);
					}
				}else{
					s1+=s[i];
				}
				
			}
			while(!isEmpty()){
				if( bropen(peek()) || brclose(peek())){
					pop();
				}else{
				s1+=pop();
				}
			}
			return s1;
		}
		
		int precedence(string a){
			if(a=="*"|| a=="/" || a=="%"){
				return 1;
			}else{
				return 0;
			}	
		}
		
		int eval(string s){
			int ans=0,s0,s1;
			string s2;
			for(string::size_type i=0;i<s.length();i++){
				s2=s[i];
				if(isdigit(s[i])){
					push(s2);
				}else{
					s0=to_int(pop());
					//cout<<s1<<s2<< " "<<s0<<" = ";
					s1=to_int(pop());
					
					if(s[i]=='*'){
						ans=s1*s0;
					}else if(s[i]=='+'){
						ans=s1+s0;
					}else if(s[i]=='-'){
						ans=s1-s0;
					}else if(s[i]=='/'){
						ans=s1/s0;	
					}else{
						ans=s1%s0;	
					} 
					if(i<s.length()-1){
						push(to_string(ans));
					//	cout<<ans<<endl;
					}
				}
			}
			return ans;
		}
		
		bool compare(string a,string b){
			if(precedence(a)>precedence(b) || bropen(b)){
				return true;
			}else{
				return false;
			}
		}
		bool brclose(string s){
			if(s==")"|| s=="}"|| s=="]"){
				return true;
			}
			return false;
		}
		bool bropen(string s){
		if(s=="(" || s=="{" || s=="["){
				return true;
			}
			return false;
		}
		int to_int(string a){
			int s0;
			stringstream num1(a);
			num1>>s0;
			//stringstream num2(pop());
			//num2>>s1;
			return s0;
		}
		string to_string(int a){
			string s;
			stringstream num1;
			num1<<a;
			num1>>s;
			return s;
		}
};

int main(){
	Stack s1;
	Stack s2(20);
	int opt;
	string bal="5-1+(2*3)";
	
	do{
		cout<<"\nEnter 1 to push: ";
		cout<<"\nEnter 2 to pop: ";
		cout<<"\nEnter 3 to display: ";
		cout<<"\nEnter 4 to Check if Balanced: ";
		cout<<"\nEnter 5 to Change into Postfix: ";
		cout<<"\nEnter 6 to Evaluate Postfix Expression: ";
		cout<<"\nEnter 0 to exit: ";
		cin>>opt;
		
		switch(opt){
			case 0:cout<<"exiting";break;
			case 1: s1.push();break;
			case 2: cout<<"Popped value: "<<s1.pop()<<endl;break;
			case 3: s2.display();break;
			case 4: cout<<"\nEnter an expression: ";
					cin>>bal;
					if(s2.balance(bal)){
						cout<<"Balanced.";
					}else{
						cout<<"Unbalanced Expression.";
					}
					break;
			case 5:
					cout<<"\nEnter an expression: ";
					cin>>bal;
					if(s2.balance(bal)){
						cout<<s2.postfix(bal);
					}else{
						cout<<"Unbalanced Expression.";
					}
					break;
			case 6:
					cout<<"\nEnter an expression: ";
					cin>>bal;
					if(s2.balance(bal)){
						cout<< s2.eval(s2.postfix(bal));
					}else{
						cout<<"Unbalanced Expression.";
					}
					break;
			default: cout<<"Invalid option";
		}
	}while(opt!=0);
	
	return 0;
}

#include <iostream>

using namespace std;

class Que{
	private:
		int front,rear,size;
		int *arr;
	public:
		Que(){
			size=5;
			front=rear=-1;
			arr = new int[5];
		}
		Que(int a){
			size=a;
			front=rear=-1;
			arr = new int[a];
		}
		void Enque(int a){
			if(!isFull()){
			if(isEmpty()){
				front=rear=0;
			}else{
				rear++;
			}
			arr[rear]=a;
			}else{
				cout<<"Full\n";
			}
		}
		void Deque(){
			if(!isEmpty()){
				front++;
			}else{
				cout<<"empty";
			}
		}
		int Front(){
			if(!isEmpty()){
			return arr[front];
		}else{
			cout<<"empty";
			return -1;
		}
		
		}
		bool isFull(){
			if(rear==size-1){
				return true;
			}else{
				return false;
			}
		}
		
		bool isEmpty(){
			if(front==-1){
				return true;
			}else{
				return false;
			}
		}
	void display(){
		if(isEmpty()){
			return;
		}else{
			for(int i=front;i<=rear;i++){
				cout<<arr[i]<<" ";
			}
		}
	}
};


int main(){
	
	Que s;
	//int x; cout<<"N";cin>>x;
	for(int i=1;i<=5;i++){
		s.Enque(i);
	}
	s.display();
	s.Deque();s.Deque();
	s.Enque(9); 
	s.display();
return 0;}

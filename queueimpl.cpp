#include<iostream>
using namespace std;
class queue{
	int *arr;
	int cs;
	int ms;
	int front;
	int rear;
	
public:
	queue(int defaultsize =7){
		ms = defaultsize;
		cs =0;
		arr =  new int[ms];
		front =0;
		rear = -1;
		
	}
	
	bool isfull(){
		return cs == ms;
	}
	
	bool isempty(){
		return cs==0;
	}
	
	void push(int element){
		if(isfull()){
			cout<<"queue is full"<<endl;
			return;
		}
		rear = (rear+1)% ms;
		arr[rear] = element;
		cs++;
		
	}
	
	void pop(){
		if(isempty()){
			cout<<"queue is empty"<<endl;
			return;
		}
		front = (front+1)% ms;
		cs--; 
	}
	int getfront(){
		if(isempty()){
			cout<<"queue is empty"<<endl;
			return -1;
		}
		return arr[front];
		
		
	}
};
int main(){
	queue q(10);
	for(int i=1; i<7; i++){
		q.push(i);
	}
	q.pop();
	q.push(11);
	while(!q.isempty()){
		cout<<q.getfront()<<" ";
		q.pop();
	}
	
	return 0;
}

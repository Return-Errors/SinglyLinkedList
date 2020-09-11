#include<iostream>
using namespace std;

class SinglyLinkedList{
private:
struct node{
	int item;
	node*next;
};
	node *first,*last;
	int length;
public:

	LinkedList(){ // Constractor
	first = last = NULL;
	length = 0;
	}
	
	//-----------------------------------------------------------------------	
	void insertFirst(int element){
		node *newNode = new node;
		newNode->item = element;
		if (length == 0){
			first = last = newNode;
			newNode->next = NULL;
		}
		else{
			newNode->next = first;
			first = newNode;
		}
		length++;
	}
	
	//------------------------------------------------------------------------	
	void insertLast(int element){
		node*newNode = new node;
		newNode->item = element;
		if(length == 0){
			first = last = newNode;
			newNode->next = NULL;
		}
		else{
			last->next = newNode;
			last = newNode;

		}
		length++;
	}

	//--------------------------------------------------------------------------	
	void insertAtPos(int pos, int element){
		if(pos < 0 || pos > length)
			cout<<"Error: Out of range"<<endl;
		else{
			node* newNode = new node;
			newNode->item = element;
			if(pos == 0)
				insertFirst(element);
			else if(pos == length)
				insertLast(element);
			else{
				node *curr = first;
				for(int i = 1;i<pos;i++)
					curr = curr->next;
				newNode->next = curr->next;
				curr->next = newNode;
				length++;
			}
				
		}
			
	}
	
	void removeFirst(){
		if (length == 0)
			cout<<"LinkedList is empty"<<endl;
		else if (length == 1){
			delete first;
			first = last = NULL;
		} else {
			node*current = first;
			first = first ->next;
			delete current;
		}
		length--;
	}
//--------------------------------------------------------------------------------------	
	void removeLast(){
		if(length == 0)
			cout<<"LinkedList is empty"<<endl;
		else if(length == 1){
			delete first;
			first = last = nullptr;
		}else{
			node *temp = first;
			node *tailTemp = NULL;
			while(temp != last){
				tailTemp = temp;
				temp = temp->next;
			}
			
			delete temp;
			tailTemp ->next = NULL;
			last = tailTemp;
		}
		length--;
	}
//-----------------------------------------------------------------------------------
	void removeAtPos(int loc){
		if(loc < 0 || loc > length)
			cout<<"Out of the range"<<endl;
		else if(loc == 1)
			removeFirst();
		else if (loc == length)
			removeLast();
		else
		{
			node *current = first;
			node *trailCurr = NULL;
			for(int i = 1 ;i<loc;i++){
				trailCurr = current;
				current = current->next; 
			}
			
			trailCurr ->next = current->next;
			delete current;
		}
		length--;
	
	}
//-----------------------------------------------------------------------------------	
	void print(){
		node*temp = first;
		while(temp != NULL){
			cout<<temp->item<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
};	
//-----------------------------------------------------------------------------------------

	
int main(){
SinglyLinkedList sl;
sl.insertFirst(4);
sl.insertFirst(12);
sl.insertLast(6);
sl.insertFirst(8);
sl.insertAtPos(2,3);
sl.removeAtPos(1);
sl.print();
}










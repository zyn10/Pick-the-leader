#include<iostream>
#include<string>
#include<string.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;    
struct Node            //------>patient credentials node
{
    Node* next;
    Node* prev;
    string name;  
    int age;
    int ID;
};
Node *head=NULL;
Node *tail=NULL;
class Leader
{ int length;
public:
Leader()
    {
        length = 1;
    }
	void circularInsert(string Name,int a,int id)
    {   Node* newNode = new Node;
        newNode->name = Name;//----->credentials
        newNode->age=a;
        newNode->ID=id;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL){
            head = newNode;
            tail = newNode; 
            newNode->next=head;
            newNode->next=head;//new node k wapis apnay ap ko point kray ge
           
		}
        else 
        {   tail->next=newNode;
            tail->next->prev=tail;     //agli node k prev ma pahli node ka address
            tail->next->next=head;    //new node k next ma  head node ka address
            tail=tail->next;         //tail ko agli node pa move krna we can sa current 
            head->prev=tail;
        }
    length++;
    
    cout<<"Added successfully "<<endl;//<<newNode->name<<endl;
    
   }
	
bool isEmpty() const
{
	if(head==NULL)
	{
		return true;
	}
	return false;
}
void Display()
    {
	    if(isEmpty())
		{
			cout<<"No data found "<<endl;
		}
		else
		{
        Node* temp= head;
        cout<<"Name\t\t\tAge\t\t\tID"<<endl;
        while (temp->next != head){
		cout<<temp->name<<"\t\t\t"<<temp->age <<"\t\t\t"<<temp->ID  <<endl; 
		temp = temp->next;
        } 
			cout<<temp->name<<"\t\t\t"<<temp->age <<"\t\t\t"<<temp->ID  <<endl; 
         }
    }

void Delete(int m)
{   
    Node* temp=head;
    while(temp->next!=head&&temp->prev!=head)
    {
    for(int i=1;i<m+1;i++)
    {
    	temp=temp->next;
	}
	    tail=temp->next;
    	temp->next=tail->next;
    	tail->next->prev=temp;
    	head->prev=tail;
		--length;
		return;
	}
}

};

    int main()
    {srand(time(0));
    	Leader obj;
    	string name;
    	int age;
    	int id;
    	cout<<"Enter the number of employees you want to enter "<<endl;
    	int n;cin>>n;
    	for(int i=0;i<n;i++)
    	{id=rand()%100;
    		cout<<"Input the Credentials of "<<i+1<<" employee"<<endl;
    		cout<<"Enter Name       ";cin>>name;
    		cout<<"Enter Age        ";cin>>age;
    		cout<<"Unique Id auto   "<<id<<endl;
			obj.circularInsert(name,age,id);
		}
		int m;
    	obj.Display();
    	for(int i=0;i<n-1;i++)
    	{
    		cout<<"Enter m to traverse the loop to delete"<<endl;
    		cin>>m;
    		obj.Delete(m);
    		obj.Display();
    		if(i==n-2)
    		{
    			cout<<"Leader Selected"<<endl;
			obj.Display();
			}
		}
    //	obj.Delete(4);
    //	obj.Display();
    	return 0;
	}

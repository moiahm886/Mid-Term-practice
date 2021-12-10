#include<iostream>
#include<string>
#include<set>
#include<unordered_set>
using namespace std;
struct Node
{
	int data;
	Node* Next;
};
class List
{
private:
	Node* head;
public:
	List()
	{
		head = NULL;
	}
	void insertatbeginning(Node *N,int val)
	{
		N = new Node();
		if (head == NULL)
		{
			N->data = val;
			N->Next = NULL;
			head = N;
		}
		else
		{
			N->data = val;
			N->Next = head;
			head = N;
		}
	}
	void insertatend(Node* N, int val)
	{
		N = new Node();
		Node* M = head;
		if (head == NULL)
		{
			insertatbeginning(N, val);
		}
		else
		{
			while (M->Next!= NULL)
			{
				M = M->Next;
			}
			N->data = val;
			N->Next = NULL;
			M->Next = N;
		}
	}
	void insertinbetween(Node* N, int val, int search)
	{
		int count = 0;
		N = new Node();
		Node* M = head;
		while (M!=NULL)
		{
			if (M->data == search)
			{
				count++;
				break;
			}
			M = M->Next;
		}
		if (count == 0)
		{
			cout << "The integer not found\n";
		}
		else
		{
			N->data = val;
			N->Next = M->Next;
			M->Next = N;
		}
	}
	void deleteatbeginning()
	{
		Node* N = head;
		head = head->Next;
		delete N;
	}
	void deleteatend()
	{
		Node* N = head;
		Node* pre = nullptr;
		while (N->Next != NULL)
		{
			pre = N;
			N = N->Next;
		}
		pre->Next = NULL;
		free(N);
	}
	void displayreverse()
	{
		Node* N = head;
		set<int>st;
		while (N != NULL)
		{
			st.insert(N->data);
			N = N->Next;
		}
		for (auto it = st.begin(); it != st.end(); it++)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}
	void deleteduplicate()
	{
		if (head == NULL) {

			cout << "List is Empty\n";

		}
		else {

			unordered_set<int>list;
			Node* current = head;
			Node* previous = head;
			int index = 0;
			while (current != NULL) 
			{
				if (list.find(current->data) != list.end()) 
				{
					previous->Next = current->Next;
					delete (current);
				}
				else
				{
					list.insert(current->data);
					previous = current;
				}
				current = previous->Next;
			}

		}
	}
	void display()
	{
		Node* N = head;
		while (N != NULL)
		{
			cout << N->data << "\t";
			N = N->Next;
		}
		cout << endl;
	}
};
int main()
{ 
	Node* N{};
	List l;
	l.insertatend(N, 49);
	l.insertatbeginning(N, 98);
	l.insertatbeginning(N, 67);
	l.insertinbetween(N, 72, 98);
	l.display();
	l.deleteatbeginning();
	l.display();
	l.displayreverse();
	l.deleteatend();
	l.display();
}
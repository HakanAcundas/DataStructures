#include "utils.h"

struct Node
{
	int value;
	Node* next;
	Node* previous;
};

class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void Insert(int value);
	void Insert(int index, int value);
	void Delete(int index, int value);

	void Print(bool isReverse);

private:
	Node* head;
	Node* tail;
};

DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

void DoublyLinkedList::Insert(int value) 
{
	Node* temp = new Node();
	temp->value = value;
	temp->next = nullptr;
	temp->previous = nullptr;

	if (head == nullptr)
		head = temp;
	else
	{
		Node* traverse = head;
		while (traverse->next != nullptr)
		{
			traverse->next->previous = traverse;
			traverse = traverse->next;
		}
		traverse->next = temp;
		temp->previous = traverse;
		tail = temp;
	}
}

void DoublyLinkedList::Print(bool isReverse)
{
	
	if (!isReverse)
	{
		Node* traverse = head;
		while (traverse != nullptr)
		{
			std::cout << "-->" << traverse->value;
			traverse = traverse->next;
		}
	}
	else
	{
		Node* traverse = tail;
		while (traverse != nullptr)
		{
			std::cout << "-->" << traverse->value;
			traverse = traverse->previous;
		}
	}
}

int main()
{
	DoublyLinkedList dbl;
	dbl.Insert(69);
	dbl.Insert(2);
	dbl.Insert(2);
	dbl.Insert(31);

	dbl.Print(true);
}

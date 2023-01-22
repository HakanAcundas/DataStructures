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
	void Delete(int index);

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

void DoublyLinkedList::Insert(int index, int value)
{
	Node* temp = new Node();
	temp->value = value;
	temp->next = nullptr;
	temp->previous = nullptr;

	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		Node* traverse = head;
		for (int i = 0; i <= index - 2; i++)
		{
			if (traverse->next != nullptr)
			{
				traverse = traverse->next;
			}
		}
		if (traverse->next == nullptr)
		{
			std::cout << "Index out of bound range for linked list!" << std::endl;
		}
		else 
		{
			temp->previous = traverse;
			temp->next = traverse->next;
			traverse->next->previous = temp;
			traverse->next = temp;
		}
		
	}
}

void DoublyLinkedList::Delete(int index)
{
	Node* traverse = head;
	if (index == 0 && traverse->next != nullptr)
	{
		head = head->next;
		return;
	}

	for (int i = 0; i <= index - 2; i++)
	{
		if (traverse->next->next == nullptr)
		{
			std::cout << "Please enter a valid number!" << std::endl;
			return;
		}
		traverse = traverse->next;
	}
	if (traverse->next == nullptr)
	{
		std::cout << "Please enter a valid number!" << std::endl;
		return;
	}
	else
	{
		traverse->next->previous = traverse;
		traverse->next = traverse->next->next;
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
	dbl.Insert(21);


	dbl.Insert(2, 100);
	dbl.Insert(2, 99);

	dbl.Delete(3);

	dbl.Print(false);
}

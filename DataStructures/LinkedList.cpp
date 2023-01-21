#include <iostream>

struct Node {
	int data;
	Node* next;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void Insert(int value);
	void InsertIndex(int index, int value);
	void Delete(int index);
	void Print();

	Node* getHead();
	void setHead(Node* nodeptr);

private:
	Node* head;
};

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList()
{
}

void LinkedList::Insert(int value)
{
	Node* temp = new Node();
	temp->data = value;
	temp->next = NULL;

	if (head == nullptr) 
	{
		head = temp;
	}
	else 
	{
		Node* traverseNode = head;
		while (traverseNode->next != nullptr)
		{
			traverseNode = traverseNode->next;
		}
		traverseNode->next = temp;
	}
}

void LinkedList::InsertIndex(int index, int value)
{
	Node* temp = new Node();
	temp->data = value;
	temp->next = NULL;

	if (index == 0)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		Node* traverseNode = head;
		for (int i = 0; i <= index - 2; i++)
		{
			if (traverseNode->next == nullptr)
			{
				std::cout << "Please enter a valid number!" << std::endl;
				return;
			}
			traverseNode = traverseNode->next;
		}
		temp->next = traverseNode->next;
		traverseNode->next = temp;
	}
}

void LinkedList::Delete(int index)
{
	if (index == 0 && head->next !=nullptr)
	{
		head = head->next;
	}
	Node* traverseNode = head;
	for (int i = 0; i <= index - 2; i++)
	{
		if (traverseNode->next == nullptr || traverseNode->next->next == nullptr)
		{
			std::cout << "Please enter a valid number!" << std::endl;
			return;
		}
		traverseNode = traverseNode->next;
	}
	traverseNode->next = traverseNode->next->next;
}

void LinkedList::Print()
{
	Node* traverse = head;
	while (traverse != nullptr)
	{
		std::cout <<"-->"<< traverse->data;
		traverse = traverse->next;
	}
}

Node* LinkedList::getHead()
{
	return head;
}

void LinkedList::setHead(Node* nodeptr)
{
	head = nodeptr;
}

//int main()
//{
//	LinkedList ls;
//	ls.Insert(1);
//	ls.Insert(2);
//	ls.Insert(0);
//	ls.Insert(-1);
//
//	ls.InsertIndex(1, 55);
//
//	ls.Delete(1);
//
//	ls.Print();
//}


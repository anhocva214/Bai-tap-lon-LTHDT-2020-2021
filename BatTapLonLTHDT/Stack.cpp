#include "Stack.h"

Stack::Stack()
{
	Top = NULL;
}

Stack::~Stack()
{
	while (!IsEmpty())
	{
		Node* p = Top;
		Top = p->Next;
		delete p;
	}
}

int Stack::IsEmpty()
{
	if (Top == NULL)
		return 1;
	else return 0;
}

Node* Stack::newNode(Data x)
{
	Node* n = new Node();
	n->Info = x;
	n->Next = NULL;
	return n;
}

void Stack::Push(Data x)
{
	Node* n = newNode(x);
	if (IsEmpty())
	{
		Top = n;
	}
	else
	{
		n->Next = Top;
		Top = n;
	}
}

int Stack::Pop(Data& x)
{
	if (IsEmpty())
	{
		return 0;
	}
	else
	{
		Node* n = Top;
		x = n->Info;
		Top = n->Next;
		delete n;
	}
	return 1;
}

Node* Stack::GetTop()
{
	return Top;
}

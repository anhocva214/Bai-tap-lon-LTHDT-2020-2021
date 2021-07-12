#include <stdio.h>
#include <string>


using namespace std;

typedef string Data;
class Node
{
public:
	Data Info;
	Node* Next;
};


class Stack
{
private:
	Node* Top;
public:
	Stack();
	~Stack();
	int IsEmpty();
	Node* newNode(Data x);
	void Push(Data x);
	int Pop(Data& x);
	Node* GetTop();
};
#include "�ҽ�.h"
using namespace std;

//����
//����ü
//struct Point
//{
//	int Data;
//	Point* link;
//};
//
//void push(Point** top, int Data)
//{
//	Point* newNode = new Point;
//
//	newNode->link = *top;
//	newNode->Data = Data;
//	*top = newNode;
//
//	cout << newNode->link << endl;
//	cout << newNode << endl << endl;
//}
//
//void pop(Point** top)
//{
//	Point *tmp;
//	tmp = *top;
//	*top = tmp->link;
//
//	cout << tmp->Data << endl << endl;
//	delete tmp;
//}
//
//void main()
//{
//	Point *point = NULL, *tmp;
//	
//	cout << point << endl << endl;
//	
//	push(&point, 10);
//	push(&point, 7);
//	push(&point, 23);
//
//	pop(&point);
//	pop(&point);
//	pop(&point);
//}

//class�� ��ȯ
//class Point
//{
//private:
//	int m_iData;
//	Point* link;
//public:
//	void push(Point** top, int Data)
//	{
//		Point* newNode = new Point;
//
//		newNode->link = *top;
//		newNode->m_iData = Data;
//		*top = newNode;
//
//		cout << newNode->link << endl;
//		cout << newNode << endl << endl;
//	}
//	void pop(Point** top);
//};
//
//void Point::pop(Point** top)
//{
//	Point *tmp;
//	tmp = *top;
//	*top = tmp->link;
//
//	cout << tmp->m_iData << endl << endl;
//	delete tmp;
//}
//
//void main()
//{
//	Point *point = NULL, *tmp;
//
//	cout << point << endl << endl;
//
//	point->push(&point, 10);
//	point->push(&point, 7);
//	point->push(&point, 23);
//
//	point->pop(&point);
//	point->pop(&point);
//	point->pop(&point);
//}


template<typename T>
class Point
{
private :
	//T* Top;
	T Top;
	Point* link;
public :
	//STACK();
	void push(Point<T>** stack, T data);
	void pop(Point<T>** stack)
	{
		Point<T> *tmp;
		tmp = *stack;
		*stack = tmp->link;
		cout << (tmp->Top) << "��" << endl;
		delete tmp;
		
	}
};

template<typename T>
void Point<T>::push(Point<T>** stack, T data)
{
	Point<T>* newNode = new Point<T>;

	newNode->link = *stack;
	//newNode->Top = *stack;
	newNode->Top = data;
	*stack = newNode;

	cout << newNode->Top << "Ǫ��" << endl;
}

void main()
{
	Point<float>* stack = NULL;

	stack->push(&stack, 5);
	stack->push(&stack, 4.3);
	stack->push(&stack, 3.f);
	stack->pop(&stack);
	stack->pop(&stack);
	stack->pop(&stack);
}
#pragma once
#include "node.h"
template <typename T>
class list {
private:
	Node<T>* current; // указатель на текущий
	Node<T>* Head; // указатель на начало
public:
	list(); //конструктор
	list(const list<T>& list2); //конструктор
	~list(); //деструктор
	list<T>& operator = (const list<T>& list2); //оператор присваивания 
	bool IsEmpty() const; //проверка на пустоту
	void Insert_to_tail(const T con = 0); //вставка в конец
	void clear(); //очистка списка
	bool operator == (const list<T>& list2) const; //оператор сравнения
	bool operator != (const list<T>& list2) const; //оператор сравнения
	void reset();//установка на начало списка
	void Dellcurrent(); //удаление текущего звена
	void getnext();//сдвиг указателя на следующий узел
	T getcurrentdate();//получить значение текущих данных
	T getcurrentnextdata(); //получить значение следующих данных
	void InsertAfterCurrent(const T con = 0); //вставить после текущего
	void ChangeCurrent(const T con = 0); //вставить в текущий
	bool IsEnd();//проверка на окончания списка
};
template <typename T>
bool list<T>::IsEnd() {
	if (current->Next == Head->Next) return true; else return false;
}
template <typename T>
void list<T>::getnext() {
	current = current->Next;
}

template <typename T>
T list<T>::getcurrentdate() {
	return current->Data;
}
template <typename T>
void list<T>::reset() {
	if (!IsEmpty()) current = Head->Next;
}
template <typename T>
list<T>::list() {
	Head = new Node<T>;
	Head->Next = Head;
	current = nullptr;
}
template <typename T>
bool list<T>::IsEmpty() const {
	if (current == nullptr)
		return true;
	else
		return false;
}


template <typename T>
void list<T>::Insert_to_tail(const T con) {
	if (!IsEmpty()) {
		while (current->Next != Head->Next) current = current->Next;
		current->Next = new Node<T>(con, Head->Next);
	}
	else {
		Head->Next = new Node<T>(con);
		Head->Next->Next = Head->Next;
		current = Head->Next;
	}
}

template <typename T>
list<T>::list(const list<T>& list2) {
	Head = new Node<T>;
	Head->Next = Head;
	current = nullptr;
	if (!list2.IsEmpty()) {
		Node<T>* ptr2 = list2.Head;
		ptr2 = ptr2->Next;
		Head->Next = new Node<T>(ptr2);
		Node<T>* ptrend = ptr2;
		current = Head->Next;
		while (ptrend->Next != ptr2) ptrend = ptrend->Next;
		ptr2 = ptr2->Next;
		while (ptr2 != list2.Head->Next) {
			current->Next = new Node<T>(ptr2);
			current = current->Next;
			ptr2 = ptr2->Next;
		}
		current->Next = Head->Next;
	}
}
template <typename T>
list<T>::~list() {
	this->clear();
}
template <typename T>
void list<T>::clear() {
	if (!IsEmpty()) {
		reset();
		Node<T>* end;
		while (!IsEnd()) getnext();
		end = current;
		reset();
		while (!IsEnd()) {
			Node<T>* ptr = current->Next;
			delete current;
			Head->Next = ptr;
			current = ptr;
			end->Next = ptr;
		}
		delete current;
		current = nullptr;
		Head->Next = Head;
	}
}
template <typename T>
list<T>& list<T>:: operator = (const list<T>& list2) { 
	this->clear();
	if (!list2.IsEmpty()) {
		Node<T>* ptr2 = list2.Head;
		ptr2 = ptr2->Next;
		Head->Next = new Node<T>(ptr2);
		Node<T>* ptrend = ptr2;
		current = Head->Next;
		while (ptrend->Next != ptr2) ptrend = ptrend->Next;
		ptr2 = ptr2->Next;
		while (ptr2 != list2.Head->Next) {
			current->Next = new Node<T>(ptr2);
			current = current->Next;
			ptr2 = ptr2->Next;
		}
		current->Next = Head->Next;
	}
	return (*this);
}


template <typename T>
bool  list<T> ::operator == (const list<T>& list2) const {
	bool res = true;
	if (list2.IsEmpty() && this->IsEmpty()) return true;
	else {
		Node<T>* listc = Head->Next;
		Node<T>* list2c = list2.Head->Next;
		if (listc->Data != list2c->Data) res = false;
		listc = listc->Next;
		list2c = list2c->Next;
		while (listc != Head->Next && list2c != list2.Head->Next) {
			if (listc->Data != list2c->Data) res = false;
			listc = listc->Next;
			list2c = list2c->Next;
		}
		if (listc != Head->Next || list2c != list2.Head->Next) res = false;
	}
	return res;
}
template <typename T>
bool  list<T> ::operator != (const list<T>& list2) const {
	if (*this == list2) return 0; else return 1;
}

template <typename T>
void list<T> ::InsertAfterCurrent(const T con)
{
	Node<T>* PtrNext = current->Next;
	current->Next = new Node<T>(con);
	current->Next->Next = PtrNext;
}

template <typename T>
void list<T> ::ChangeCurrent(const T con)
{
	current->Data = con;
}

template <typename T>
T  list<T> ::getcurrentnextdata()
{
	return current->Next->Data;
}

template <typename T>
void list<T> ::Dellcurrent()
{
	if (!this->IsEmpty())
	{
		Node<T>* Ptr = Head->Next;
		Node<T>* Ptrnext = current->Next;
		Node<T>* Ptr2 = Head->Next;

		if ((current == Ptr) && (current->Next == Ptr))
		{
			delete current;
			Head->Next = Head;
			current = nullptr;
		}
		else if ((current == Ptr) && (current->Next != Ptr))
		{
			while (Ptr2->Next != Head->Next) Ptr2 = Ptr2->Next;
			delete current;
			Head->Next = Ptrnext;
			current = Ptrnext;
			Ptr2->Next = Head->Next;

		}
		else if (current != Ptr)
		{
			while (Ptr->Next != current) Ptr = Ptr->Next;
			Ptr->Next = Ptrnext;
			delete current;
			current = Ptr;
		}
	}
}

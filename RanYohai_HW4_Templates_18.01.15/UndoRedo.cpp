#include "UndoRedo.h"

#include <iostream>

using namespace std;

template <class T>
UndoRedo<T>::UndoRedo()
{
}

template <class T>
UndoRedo<T>::~UndoRedo()
{
}

template <class T>
UndoRedo<T>::UndoRedo(const UndoRedo<T> &other)
{
	m_Redo = other.m_Redo;
	m_Undo = other.m_Undo;
}

template <class T>
const UndoRedo<T> &UndoRedo<T>::operator=(const UndoRedo<T> &other)
{
	m_Redo = other.m_Redo;
	m_Undo = other.m_Undo;

	return *this;
}

template <class T>
void UndoRedo<T>::AddNew(T obj)
{
	m_Redo.Push(obj);
}

template <class T>
void UndoRedo<T>::Delete()
{
	if (!m_Redo.IsEmpty())
	{
		T obj = m_Redo.Top();
		m_Redo.Pop();
		m_Undo.Push(obj);
	}
	else
	{
		cout << "There is nothing to delete!" << endl;
	}
}

template <class T>
void UndoRedo<T>::Restore()
{
	if (!m_Undo.IsEmpty())
	{
		T obj = m_Undo.Top();
		m_Undo.Pop();
		m_Redo.Push(obj);
	}
	else
	{
		cout << "There is nothing to restore!" << endl;
	}
}

template <class T>
void UndoRedo<T>::DeleteAll()
{
	m_Redo.DeleteAll();
	m_Undo.DeleteAll();
}

template <class T>
T UndoRedo<T>::Top() const
{
	return m_Redo.Top();
}

template <class T>
bool UndoRedo<T>::IsEmpty() const
{
	return m_Redo.IsEmpty();
}

template <class T>
void UndoRedo<T>::PrintAll() const
{
	m_Redo.Print();
	cout << endl;
}
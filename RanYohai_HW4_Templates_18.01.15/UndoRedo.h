#pragma once

#include "Stack.cpp"

template <class T>
class UndoRedo
{
public:
	UndoRedo();
	~UndoRedo();

	UndoRedo(const UndoRedo<T> &);
	const UndoRedo<T> &operator=(const UndoRedo<T> &);

	void AddNew(T);
	void Delete();
	void Restore();
	void DeleteAll();

	T Top() const;
	bool IsEmpty() const;
	void PrintAll() const;

private:
	Stack<T> m_Undo;
	Stack<T> m_Redo;
};
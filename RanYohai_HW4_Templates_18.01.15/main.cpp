#include "UndoRedo.cpp"

#include <iostream>

using namespace std;

template <class T>
void PrintUndoRedoStatus(const UndoRedo<T> &obj)
{
	if (obj.IsEmpty())
	{
		cout << "UndoRedo is empty!" << endl;
	}
	else
	{
		cout << "UndoRedo is not empty!" << endl << endl;
	}
}

template <class T>
void TestUndoRedo(UndoRedo<T> &urObj, const char *objName, 
				  T item1, T item2, T item3, T item4, T item5)
{
	cout << "Adding " << item1 << ", " << item2 << ", " << item3 << " to " << objName << " . . . " << endl;
	urObj.AddNew(item1);
	urObj.AddNew(item2);
	urObj.AddNew(item3);
	urObj.PrintAll();

	cout << "Top object of " << objName << " is: " << urObj.Top() << endl << endl;

	cout << "Deleting object from " << objName << " . . . " << endl;
	urObj.Delete();
	urObj.PrintAll();

	cout << "Top object of " << objName << " is: " << urObj.Top() << endl << endl;

	cout << "Adding " << item4 << " to " << objName << " . . . " << endl;
	urObj.AddNew(item4);
	urObj.PrintAll();

	cout << "Restoring deleted object to " << objName << " . . . " << endl;
	urObj.Restore();
	urObj.PrintAll();

	cout << "Adding " << item5 << " to " << objName << " . . . " << endl;
	urObj.AddNew(item5);
	urObj.PrintAll();

	cout << "" << objName << " status:" << endl;
	PrintUndoRedoStatus(urObj);

	cout << "Deleting all objects from " << objName << " . . . " << endl << endl;
	urObj.DeleteAll();

	cout << "" << objName << " status:" << endl;
	PrintUndoRedoStatus(urObj);

	cout << endl;
}

void main()
{
	UndoRedo<int> ints;
	TestUndoRedo(ints, "INTS", 1, 2, 3, 4, 5);

	cout << "=======================================" << endl << endl;

	UndoRedo<char> chars;
	TestUndoRedo(chars, "CHARS", 'a', 'b', 'c', 'd', 'e');
}
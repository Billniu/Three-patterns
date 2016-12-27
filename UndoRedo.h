#include <iostream>
#include <stack>
#include <string>

using namespace std;

class URStr
{
private:
	string urdo;
public:
	URStr(const string &str){ urdo = str; }
	~URStr(){}
	void print()
	{
		cout << "current string£º" << urdo << endl;
	}
};


class  UndoRedo
{
private:
	stack< URStr* > urUndo;
	stack< URStr* > urRedo;
public:
	UndoRedo(URStr* str){ urUndo.push(str); }
	~UndoRedo()
	{
		while (urUndo.empty() == false)
		{
			delete urUndo.top();
			urUndo.pop();
		}
		while (urRedo.empty() == false)
		{
			delete urRedo.top();
			urRedo.pop();
		}
	}

	void In(URStr* str)
	{
		str->print();
		urUndo.push(str);
		while (urRedo.empty() == false)
		{
			delete urRedo.top();
			urRedo.pop();
		}
	}

	void Undo(){
		if (urUndo.size() <= 2)
		{
			cout << "Undo Failed" << endl;
			return;
		}
		auto str = urUndo.top();
		urRedo.push(str);
		urUndo.pop();
		str = urUndo.top();
		str->print();
	}

	void Redo()
	{
		if (urRedo.empty())
		{
			cout << "Redo Failed" << endl;
			return;
		}
		auto str = urRedo.top();
		str->print();
		urRedo.pop();
		urUndo.push(str);
	}
};

void menu()
{
	cout << "                Instructions" << endl;
	cout << "***************************************" << endl;
	cout << "\"in + string\"		        Enter Strings" << endl;
	cout << "\"undo\"				Undo" << endl;
	cout << "\"redo\"				Redo" << endl;
	cout << "***************************************" << endl;
}







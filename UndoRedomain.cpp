#include <iostream>
#include "UndoRedo.h"

using namespace std;

int main()
{
	UndoRedo* p = new UndoRedo(new URStr("empty"));
	string str1, str2;
	menu(); 

	while (1)
	{   
		
		cout << "Enter the instruction£º" << endl;
		cin >> str1;
		
		if (str1 == "in"){
			cin >> str2;
			p->In(new URStr(str2));
		}
		if (str1 == "undo" ){
			p->Undo();
		}
		if (str1 == "redo"){
			p->Redo();
		}
		
		cout << endl;
	}

	system("pause");
	return 0;
}
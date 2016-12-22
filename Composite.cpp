#include "composite.h"
#include <iostream>
using namespace std;

void TjSse::add(Sse* pro)
{
	if (nullptr != pro)
	{
		mList.push_back(pro);
	}
}

void TjSse::remove(Sse* pro)
{
	if (nullptr != pro)
	{
		mList.remove(pro);
	}
}

void TjSse::display(string str)
{
	list<Sse* >::iterator beg = mList.begin();
	cout << str << mName << endl;
	str = str + str;
	for (; beg != mList.end(); beg++)
	{
		(*beg)->display(str);
	}
}

void TjSse::Show(string sse)
{
	list<Sse* >::iterator beg = mList.begin();
	string name = mName;
	for (; beg != mList.end(); beg++)
	{
		(*beg)->Show(name);
     }
}

void SseProfession::display(string str)
{
	cout << str << mName << endl;
}

void SseProfession::Show(string sse)
{
	cout << sse << "专业方向展示" << endl;
}

void ProfessionClass::display(string str)
{
	cout << str << mName << endl;
}

void ProfessionClass::Show(string sse)
{
	cout << sse << "部分课程展示" << endl;
}

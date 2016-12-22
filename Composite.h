#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <list>
using std::list;

#include <string>
using std::string;

#include <iostream>
using namespace std;

class Sse
{
public:
	Sse(char* name) :mName(name){}
	virtual void add(Sse* pro){}
	virtual void remove(Sse* pro){}
	virtual void display(string str){}
    virtual void Show(string sse){}

protected:
	char* mName;
	list<Sse* > mList;
};

class TjSse :public Sse{
public:
	TjSse(char* name) :Sse(name){}
	virtual void add(Sse* pro);
	virtual void remove(Sse* pro);
	virtual void display(string str);
	virtual void Show(string sse);
};

class SseProfession :public Sse
{
public:
	SseProfession(char* name) :Sse(name){}
	virtual void display(string str);
    virtual void Show(string sse);
};

class ProfessionClass :public Sse{
public:
	ProfessionClass(char* name) :Sse(name){}
	virtual void display(string str);

	virtual void Show(string sse);
};


#endif
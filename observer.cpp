#include <iostream>
#include <vector>
#include <string>
using namespace std;
class SendMoment;

// ��������Ȧ���� 
class ReceiveMoment
{
public:
	ReceiveMoment(string strName, SendMoment* strSub)
	{
		name = strName;
		sub = strSub;
	}

	void Update();

private:
	string name;
	SendMoment* sub;
};

// ������Ȧ���� 
class SendMoment
{

public:
	string action;
	void Add(ReceiveMoment ob)
	 { 
	   observers.push_back(ob); 
	   } //��ӽ����� 
	
	void Notify()
	{
		vector<ReceiveMoment>::iterator it;
		for (it=observers.begin(); it!=observers.end(); ++it)
		{
			(*it).Update();
		}
	} //֪ͨ������ 
	
	void Remove(int addIndex)
	{
		if(addIndex >=0 && addIndex < observers.size())
		observers.erase(observers.begin() + addIndex);
	} //ɾ�������� 

private:
	vector<ReceiveMoment> observers;
};



void ReceiveMoment::Update()
{
	cout << name << "   Amy��" << sub->action << endl;
}


int main()
{
	// ���������� 
	SendMoment* p = new SendMoment();

	// ���������� 
	ReceiveMoment* m1 = new ReceiveMoment("William", p);
	ReceiveMoment* m2 = new ReceiveMoment("Bob", p);

	// ����֪ͨ����
	p->Add(*m1);
	p->Add(*m2);

	// ������̬ 
	p->action = "I like snow !";

	// ����
	p->Notify();
	cout << "**************************************" << endl;
	
	// ɾ�������� 
	p->Remove(1);
	p->Notify();

	return 0;

}


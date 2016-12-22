#include <iostream>
#include <vector>
#include <string>
using namespace std;
class SendMoment;

// 接收朋友圈的类 
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

// 发朋友圈的类 
class SendMoment
{

public:
	string action;
	void Add(ReceiveMoment ob)
	 { 
	   observers.push_back(ob); 
	   } //添加接收者 
	
	void Notify()
	{
		vector<ReceiveMoment>::iterator it;
		for (it=observers.begin(); it!=observers.end(); ++it)
		{
			(*it).Update();
		}
	} //通知接收者 
	
	void Remove(int addIndex)
	{
		if(addIndex >=0 && addIndex < observers.size())
		observers.erase(observers.begin() + addIndex);
	} //删除接收者 

private:
	vector<ReceiveMoment> observers;
};



void ReceiveMoment::Update()
{
	cout << name << "   Amy：" << sub->action << endl;
}


int main()
{
	// 创建发送者 
	SendMoment* p = new SendMoment();

	// 创建接收者 
	ReceiveMoment* m1 = new ReceiveMoment("William", p);
	ReceiveMoment* m2 = new ReceiveMoment("Bob", p);

	// 加入通知队列
	p->Add(*m1);
	p->Add(*m2);

	// 发布动态 
	p->action = "I like snow !";

	// 更新
	p->Notify();
	cout << "**************************************" << endl;
	
	// 删除接收者 
	p->Remove(1);
	p->Notify();

	return 0;

}


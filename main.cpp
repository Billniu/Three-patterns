#include <iostream>
#include "composite.h"
using namespace std;

void main()
{
	
	TjSse com1("ͬ�ô�ѧ���ѧԺ");
	SseProfession com2("����ס������");
	SseProfession com3("����ý�巽��");
	SseProfession com4("���������");

	com1.add(&com2);
	com1.add(&com3);
	com1.add(&com4);


	TjSse com11("Ƕ��ʽ����");
	ProfessionClass com22("IOS����");
	ProfessionClass com33("ʵʱϵͳ");
	ProfessionClass com44("Ƕ��ʽϵͳ����");


	com11.add(&com22);
	com11.add(&com33);
	com11.add(&com44);


	com1.add(&com11);

	string str("��");
	com1.display(str);

    cout << endl;

	com1.Show(str);
	system("pause");
	return;
}
#include <iostream>
#include "composite.h"
using namespace std;

void main()
{
	
	TjSse com1("同济大学软件学院");
	SseProfession com2("大型住机方向");
	SseProfession com3("艺术媒体方向");
	SseProfession com4("软件管理方向");

	com1.add(&com2);
	com1.add(&com3);
	com1.add(&com4);


	TjSse com11("嵌入式方向");
	ProfessionClass com22("IOS开发");
	ProfessionClass com33("实时系统");
	ProfessionClass com44("嵌入式系统导论");


	com11.add(&com22);
	com11.add(&com33);
	com11.add(&com44);


	com1.add(&com11);

	string str("─");
	com1.display(str);

    cout << endl;

	com1.Show(str);
	system("pause");
	return;
}
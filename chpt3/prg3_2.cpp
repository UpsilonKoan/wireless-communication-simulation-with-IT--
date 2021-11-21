#include "stdafx.h"
#include "itpp/itcomm.h"
#include <itpp/comm/channel.h>
#include <iostream>
#include <fstream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using namespace itpp;

int main(int argc, char* argv[])
{
	//�ŵ�ÿ��������仯һ��
	ofstream f1("staticchannel.txt");
  	Static_Fading_Generator fad1;   //ʵ������ȷ��˥����
   //��ʼ��˥�������
	fad1.set_LOS_power(1.0);      //����ֱ�侶��Թ���ֵ
	cvec out;                    //�����������
	out.set_length(10);           //����ÿ�ξ�̬�ŵ������������

	for(int i=0;i<1000;i++)
	{
		fad1.init();  
		fad1.generate(10,out);        //�����ŵ�ϵ�������out����
		f1<<abs(out)<<endl;
	}
	
	f1.close();
	system("Pause");
	return 0;
}

#include "stdafx.h"
#include <itpp/itbase.h>
#include <itpp/itcomm.h>
using namespace itpp;

//These lines are needed for use of cout and endl
using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout<<"******************LFSR*****************"<<endl;
	LFSR lfsr;
	bvec Connection="1 0 1 1";//���Ӷ���ʽ
	bvec State="0 0 1";//��ʼ״̬
	lfsr.set_connections(Connection);//�������Ӷ���ʽ
	lfsr.set_state(State);//���ó�ʼ״̬
	cout<<lfsr.get_state();
	cout<<"���Ӷ���ʽ��"<<Connection<<endl;
	cout<<"�Ĵ�������"<<lfsr.get_length()<<endl;
	bvec Sequence(7);
	int i;
	for(i = 0;i < Sequence.length();i ++)
	{
		Sequence(i)=lfsr.shift();
		cout<<"step  "<<"�Ĵ���״̬      "<<"output  "<<endl;
		cout<<i<<"     "<<lfsr.get_state()<<"    "<<Sequence(i)<<endl;
	}
	cout<<endl<<"����:"<<Sequence<<endl;
	return 0;
}

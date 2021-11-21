#include "stdafx.h"
#include "itpp/itcomm.h"
#include "itpp/comm/spread.h"

using std::cin;
using std::cout;
using std::endl;
using namespace itpp;

int main(int argc, char* argv[])
{
   //����I Q֧·��Ƶ��
   vec spreading_code_I = "1 1 1 1";
   vec spreading_code_Q = "1 1 1 1";

   //��ʼ��spread_2d��
   Spread_2d spread_2d(spreading_code_I,spreading_code_Q);

   //�����������
   bvec transmitted_bits = randb(6);

   //QPSK����
    QPSK qpsk;                

    cvec transmitted_symbols = qpsk.modulate_bits(transmitted_bits);

	//��Ƶ����
	cvec transmitted_signal = spread_2d.spread(transmitted_symbols);	

    cvec received_signal = transmitted_signal;

	//�����ź�
	cvec received_symbols  = spread_2d.despread(received_signal,0);

	//���
    bvec received_bits = qpsk.demodulate_bits(received_symbols);

    //��ʾ���
	cout<< "transmitted_bits = " << transmitted_bits <<endl;
	cout<< "transmitted_symbols = " << transmitted_symbols <<endl;
	cout<< "transmitted_signal = " << transmitted_signal <<endl;
	cout<< "received_symbols = " << received_symbols <<endl;
    cout<< "received_bits = " << received_bits <<endl;
	return 0;
}

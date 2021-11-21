#include "stdafx.h"
#include "itpp/itcomm.h"
#include "itpp/comm/spread.h"

using std::cin;
using std::cout;
using std::endl;
using namespace itpp;

int main(int argc, char* argv[])
{
    //������Ƶ��
    vec spreading_code = "-1 1 -1 1";

    //��ʼ��Spread_1d��
    Spread_1d spread_1d(spreading_code);

    //�����������
    bvec transmitted_bits = randb(10);
    BPSK bpsk;
    vec transmitted_symbols = bpsk.modulate_bits(transmitted_bits);

    //�����н�����Ƶ
    vec transmitted_signal = spread_1d.spread(transmitted_symbols);

    vec received_signal = transmitted_signal;

    //�Խ����źŽ���
    vec received_symbols  = spread_1d.despread(received_signal,0);

    //����ź�
    bvec received_bits = bpsk.demodulate_bits(received_symbols);

    //��ʾ���
	cout<< "transmitted_bits = " << transmitted_bits <<endl;
	cout<< "transmitted_symbols = " << transmitted_symbols <<endl;
	cout<< "transmitted_signal = " << transmitted_signal <<endl;
	cout<< "received_symbols = " << received_symbols <<endl;
    cout<< "received_bits = " << received_bits <<endl;
	return 0;
}

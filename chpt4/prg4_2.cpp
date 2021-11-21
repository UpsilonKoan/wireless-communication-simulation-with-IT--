#include "stdafx.h"
#include "itpp/itcomm.h"
#include <itpp/comm/hammcode.h>
using std::cin;
using std::cout;
using std::endl;
using namespace itpp;
int main(int argc, char* argv[])
{
		BPSK bpsk; //BPSK���ʵ����
		bvec uncoded_bit,coded_bit,decoded_bit,decoded_bit_bpsk;
		vec tx_signal, rx_signal;
        Extended_Golay golay;
		uncoded_bit="1 0 0 0 0 0 0 0 0 0 0 0";
	
		golay.encode(uncoded_bit, coded_bit);
		tx_signal=bpsk.modulate_bits(coded_bit); //����
		rx_signal = tx_signal + sqrt(0.5)*randn(tx_signal.size());//������
		bpsk.demodulate_bits(rx_signal,decoded_bit_bpsk);
		golay.decode(decoded_bit_bpsk,decoded_bit); //vec����������
		cout<<" uncoded_bit="<< uncoded_bit<<endl;
		cout<<" coded_bit ="<<coded_bit<<endl;
		cout<<"decoded_bit_bpsk=" <<decoded_bit_bpsk<<endl;
		cout<<"decoded_bit ="<<decoded_bit<<endl;

		system("Pause");
}

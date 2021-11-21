#include "stdafx.h"
#include "itpp/itcomm.h"
#include <itpp/comm/punct_convcode.h>


using std::cin;
using std::cout;
using std::endl;
using namespace itpp;

int main(int argc, char* argv[])
{
	BPSK bpsk;
	Punctured_Convolutional_Code code;
	ivec generator(3); 
	generator(0)=0133; 
	generator(1)=0165; 
	generator(2)=0171; 
	code.set_generator_polynomials(generator, 7); // �趨���ɶ���ʽ

	bmat puncture_matrix = "1 1;1 0;0 1"; //�趨����Ϊ1/3

    code.set_puncture_matrix(puncture_matrix);//�趨��׾���
	code.set_truncation_length(30);

	bvec bits=randb(100), encoded_bits, decoded_bits;
	vec  tx_signal,  rx_signal;

	code.encode(bits, encoded_bits);//�������
	tx_signal = bpsk.modulate_bits(encoded_bits);//����
	rx_signal = tx_signal + sqrt(0.5)*randn(tx_signal.size());    //������
	code.decode(rx_signal, decoded_bits);//����

    cout<<"uncoded_bits="<<bits<<endl;
	cout<<"encoded_bits="<<encoded_bits<<endl;
	cout<<"tx_signal="<<tx_signal<<endl;
	cout<<"rx_signal="<<rx_signal<<endl;
	cout<<"decoded_bits="<<decoded_bits<<endl;

	
	return 0;
}

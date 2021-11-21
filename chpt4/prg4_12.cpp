#include "stdafx.h"
#include "itpp/itcomm.h"
#include <itpp/comm/turbo.h>


using std::cin;
using std::cout;
using std::endl;
using namespace itpp;

int main(int argc, char* argv[])
{
 // �������:
QPSK qpsk;                       // QPSK����
AWGN_Channel awgn_channel;      // AWGN�ŵ�
BERC berc;                       // ����������
Turbo_Codec turbo;

// ������ʸ���������ͳ�ʼ��: 
int Number_of_bits=400;             // ������Ŀ
int ml=2;                          // ���Ƶ�ƽ����QPSK ml=2
int i;
int constraint_length ;                // turbo���ڽ�֯����Լ������
double Es, Eb;                      // ���������ͱ�������
double code_rate;                   // turbo���������
vec EbN0dB, EbN0, N0, noise_variance, bit_error_rate, received_soft_bits; 
// vec ��һ���洢double�ͱ���������
bvec transmitted_bits, encoded_bits, received_bits;                 
// bvec ��һ���洢�����Ʊ��ص�����
cvec transmitted_symbols, received_symbols;          
// cvec ��һ���洢double_complex�ͱ���������
ivec gen(2);                        // Turbo�����ɶ���ʽ

// ����Turbo��Ĳ��� ��
gen(0) = 013;
gen(1) = 015;
constraint_length=4;       
code_rate = (double)(Number_of_bits / (3.0 * Number_of_bits + 4.0 *(constraint_length-1))); 

// ����turbo���ڽ�֯���� 
ivec interleaver_sequence = wcdma_turbo_interleaver_sequence( 40 );
turbo.set_parameters(gen, gen, constraint_length,interleaver_sequence);

// �����������ߴ��������ܶȣ�
Es = 1.0;                                   // ÿ��QPSK��������
Eb = Es / (ml * code_rate);                     // ÿ���ŵ��ı�������
EbN0dB = linspace(0.0,4.0,5);                  // Eb/N0 ��ֵdB����0dB��4dB,��5��ֵ
EbN0 = inv_dB(EbN0dB);                     // Eb/N0 ���Ե�ֵ 
N0 = Eb * pow(EbN0,-1.0);                    // N0 ��ֵ�����ķ���  

bit_error_rate.set_size(EbN0dB.length(),false);     // Ϊ������������ڴ�ռ�. 
RNG_randomize();                           // ���������:

// ��ʼ���棺
for (i=0; i<EbN0dB.length(); i++) {                    // ��������EbN0dBֵ:
 
transmitted_bits = randb(Number_of_bits);             // ���������������0 1 
turbo.encode(transmitted_bits,encoded_bits);               // turbo����
transmitted_symbols = qpsk.modulate_bits(encoded_bits);    // QPSK����

awgn_channel.set_noise(N0(i));                       // ����AWGN�ŵ�����
received_symbols = awgn_channel(transmitted_symbols);    // ͨ��AWGN�ŵ�
received_soft_bits = qpsk.demodulate_soft_bits(received_symbols ,N0(i)); // QPSK����
turbo.decode(received_soft_bits,received_bits);            // turbo����

// ����������ʣ�
berc.clear();                                       // ���������ʼ�����
berc.count(transmitted_bits,received_bits);               // �����������
bit_error_rate(i) = berc.get_errorrate();         // ��������ʱ����ڽ��������
}

//������:
cout << endl;
cout << "EbN0dB = " << EbN0dB << " [dB]" << endl;
cout << "BER = " << bit_error_rate << endl;
cout << endl;


	return 0;
}

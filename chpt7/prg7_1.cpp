#include "stdafx.h"
#include "itpp/itcomm.h"

using std::cin;
using std::cout;
using std::endl;
using namespace itpp;

int main(int argc, char* argv[])
{
  //��������
  int i, Number_of_bits;                            
  double Ec, Eb;
  vec EbN0dB, EbN0, N0, noise_variance, bit_error_rate; //vec �Ǹ���������
  bvec transmitted_bits, received_bits;                 //bvec�Ƕ�����������
  cvec transmitted_symbols, received_symbols,ofdm_mod_symbols,ofdm_demod_symbols;   //cvec �Ǹ�����

  //������:
  OFDM ofdm;                     //����OFDM��
  QPSK qpsk;                     //����QPSK��
  AWGN_Channel awgn_channel;     //�����˹�������ŵ���
  it_file ff;                    //���ڴ洢������ļ�
  BERC berc;                     //����������
  Real_Timer tt;                 //��ʱ�����ڲ�������ʱ��
 
  //��ʱ����ʼ
  tt.tic();

  //������ʼ����
  Ec = 1.0;                      
  Eb = Ec / 2.0;                 
  EbN0dB = linspace(0.0,9.0,10); 
  EbN0 = inv_dB(EbN0dB);        
  N0 = Eb * pow(EbN0,-1.0);      
  Number_of_bits = 128*2*6;    
  ofdm.set_parameters(128,32,1); //����OFDM�Ĳ�����FFT�ĵ����ǣ�CPѭ��ǰ׺�ĳ����ǣ�������Ϊ��Ĭ��ֵ��

  //Ϊ�������ռ䣬 "false" ��ʾ��Ҫ���ƾɵı������¿��ٵĿռ�
  bit_error_rate.set_size(EbN0dB.length(),false);

  //�����������:
  RNG_randomize();

  for (i=0; i<EbN0dB.length(); i++) {

    cout << "Now simulating Eb/N0 value number " << i+1 << " of " << EbN0dB.length() << endl;

    transmitted_bits = randb(Number_of_bits);

    transmitted_symbols = qpsk.modulate_bits(transmitted_bits);

	ofdm.modulate(transmitted_symbols,ofdm_mod_symbols);   //ofdm���ƣ�IFFT�任����ѭ��ǰ׺
    awgn_channel.set_noise(N0(i));

    received_symbols = awgn_channel(ofdm_mod_symbols);

	ofdm_demod_symbols = ofdm.demodulate(received_symbols); //ofdm�����FFT�任��ȥѭ��ǰ׺
received_bits = qpsk.demodulate_bits(ofdm_demod_symbols);

    //����������:
    berc.clear();                               
    berc.count(transmitted_bits,received_bits);
    bit_error_rate(i) = berc.get_errorrate(); 

  }
  tt.toc_print();
  //��ʾ���:
  cout << endl;
  cout << "EbN0dB = " << EbN0dB << " [dB]" << endl;
  cout << "BER = " << bit_error_rate << endl;
  cout << "Saving results to ./ofdm_result_file.it" << endl;
  cout << endl;

  //���������ļ���:
  ff.open("ofdm_result_file.it");
  ff << Name("EbN0dB") << EbN0dB;
  ff << Name("ber") << bit_error_rate;
  ff.close();

	return 0;
}


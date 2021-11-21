#include "stdafx.h"
#include "itpp/itcomm.h"
#include <itpp/comm/crc.h>
#include <itpp/itbase.h>


using std::cin;
using std::cout;
using std::endl;
using std::string;


using namespace itpp;

int main(int argc, char* argv[])
{
	//Declarations of scalars and vectors: 
  CRC_Code crc(string("CRC-4"));//�����ַ���ֵCRC-4�趨����CRC
  //��׼����ʽ
  bvec bits = randb(10),coded_bits,decoded_bits,rec_bits;//�趨�洢������
                                               //������Ϣ����
  bool error;
  coded_bits = crc.encode(bits);   //���㲢����Ӽ����ֶΣ�����CRC�� 
  rec_bits =coded_bits;
  error = crc.decode(rec_bits, decoded_bits);//У����ȷ��
  cout<<"�������="<<bits<<endl;
  cout<<"CRC����="<<coded_bits<<endl;
  cout<<"������"<<decoded_bits<<endl;

  
  return 0;
}

#include "stdafx.h"
#include "itpp/itcomm.h"
#include <itpp/comm/egolay.h>
using std::cin;
using std::cout;
using std::endl;
using namespace itpp;
int main(int argc, char* argv[])
{
	Extended_Golay golay; //���ʵ����
	bvec uncoded_bit,coded_bit;
	uncoded_bit="1 0 0 0 0 0 0 0 0 0 0 0 1"; //����13λ������
	golay.encode(uncoded_bit, coded_bit);  //��չ���ױ���
	cout<< uncoded_bit <<endl;
	cout<< coded_bit <<endl;
	system("Pause");
}

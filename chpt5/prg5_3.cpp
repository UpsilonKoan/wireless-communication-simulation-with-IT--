#include <itpp/itbase.h>
#include <itpp/itsignal.h>

using namespace itpp;
using namespace std;

int main()
{
  cout << "======================================" << endl;
  cout << "        Test of filter routines       " << endl;
  cout << "======================================" << endl;

  // �����ź�
  vec x = randn(10), x2 = randn(10);

  cout << "Input signals: " << endl;
  cout << "x = " << x << endl;
  cout << "x2 = " << x2 << endl;

  // �˲�������
  vec b(10);
  b.ones();
  b(0) += 0.1;

  vec a(2);
  a(0) = 1.0;
  a(1) = -1.0;

  cout << "Filter coefficients: " << endl;
  cout << "b = " << b << endl;
  cout << "a = " << a << endl;

  vec y, y2;
  vec s1, s2;

  cout << endl << "-----------------------------------------------" << endl;
  cout << "MA Filter: " << endl;

  MA_Filter<double, double, double> H(b);//����MA�˲�������

  y = H(x);          //���������ź�x�����˲���
  s1 = H.get_state();//�õ��˲���״̬
  cout << "y = " << y << endl;
  cout << "s1 = " << s1 << endl;
  y2 = H(x2);        //���������ź�x2�����˲���
  s2 = H.get_state();//�õ��˲���״̬
  cout << "y2 = " << y2 << endl;
  cout << "s2 = " << s2 << endl;

  return 0;
}


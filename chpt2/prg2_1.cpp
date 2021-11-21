#include "stdafx.h"
#include "itpp/itbase.h"
#include <cstdio>


using std::cin;
using std::cout;
using std::endl;
using namespace itpp;

int main(int argc, char* argv[])
{
	//Declarations of scalars and vectors: 
   // complex<double> d=(32.0000, 0);
    vec  a = "0 0.7 5 9.3";
    bin  b;
	b=randb();
	ivec c = "0:5";
	bvec bin_list="1 0 1 1 1 0 0 0 0";

   //Print the results:
  cout << endl;
  cout << "a = " << a <<  endl;
  cout << "b = " << b <<  endl;
  cout << "c = " << c <<  endl;
  cout << "bin_list = " << bin_list <<  endl;

  //ʸ�������ʼ��ʾ��
	vec  d = "1 0.02 4.46 5.26"; //����ʸ������ d = [1  0.02  4.46  5.26]
	cout << "d = " << d <<  endl;

	vec  e;e = "3:2.5:13";         //����ʸ������e= [3  5.5  8  10.5  13]
    cout << "e = " << e <<  endl;

	vec  f=("1.2,3.4,5.6");       // ����ʸ������ f = [1.2  3.4  5.6]
    cout << "f = " << f <<  endl;

	vec g;
	    g.set("1.0  2.0  3.0  4.0");//����ʸ������g = [1.0  2.0  3.0  4.0]
    cout << "g = " << g <<  endl;

	vec h;
		h= g;                   //����ʸ������g��ֵ����h
    cout << "h = " << h <<  endl;

	ivec  i = "1:6";                // ����ʸ������i = [1  2  3  4  5  6]
    cout << "i = " << i <<  endl;

	
   mat A; A = "1.0 2.0;3.0 4.0";
   cout << "A = " << A <<  endl;

   cout<<"a.left(2)="<<a.left(2)<<endl; 
   cout<<"bin_list.right(2)="<<bin_list.right(2)<<endl; 
   cout<<"bin_list.mid(1,2)="<<bin_list.mid(1,3)<<endl; 
   cout<<"bin_list(2,4)="<<bin_list(2,4)<<endl; 

   cout << endl;

 

	return 0;
}

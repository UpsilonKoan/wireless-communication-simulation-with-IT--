// 8-PSK���ƽ��
#include <itpp/itcomm.h>
using namespace itpp;
using namespace std;
int main()
{
  RNG_reset(12345);   //�������������
  const int no_symbols = 5;  //���ͷ�����
  const double N0 = 0.1;  //��������
{
    cout << endl << "8-PSK" << endl;
    PSK psk(8);  // 8-PSK����
    int bps = round_i(psk.bits_per_symbol()); //ÿ�����ŵı�����
    bvec tx_bits = randb(no_symbols * bps); //���ͱ���
    ivec tx_sym_numbers = randi(no_symbols, 0, pow2i(bps) - 1); //���ͷ���
    cvec noise = sqrt(N0) * randn_c(no_symbols); //����

    cvec tx_symbols = psk.modulate(tx_sym_numbers);//���ŵ���
    cvec rx_symbols = tx_symbols + noise; //���շ���
    ivec dec_sym_numbers = psk.demodulate(rx_symbols);//���Ž��

    cout << "* modulating symbol numbers:" << endl;
    cout << "  tx_sym_numbers  = " << tx_sym_numbers << endl;
    cout << "  tx_symbols      = " << tx_symbols << endl;
    cout << "  rx_symbols      = " << rx_symbols << endl;
    cout << "  dec_sym_numbers = " << dec_sym_numbers << endl;

    tx_symbols = psk.modulate_bits(tx_bits);//���ص���
    rx_symbols = tx_symbols + noise; //���շ���
    bvec decbits = psk.demodulate_bits(rx_symbols);//����Ӳ���
    vec softbits_approx = psk.demodulate_soft_bits(rx_symbols, N0, APPROX); //AWGN�ŵ�������ؽ��ƽ��
    vec softbits = psk.demodulate_soft_bits(rx_symbols, N0, LOGMAP);
 //AWGN�ŵ��������Log-MAP���

    cout << "* modulating bits:" << endl;
    cout << "  tx_bits         = " << tx_bits << endl;
    cout << "  tx_symbols      = " << tx_symbols << endl;
    cout << "  rx_symbols      = " << rx_symbols << endl;
    cout << "  decbits         = " << decbits << endl;
    cout << "  softbits        = " << softbits << endl;
    cout << "  softbits_approx = " << softbits_approx << endl << endl;
  }
}

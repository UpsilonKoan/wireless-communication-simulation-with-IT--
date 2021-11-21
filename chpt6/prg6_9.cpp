#include <itpp/itcomm.h>
using namespace itpp;
using namespace std;
int main()
{
  RNG_reset(12345);//���������
  const int no_symbols = 5; //���Ÿ���
  const double N0 = 0.05;//�����������ܶ�
{
    cout << endl << "4-PAM(real)" << endl;
    PAM pam(4);
    int bps = round_i(pam.bits_per_symbol());//ÿ���ű��ظ���

    bvec tx_bits = randb(no_symbols * bps);//���ͱ���
    ivec tx_sym_numbers = randi(no_symbols, 0, pow2i(bps) - 1);//���ͷ���
    vec noise = sqrt(N0) * randn(no_symbols);//����

    vec tx_symbols = pam.modulate(tx_sym_numbers);//���ŵ���
    vec rx_symbols = tx_symbols + noise;//���շ���
    ivec dec_sym_numbers = pam.demodulate(rx_symbols);//���Ž��

    cout << "* modulating symbol numbers:" << endl;
    cout << "  tx_sym_numbers  = " << tx_sym_numbers << endl;
    cout << "  tx_symbols      = " << tx_symbols << endl;
    cout << "  rx_symbols      = " << rx_symbols << endl;
    cout << "  dec_sym_numbers = " << dec_sym_numbers << endl;

    tx_symbols = pam.modulate_bits(tx_bits);//���ص���
    rx_symbols = tx_symbols + noise;//���շ���
    bvec decbits = pam.demodulate_bits(rx_symbols);//����Ӳ���
    vec softbits_approx = pam.demodulate_soft_bits(rx_symbols, N0, APPROX); //AWGN�ŵ�������ؽ��ƽ��
    vec softbits = pam.demodulate_soft_bits(rx_symbols, N0, LOGMAP);
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

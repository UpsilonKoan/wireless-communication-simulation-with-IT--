#include <itpp/itcomm.h>
using namespace itpp;
using namespace std;
int main()
{
  RNG_reset(12345); //���������
  const int no_symbols = 5; //���ͷ��Ÿ���
  const double N0 = 0.1;  //�����������ܶ�
{
    cout << endl << "PAM_c(complex)" << endl;
    PAM_c pam_c(4); //4-PAM
    int bps = round_i(pam_c.bits_per_symbol());//ÿ���ű�����

    bvec tx_bits = randb(no_symbols * bps);//���ͱ���
    ivec tx_sym_numbers = randi(no_symbols, 0, pow2i(bps) - 1);//���ͷ���
    cvec noise = sqrt(N0) * randn_c(no_symbols);//����

    cvec tx_symbols = pam_c.modulate(tx_sym_numbers);//���ŵ���
    cvec rx_symbols = tx_symbols + noise;//���շ���
    ivec dec_sym_numbers = pam_c.demodulate(rx_symbols);//���Ž��

    cout << "* modulating symbol numbers:" << endl;
    cout << "  tx_sym_numbers  = " << tx_sym_numbers << endl;
    cout << "  tx_symbols      = " << tx_symbols << endl;
    cout << "  rx_symbols      = " << rx_symbols << endl;
    cout << "  dec_sym_numbers = " << dec_sym_numbers << endl;

    tx_symbols = pam_c.modulate_bits(tx_bits);//���ص���
    rx_symbols = tx_symbols + noise; //���շ���
    bvec decbits = pam_c.demodulate_bits(rx_symbols);//����Ӳ���
    vec softbits_approx = pam_c.demodulate_soft_bits(rx_symbols, N0, APPROX); //AWGN�ŵ�������ؽ��ƽ��
    vec softbits = pam_c.demodulate_soft_bits(rx_symbols, N0, LOGMAP); //AWGN�ŵ��������Log-MAP���

    cout << "* modulating bits:" << endl;
    cout << "  tx_bits         = " << tx_bits << endl;
    cout << "  tx_symbols      = " << tx_symbols << endl;
    cout << "  rx_symbols      = " << rx_symbols << endl;
    cout << "  decbits         = " << decbits << endl;
    cout << "  softbits        = " << softbits << endl;
    cout << "  softbits_approx = " << softbits_approx << endl << endl;
  }
}

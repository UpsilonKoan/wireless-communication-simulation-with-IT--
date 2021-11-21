#include <itpp/itcomm.h>
using namespace itpp;
using namespace std;
int main()
{
  RNG_reset(12345);  //���������
  const int no_symbols = 5;  //���Ÿ���
  const double N0 = 0.1;  //�����������ܶ�
{
    cout << endl << "BPSK(real)" << endl;
    BPSK bpsk;  //BPSK����
    int bps = round_i(bpsk.bits_per_symbol()); //ÿ�����ŵı���λ��

    bvec tx_bits = randb(no_symbols * bps); //���ͱ���
    ivec tx_sym_numbers = randi(no_symbols, 0, pow2i(bps) - 1); //���ͷ���
    vec noise = sqrt(N0) * randn(no_symbols); //����

    vec tx_symbols = bpsk.modulate(tx_sym_numbers);//���ŵ���
    vec rx_symbols = tx_symbols + noise; //���շ���
    ivec dec_sym_numbers = bpsk.demodulate(rx_symbols);//���ŵ���

    cout << "* modulating symbol numbers:" << endl;
    cout << "  tx_sym_numbers  = " << tx_sym_numbers << endl;
    cout << "  tx_symbols      = " << tx_symbols << endl;
    cout << "  rx_symbols      = " << rx_symbols << endl;
    cout << "  dec_sym_numbers = " << dec_sym_numbers << endl;

    tx_symbols = bpsk.modulate_bits(tx_bits);//���ص���
    rx_symbols = tx_symbols + noise; //���շ���
    bvec decbits = bpsk.demodulate_bits(rx_symbols);//����Ӳ���
    vec softbits_approx = bpsk.demodulate_soft_bits(rx_symbols, N0, APPROX); //AWGN�ŵ�������ؽ��ƽ��
    vec softbits = bpsk.demodulate_soft_bits(rx_symbols, N0, LOGMAP);
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

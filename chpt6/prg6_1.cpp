#include <itpp/itcomm.h>
using namespace itpp;
using namespace std;
int main()
{
  RNG_reset(12345); //�������������
  const int no_symbols = 5;//5������
  const double N0 = 0.1;
  {
    cout << endl << "Modulator_1D (configured as BPSK)" << endl;
    Modulator_1D  mod("1.0 -1.0", "0 1"); //1Dʵ������
    int bps = round_i(mod.bits_per_symbol());

    bvec tx_bits = randb(no_symbols * bps);//��������bit
    ivec tx_sym_numbers = randi(no_symbols, 0, pow2i(bps) - 1);//���ͷ���
    vec noise = sqrt(N0) * randn(no_symbols);//��������

    vec tx_symbols = mod.modulate_bits(tx_bits);//���ص��ƣ��õ����ƺ�ķ���
    vec rx_symbols = tx_symbols + noise;//���յ����������ķ���
    bvec decbits = mod.demodulate_bits(rx_symbols);//����Ӳ������õ�������

    cout << "* modulating bits:" << endl;
    cout << "  tx_bits         = " << tx_bits << endl;
    cout << "  tx_symbols      = " << tx_symbols << endl;
    cout << "  rx_symbols      = " << rx_symbols << endl;
    cout << "  decbits         = " << decbits << endl;

    tx_symbols = mod.modulate(tx_sym_numbers);//���ŵ���
    rx_symbols = tx_symbols + noise;
    ivec dec_sym_numbers = mod.demodulate(rx_symbols);//���Ž��

    cout << "* modulating symbol numbers:" << endl;
    cout << "  tx_sym_numbers  = " << tx_sym_numbers << endl;
    cout << "  tx_symbols      = " << tx_symbols << endl;
    cout << "  rx_symbols      = " << rx_symbols << endl;
    cout << "  dec_sym_numbers = " << dec_sym_numbers << endl;
}
}

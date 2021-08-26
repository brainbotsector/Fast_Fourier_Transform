#include <complex>
#include <iostream>
#include <valarray>
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
void fft(CArray& x)
{
const size_t N = x.size();
if (N <= 1) return;
CArray even = x[std::slice(0, N / 2, 2)];
CArray odd = x[std::slice(1, N / 2, 2)];
fft(even);
fft(odd);
for (size_t k = 0; k < N / 2; ++k)
{
 Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
 x[k] = even[k] + t;
 x[k + N / 2] = even[k] - t;
}
}
int main()
{
int N;
std::cout << "Enter number of elements:";
std::cin >> N;
Complex test[100];
std::cout << "Enter values:";
for (int i = 0; i < N; i++) {
 std::cin >> test[i];
}
CArray data(test, N);
fft(data);
std::cout << "Output values:" << std::endl;
for (int i = 0; i < N; ++i)
{
 std::cout << data[i] << std::endl;
}
return 0;
}
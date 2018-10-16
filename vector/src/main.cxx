#include <cmath>
#include <iostream>
#include "Classes/Vector.h"

template<typename T>
Vector<T> init(int n)
{
	Vector<T> vec(n);

	for (int i = 0; i != vec.size(); ++i)
		vec[i] = 777;

	return vec;
}

template<typename T>
double sqrt_num(Vector<T> &v)
{
	double sum = 0;

	for (int i = 0; i != v.size(); ++i)
		sum += std::sqrt(v[i]);

	return sum;
}

int main (int argc, char *argv[])
{
	std::cout << "*** Vector demo program ***\n";

	Vector<double> v {1, 2, 3, 4, 5};

	double out = sqrt_num(v);

	std::cout << "Output v : " << out << "\n";

	Vector<double> v1 = v;

	v1[2] = 6;

	out = sqrt_num(v);
	double out1 = sqrt_num(v1);

	std::cout << "Output v : " << out << "  v1 : " << out1 << "\n";

	Vector<double> v2 = v + v1;
	out = sqrt_num(v2);

	std::cout << "Output v2 : " << out << "\n";

	Vector<double> v3 = init<double>(1'000'000);

	std::cout << "Output v3[12345] : " << v3[12345] << "\n";

	return 0;
}

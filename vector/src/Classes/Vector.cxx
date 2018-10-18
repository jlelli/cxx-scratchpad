#include <iostream>
#include "Vector.h"

template<typename T>
Vector<T>::Vector(int s)
	:elem{new T[s]}, sz{s}
{
	std::cout << "Vector::int constructor\n";
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> lst)
	:elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())}
{
	std::cout << "Vector::list constructor\n";
	std::copy(lst.begin(), lst.end(), elem);
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] elem;
}

template<typename T>
Vector<T>::Vector(const Vector& a)
	:elem{new T[a.sz]},
	sz{a.sz}
{
	std::cout << "Vector::copy constructor\n";

	for (int i=0; i != sz; ++i)
		elem[i] = a.elem[i];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& a)
{
	std::cout << "Vector::copy assignment\n";

	T *p = new T[a.sz];

	for (int i = 0; i != a.sz; ++i)
		p[i] = a.elem[i];

	delete[] elem;
	elem = p;
	sz = a.sz;

	return *this;
}

template<typename T>
Vector<T>::Vector(Vector&& a)
	:elem{a.elem},
	sz{a.sz}
{
	std::cout << "Vector::move constructor\n";

	a.elem = nullptr;
	a.sz = 0;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& a)
{
	std::cout << "Vector::move assignment\n";

	elem = a.elem;
	sz = a.sz;

	return *this;
}

template<typename T>
Vector<T> Vector<T>::operator+ (const Vector<T>& a)
{
	std::cout << "Vector::operator+\n";

	if (this->size() != a.size())
		throw std::length_error{"Vector::operator+, can't add Vectors of different sizes"};

	Vector<T> res(this->size());

	for (int i = 0; i != this->size(); ++i)
		res[i] = this->elem[i] + a[i];

	return res;
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
	return elem[i];
}

template<typename T>
T& Vector<T>::operator[](int i)
{
	return elem[i];
}

template<typename T>
int Vector<T>::size() const
{
	return sz;
}

template class Vector<double>;

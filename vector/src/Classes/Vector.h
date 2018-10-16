#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <algorithm>
#include <initializer_list>
#include <stdexcept>

template<typename T> class Vector;
template<typename T> Vector<T> operator+(const Vector<T>&, const Vector<T>&);

template<typename T>
class Vector {
public:
	explicit Vector(int);
	Vector(std::initializer_list<T>);
	~Vector();

	Vector(const Vector&); //copy constructor
	Vector& operator=(const Vector&); //copy assignment

	Vector(Vector&&); //move constructor
	Vector& operator=(Vector&&); //move assignment

	friend Vector<T> operator+ <T> (const Vector<T>&, const Vector<T>&);

	T& operator[](int);
	const T& operator[](int) const;

	int size() const;
private:
	T* elem;
	int sz;
};

#endif

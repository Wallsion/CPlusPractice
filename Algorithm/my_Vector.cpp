#include "stdafx.h"
#include "my_Vector.h"

template <typename T>
void my_Vector<T>::copyFrom(T *const A, int lo, int hi)
{
	_elem = new T[_capacity = 2 * (hi - lo)];
	_size = 0;
	while (lo < hi)
	{
		_elem[_size++] = A[lo++];
	}
}

template <typename T>
my_Vector<T>::my_Vector(int c)
{
	_elem = new T[_capacity = c]; _
		size = 0;
}

template <typename T>
my_Vector<T>::my_Vector(T *A, Rank lo, Rank hi)
{
	copyFrom(A, lo, hi);
}
template <typename T>
my_Vector<T>::my_Vector(T *A, Rank n)
{
	copyFrom(A, 0, n);
}
template <typename T>
my_Vector<T>::my_Vector(my_Vector<T> const &V, Rank lo, Rank hi)
{
	copyFrom(V._elem, lo, hi);
}
template <typename T>
my_Vector<T>::my_Vector(my_Vector<T> const &V)
{
	copyFrom(V._elem, 0, V._size);
}
template <typename T>
my_Vector<T> my_Vector<T>::operator=(my_Vector<T> const &V)
{
	int n = V._size();
	if (_capacity < n)
	{
		delete[] _elem;
		_elem = new T[_capacity = 2 * n];
	}
	copyFrom(V._elem, 0, n);
	return *this;
}

template <typename T>
void my_Vector<T>::expand()
{
	if (_size < _capacity) return;
	if (_capacity < DEFAULT_CAPACTIY) _capacity = DEFAULT_CAPACTIY;
	T *oldElem = _elem;
	_elem = new T[_capacity << 1];
	for (int i; i < _size; i++)
	{
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;
}

template <typename T>
int my_Vector<T>::disordered() const
{
	int n = 0;
	for (int i = 1; i < _size; i++)
	{
		if (_elem[1 - 1] > _elem[i])
			n++;
	}
	return n;
}

template <typename T>
Rank my_Vector<T>::find(T const &e, Rank lo, Rank hi) const
{
	Rank temIndex = -1;
	if (!(0 < lo && lo < hi && hi < _size))
	{
		std::cout << "index error!";
		return -1;
	}
	for (int i = lo; i < hi; i++)
	{
		if (_elem[i] == e)
			temIndex = i;
	}
	return temIndex;
}

template <typename T>
Rank my_Vector<T>::search(T const &e, Rank lo, Rank hi) const
{
	return 1;
}
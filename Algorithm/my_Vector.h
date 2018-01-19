#pragma once
typedef int Rank;
#define DEFAULT_CAPACTIY 3
template <typename T>

class my_Vector
{
private:
	Rank _size;
	int _capacity;
	T *_elem;
protected:
	void copyFrom(T *const A, int lo, int hi);
	void expand();
public:
	my_Vector(int c = DEFAULT_CAPACTIY);
	my_Vector(T *A, Rank lo, Rank hi);
	my_Vector(T *A, Rank n);
	my_Vector(my_Vector<T> const &V, Rank lo, Rank hi);
	my_Vector(my_Vector<T> const &V);
	~my_Vector() 
	{
		delete[] _elem;
	};
	Rank size() const 
	{ 
		return _size;
	}
	bool empty() const 
	{ 
		return _size <= 0; 
	}
	int disordered() const;
	Rank find(T const &e) const { return find(e, 0, (Rank)_size); }
	Rank find(T const &e, Rank lo, Rank hi) const;
	Rank search(T const &e) const { return (0 >= _size) ? -1 : search(e, (Rank)0, (Rank), _size); }
	Rank search(T const &e, Rank lo, Rank hi) const;

	my_Vector<T> my_Vector<T>::operator=(my_Vector<T> const &V);
};


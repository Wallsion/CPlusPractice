#include <iostream>
using std::ostream;
template <class type>
class Complex
{
public:
	void setValue(const type &i, const type &j){real = i; vitual = j;}
	void setValue(const Complex<type> &tem){real = tem.getRealValue(); vitual = tem.getVirtualValue();}
	type getRealValue() const {return real;}
	type getVirtualValue()const {return vitual;}
	Complex():real(0),vitual(0){}
	Complex(type i, type j){real = i; vitual = j;}
	Complex(const Complex<type> &tem){real = tem.getRealValue(); vitual = tem.getVirtualValue();}
	Complex<type>& operator =(const Complex<type> &tem){this->setValue(tem);return *this}
	bool operator ==(const Complex<type> &tem);
	bool operator >(const Complex<type> &tem);
	bool operator <(const Complex<type> &tem);
	Complex<type> operator +(const Complex<type> &tem);
	Complex<type> operator -(const Complex<type> &tem);
	Complex<type> operator *(const Complex<type> &tem);
private:
	type real;
	type vitual;
};
template <class type>
bool Complex<type>::operator ==(const Complex<type> &tem)
{
	if(tem.getRealValue() == real && tem.getVirtualValue() == vitual)
		return true;
	else
		return false;
}

template <class type>
bool Complex<type>::operator >(const Complex<type> &tem)
{
	if(real * real + vitual * vitual > tem.getRealValue() * tem.getRealValue() + tem.getVirtualValue() *tem.getVirtualValue() )
		return true;
	else
		return false;
}

template <class type>
bool Complex<type>::operator <(const Complex<type> &tem)
{
	if(real * real + vitual * vitual < tem.getRealValue() * tem.getRealValue() + tem.getVirtualValue() *tem.getVirtualValue() )
		return true;
	else
		return false;
}

template <class type>
Complex<type> Complex<type>::operator +(const Complex<type> &tem)
{
	Complex<type> tem1;
	tem1.setValue(tem.getRealValue() + real,tem.getVirtualValue() + vitual);
	return tem1;
}

template <class type>
Complex<type> Complex<type>::operator -(const Complex<type> &tem)
{
	Complex<type> tem1;
	tem1.setValue(real - tem.getRealValue(),vitual - tem.getVirtualValue());
	return tem1;
}

template <class type>
Complex<type> Complex<type>::operator *(const Complex<type> &tem)
{
	Complex<type> tem1;
	type i,j;
	i = real * tem.getRealValue() + vitual * tem.getVirtualValue();
	j = real * tem.getVirtualValue() + vitual * tem.getRealValue();
	tem1.setValue(i,j);
	return tem1;
}


template <typename T>
ostream& operator<<(ostream &os,Complex<T> complex)
{
	T i,j;
	i = complex.getRealValue();
	j = complex.getVirtualValue();
	if(j > 0)
	{
		os << i << "+" << j << "i";
	}
	else if(j > 0)
	{
		os << i << "-" << -j << "i";
	}
	else
	{
		os << i;
	}
	return os;
}

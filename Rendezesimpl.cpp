#include "Rendezes.h"

using namespace std;

template class BuborekosRendezes<int>;
template class QuickSort<int>;
template class BuborekosRendezesT<int>;
template class QuickSortT<int>;
template class BuborekosRendezes<unsigned int>;
template class QuickSort<unsigned int>;
template class BuborekosRendezesT<unsigned int>;
template class QuickSortT<unsigned int>;
template class BuborekosRendezes<float>;
template class QuickSort<float>;
template class BuborekosRendezesT<float>;
template class QuickSortT<float>;
template class BuborekosRendezes<double>;
template class QuickSort<double>;
template class BuborekosRendezesT<double>;
template class QuickSortT<double>;
template class BuborekosRendezes<long long>;
template class QuickSort<long long>;
template class BuborekosRendezesT<long long>;
template class QuickSortT<long long>;
template class BuborekosRendezes<unsigned long long>;
template class QuickSort<unsigned long long>;
template class BuborekosRendezesT<unsigned long long>;
template class QuickSortT<unsigned long long>;

Stat::Stat()
{
	init();
}

void Stat::init()
{
	ido = 0;
	nHasonlit = 0;
	nCsere = 0;
}

void Stat::incHasonlit()
{
	++nHasonlit;
}

void Stat::incCsere()
{
	++nCsere;
}

unsigned int Stat::getCsere()
{
	return nCsere;
}

unsigned int Stat::getHasonlit()
{
	return nHasonlit;
}

unsigned int Stat::getIdo()
{
	return ido;
}

void Stat::kezd()
{
	c = clock();
}

void Stat::vege()
{
	clock_t end = clock();
	end -= c;
	c = end;
	ido = (int)c;
}

template <class T>
bool BuborekosRendezes<T>::kisebb(T a, T b)
{
	return a < b;
}

template <class T>
void BuborekosRendezes<T>::csere(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
void BuborekosRendezes<T>::rendez(T* tomb, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (kisebb(tomb[i], tomb[j]))
			{
				csere(tomb[i], tomb[j]);
			}
		}
	}
}

template <class T>
bool QuickSort<T>::kisebb(T a, T b)
{
	return a < b;
}

template <class T>
void QuickSort<T>::csere(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
void QuickSort<T>::qsort(T* a, int bal, int jobb)
{
	if (bal < jobb)
	{
		int m = particional(a, bal, jobb);
		qsort(a, bal, m);
		qsort(a, m + 1, jobb);
	}
}

template <class T>
int QuickSort<T>::particional(T* a, int bal, int jobb)
{
	T pivot = a[bal];
	int i = bal;
	int j = jobb;
	do
	{
		while (kisebb(pivot, a[j]))
		{
			--j;
		}
		while (kisebb(a[i], pivot))
		{
			++i;
		}
		if (i < j)
		{
			csere(a[i], a[j]);
		}
	}
	while (i < j);
	return j;
}

template <class T>
void QuickSort<T>::rendez(T* tomb, int n)
{
	qsort(tomb, 0, n - 1);
}

template <class T>
bool BuborekosRendezesT<T>::kisebb(T a, T b)
{
	incHasonlit();
	return BuborekosRendezes<T>::kisebb(a, b);
}

template <class T>
void BuborekosRendezesT<T>::csere(T& a, T& b)
{
	incCsere();
	return BuborekosRendezes<T>::csere(a, b);
}

template <class T>
void BuborekosRendezesT<T>::rendez(T* tomb, int n)
{
	kezd();
	BuborekosRendezes<T>::rendez(tomb, n);
	vege();
}

template <class T>
bool QuickSortT<T>::kisebb(T a, T b)
{
	incHasonlit();
	return QuickSort<T>::kisebb(a, b);
}

template <class T>
void QuickSortT<T>::csere(T& a, T& b)
{
	incCsere();
	QuickSort<T>::csere(a, b);
}

template <class T>
void QuickSortT<T>::rendez(T* tomb, int n)
{
	kezd();
	QuickSort<T>::rendez(tomb, n);
	vege();
}
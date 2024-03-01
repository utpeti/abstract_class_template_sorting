#ifndef _RENDEZES_H_
#define _RENDEZES_H_
#include <ctime>

template <class T>
class Rendezes
{
protected:
    virtual bool kisebb(T a, T b) = 0;
    virtual void csere(T &a, T &b) = 0;
public:
    virtual void rendez(T *tomb, int n) = 0;
};

class Stat
{
private:
    unsigned int ido, nHasonlit, nCsere;
    std::clock_t c;

protected:
    void kezd();
    void vege();
    void init();
    void incHasonlit();
    void incCsere();

public:
    Stat();
    unsigned int getIdo();
    unsigned int getHasonlit();
    unsigned int getCsere();
};

template <class T>
class BuborekosRendezes : public Rendezes<T>
{
protected:
    bool kisebb(T a, T b);
    void csere(T &a, T &b);

public:
    void rendez(T *tomb, int n);
};

template <class T>
class BuborekosRendezesT : public BuborekosRendezes<T>, public Stat
{
protected:
    bool kisebb(T a, T b);
    void csere(T &a, T &b);


public:
    void rendez(T *tomb, int n);
};

template <class T>
class QuickSort : public Rendezes<T>
{
private:
    void qsort(T* a, int bal, int jobb);
    int particional(T *a, int bal, int jobb);

protected:
    bool kisebb(T a, T b);
    void csere(T &a, T &b);

public:
    void rendez(T *tomb, int n);

};

template <class T>
class QuickSortT : public QuickSort<T>, public Stat
{

protected:
    bool kisebb(T a, T b);
    void csere(T &a, T &b);

public:
    void rendez(T *tomb, int n);

};

#endif
#pragma once
#include <cmath>
#include <iostream>
#include <initializer_list>

using namespace std;

template <typename T>
class TVector
{
    template<typename K> friend TVector<K> v_sum(const TVector<K>& v1, const TVector<K>& v2);
    template<typename K> friend TVector<K> v_diff(const TVector<K>& v1, const TVector<K>& v2);
    template<typename K> friend double scalar(const TVector<K>& v1, const TVector<K>& v2);

protected:
    T* m_pdata;
    int m_size;

    void init()
    {
        m_size = 0;
        m_pdata = nullptr;
    }

public:
    TVector(const int& size = 0, const T* const pdata = nullptr);
    TVector(const TVector& rv);

    void out() const;

    int copy(const int& size, const T* const pdata);
    int copy(const TVector& rv);
    int move(TVector& temp);

    double module() const;
    void TV_sum(const TVector& rv);
    void TV_diff(const TVector& rv);

    void clear()
    {
        if (m_pdata != nullptr)
        {
            delete[] m_pdata;
        }
        init();
    }

    ~TVector() { clear(); }

    TVector& operator=(const TVector& rv)
    {
        cout << "copy=" << endl;
        if (this->m_pdata != rv.m_pdata)
        {
            copy(rv);
        }
        return *this;
    }

    double operator()() const
    {
        return module();
    }

    T& operator[](int index)
    {
        return this->m_pdata[index];
    }

    const T operator[](int index) const
    {
        return this->m_pdata[index];
    }

    TVector& operator+=(const TVector& rv)
    {
        this->TV_sum(rv);
        return *this;
    }

    TVector& operator-=(const TVector& rv)
    {
        this->TV_diff(rv);
        return *this;
    }

    TVector& operator=(TVector&& temp) noexcept
    {
        cout << "move=";
        if (this->m_pdata != temp.m_pdata)
        {
            move(temp);
        }
        return *this;
    }

    TVector(TVector&& rv) noexcept;
};

template <typename T>
TVector<T>::TVector(const int& size, const T* const pdata)
{
    init();
    copy(size, pdata);
}

template <typename T>
TVector<T>::TVector(const TVector& rv)
{
    init();
    copy(rv);
}

template <typename T>
TVector<T>::TVector(TVector&& rv) noexcept
{
    init();
    move(rv);
}

template <typename T>
void TVector<T>::out() const
{
    cout << "Num: " << m_size << " Data: ";
    for (int i = 0; i < m_size; i++)
        cout << m_pdata[i] << " ";
    cout << endl;
}

template <typename T>
int TVector<T>::copy(const int& size, const T* const pdata)
{

    if (m_pdata == pdata) return m_size;

    clear();
    m_pdata = new T[size];

    if (m_pdata)
    {
        for (int i = 0; i < size; i++)
            m_pdata[i] = pdata[i];
        m_size = size;
    }

    return m_size;
}

template <typename T>
int TVector<T>::copy(const TVector& rv)
{
    return copy(rv.m_size, rv.m_pdata);
}

template <typename T>
int TVector<T>::move(TVector& temp)
{
    if (m_pdata == temp.m_pdata) return m_size;

    clear();

    m_size = temp.m_size;
    m_pdata = temp.m_pdata;

    temp.init();
    return m_size;
}

template <typename T>
double TVector<T>::module() const
{
    return sqrt(scalar(*this, *this));
}

template <typename T>
void TVector<T>::TV_sum(const TVector& rv)
{
    this->copy(v_sum(*this, rv));
}

template <typename T>
void TVector<T>::TV_diff(const TVector& rv)
{
    this->copy(v_diff(*this, rv));
}

template<typename T>
TVector<T> v_sum(const TVector<T>& v1, const TVector<T>& v2)
{
    int max_size = max(v1.m_size, v2.m_size);
    int min_size = min(v1.m_size, v2.m_size);

    TVector<T> ans;
    ans.m_size = max_size;
    ans.m_pdata = new T[max_size];

    for (int i = 0; i < min_size; i++)
        ans.m_pdata[i] = v1.m_pdata[i] + v2.m_pdata[i];

    for (int i = min_size; i < v1.m_size; i++)
        ans.m_pdata[i] = v1.m_pdata[i];

    for (int i = min_size; i < v2.m_size; i++)
        ans.m_pdata[i] = v2.m_pdata[i];

    return ans;
}

template<typename T>
TVector<T> v_diff(const TVector<T>& v1, const TVector<T>& v2)
{
    int max_size = max(v1.m_size, v2.m_size);
    int min_size = min(v1.m_size, v2.m_size);

    TVector<T> ans;
    ans.m_size = max_size;
    ans.m_pdata = new T[max_size];

    for (int i = 0; i < min_size; i++)
        ans.m_pdata[i] = v1.m_pdata[i] - v2.m_pdata[i];

    for (int i = min_size; i < v1.m_size; i++)
        ans.m_pdata[i] = v1.m_pdata[i];

    for (int i = min_size; i < v2.m_size; i++)
        ans.m_pdata[i] = -v2.m_pdata[i];

    return ans;
}

template <typename T>
double scalar(const TVector<T>& v1, const TVector<T>& v2)
{
    double ans = 0;
    int min_size = min(v1.m_size, v2.m_size);

    for (int i = 0; i < min_size; i++)
        ans += v1.m_pdata[i] * v2.m_pdata[i];

    return ans;
}

template <typename T>
TVector<T> operator+(const TVector<T>& v1, const TVector<T>& v2)
{
    return v_sum(v1, v2);
}

template <typename T>
TVector<T> operator-(const TVector<T>& v1, const TVector<T>& v2)
{
    return v_diff(v1, v2);
}

template <typename T>
double operator*(const TVector<T>& v1, const TVector<T>& v2)
{
    return scalar(v1, v2);
}

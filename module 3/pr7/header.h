#pragma once
#include <cmath>
#include <iostream>
#include <initializer_list>

template <typename T>
class TVector
{
    template<typename K> friend TVector<K> v_diff(const TVector<K>& v1, const TVector<K>& v2);
    template<typename K> friend TVector<K> v_sum(const TVector<K>& v1, const TVector<K>& v2);
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
    typedef T* iterator;

    iterator begin()
    {
        return m_pdata;
    }

    iterator end()
    {
        return m_pdata + m_size;
    }

    TVector(std::initializer_list<T> list)
    {
        m_size = list.size();
        m_pdata = new T[m_size];
        int i = 0;
        for (auto k : list)
        {
            m_pdata[i] = k;
            i++;
        }
    }

    TVector(TVector&& v);
    ~TVector() { clear(); }

    void clear()
    {
        if (m_pdata != nullptr)
            delete[] m_pdata;
        init();
    }

    TVector(const int& size = 0, const T* const p = nullptr);
    TVector(const TVector& v);

    int copy(const int& n, const T* const b);
    int copy(const TVector& v);
    int move(TVector& v);

    void out() const;

    double module() const;

    void TV_sum(const TVector& t);
    void TV_diff(const TVector& t);

    TVector& operator+=(const TVector& t)
    {
        TV_sum(t);
        return *this;
    }

    TVector& operator-=(const TVector& t)
    {
        TV_diff(t);
        return *this;
    }

    TVector& operator=(TVector&& t)
    {
        if (this->m_pdata != t.m_pdata)
            move(t);
        return *this;
    }

    TVector& operator=(const TVector& t)
    {
        if (this->m_pdata != t.m_pdata)
            copy(t);
        return *this;
    }

    T& operator[](int index) { return m_pdata[index]; }
    const T operator[](int index) const { return m_pdata[index]; }

    double operator()() const { return module(); }
};

template <typename T>
TVector<T> operator+(const TVector<T>& a, const TVector<T>& b)
{
    return v_sum(a, b);
}

template <typename T>
TVector<T> operator-(const TVector<T>& a, const TVector<T>& b)
{
    return v_diff(a, b);
}

template <typename T>
double operator*(const TVector<T>& a, const TVector<T>& b)
{
    return scalar(a, b);
}

template <typename T>
TVector<T> v_diff(const TVector<T>& v1, const TVector<T>& v2)
{
    TVector<T> ans;
    ans.m_size = std::max(v1.m_size, v2.m_size);
    int t = std::min(v1.m_size, v2.m_size);
    ans.m_pdata = new T[ans.m_size];

    for (int i = 0; i < t; i++)
        ans.m_pdata[i] = v1.m_pdata[i] - v2.m_pdata[i];

    for (int i = t; i < v1.m_size; i++)
        ans.m_pdata[i] = v1.m_pdata[i];

    for (int i = t; i < v2.m_size; i++)
        ans.m_pdata[i] = -v2.m_pdata[i];

    return ans;
}

template <typename T>
double scalar(const TVector<T>& v1, const TVector<T>& v2)
{
    double ans = 0;
    int t = std::min(v1.m_size, v2.m_size);
    for (int i = 0; i < t; i++)
        ans += v1.m_pdata[i] * v2.m_pdata[i];
    return ans;
}

template <typename T>
TVector<T> v_sum(const TVector<T>& v1, const TVector<T>& v2)
{
    TVector<T> ans;
    ans.m_size = std::max(v1.m_size, v2.m_size);
    int t = std::min(v1.m_size, v2.m_size);
    ans.m_pdata = new T[ans.m_size];

    for (int i = 0; i < t; i++)
        ans.m_pdata[i] = v1.m_pdata[i] + v2.m_pdata[i];

    for (int i = t; i < v1.m_size; i++)
        ans.m_pdata[i] = v1.m_pdata[i];

    for (int i = t; i < v2.m_size; i++)
        ans.m_pdata[i] = v2.m_pdata[i];

    return ans;
}

template <typename T>
TVector<T>::TVector(TVector<T>&& v)
{
    init();
    m_pdata = v.m_pdata;
    m_size = v.m_size;
    v.init();
}

template <typename T>
TVector<T>::TVector(const TVector<T>& v)
{
    init();
    copy(v);
}

template <typename T>
TVector<T>::TVector(const int& size, const T* const p)
{
    init();
    copy(size, p);
}

template <typename T>
int TVector<T>::copy(const int& n, const T* const b)
{
    if (m_pdata == b)
        return m_size;

    clear();
    m_pdata = new T[n];

    if (m_pdata)
    {
        for (int i = 0; i < n; i++)
            m_pdata[i] = b[i];
        m_size = n;
    }

    return m_size;
}

template <typename T>
int TVector<T>::copy(const TVector& v)
{
    return copy(v.m_size, v.m_pdata);
}

template <typename T>
int TVector<T>::move(TVector& v)
{
    if (v.m_pdata == m_pdata)
        return m_size;

    clear();
    m_size = v.m_size;
    m_pdata = v.m_pdata;
    v.init();
    return m_size;
}

template <typename T>
void TVector<T>::out() const
{
    std::cout << "Num: " << m_size << " Data: ";
    for (int i = 0; i < m_size; i++)
    {
        std::cout << (double)m_pdata[i];
        if (i < m_size - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

template <typename T>
double TVector<T>::module() const
{
    return std::sqrt(scalar(*this, *this));
}

template <typename T>
void TVector<T>::TV_sum(const TVector& t)
{
    copy(v_sum(*this, t));
}

template <typename T>
void TVector<T>::TV_diff(const TVector& t)
{
    copy(v_diff(*this, t));
}

#include <iostream>

#include <array>
#include <cassert>

template <typename T1, unsigned int S>
class VectorND {
public:

    VectorND()
    {}

    template<class T, class... A>
    VectorND(const T x, A... args)
    {
        fill(x, args...);
    }

    template <typename T2>
    T1 operator*(const VectorND<T2, S> &other)
    {
        // TODO: Skalar-Produkt implementieren
        T1 ret = 0;

         for (int i=0; i<S; i++){
            ret += (mData[i] * other[i]);
        }

        return ret;
    }

    void clear()
    {
        for(auto &val : mData)
            val = 0;
    }

    template <typename T2>
    VectorND<T1, S> operator+(const VectorND<T2, S> &other)
    {
        // TODO: Vektor Addition implementieren
        VectorND<T1, S> res;
        res.clear();
        for (int i=0; i<S; i++){
            res[i] = (mData[i] + other[i]);
        }

        return res;
    }

    T1 operator[](const unsigned int idx) const
    {
        // TODO: Code für Subscript-Operator implementieren
        return mData[idx];
    }

    T1& operator[](const unsigned int idx)
    {
        // TODO: Code für Subscript-Operator implementieren
        return mData[idx];
    }

    unsigned int size() const
    {   return S;    }

    void print()
    {
        for(auto i=0 ; i<mData.size() ; i++)
        {
            std::cout << mData[i] << std::endl;
        }
    }

private:

    // TODO: Implementierung von der fill Methode, die nur vom Konstruktor
    // aufgerufen wird
    void fill()
    {}

    template<typename TYPE, typename... A>
    void fill(const TYPE x, A... args){
        mData[mSizeSentinel++] = x;

        fill(args...);
    }


    std::array<T1, S> mData;
    int mSizeSentinel = 0;
};

int main()
{
    VectorND<int, 3> x1(1,2,3);
    VectorND<int, 3> x2(1,2,3);

    VectorND<int, 5> y1(1,2,3,4,5);
    VectorND<int, 5> y2(1,2,3,4,5);

    auto x3 = x1+x2;
    auto y3 = y1+y2;

    x3.print();
    y3.print();

    std::cout << x1*x2 << std::endl;
    std::cout << y1*y2 << std::endl;


    return 0;
}

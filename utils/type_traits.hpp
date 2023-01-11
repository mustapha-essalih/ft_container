#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP


#include <iomanip>
#include <cstddef>
#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>     
#include<iterator>
#include <utility> 
 
namespace ft
{
    template< typename T1, typename T2 >
        class pair
        {
            typedef T1 first_type;
            typedef T2 second_type;

            public:
                first_type  first;
                second_type  second;

                pair() : first(), second() { }

                template<class U, class V>
                pair (const ft::pair<U,V> & pr):first(pr.first),second(pr.second)
                {
                }
                pair( const first_type & a, const second_type & b ):first(a),second(b)
                {
                }
                
    //             template<class _U1, class _U2>
    //      pair&
    //      operator=(pair<_U1, _U2>& __p)
    //  {
    //    first = std::move(__p.first);
    //    second = std::move(__p.second);
    //    return *this;
    //  }
  
                ~pair()
                {

                }
        };

        template <typename T1, typename T2> 
        pair<T1,T2> make_pair (T1 x, T2 y)
        {
            return pair<T1,T2>(x,y);
        }

        template <typename T1, typename T2>
        bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        {return lhs.first==rhs.first && lhs.second==rhs.second; }

        template <typename T1, typename T2>
        bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(lhs==rhs); }

        template <typename T1, typename T2>
        bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); } // if lhs.first==rhs.first wiil pass next statemnet

        template <typename T1, typename T2>
        bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(rhs<lhs); }// here rhs > lhs

        template <typename T1, typename T2>
        bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return rhs<lhs; }

        template <typename T1, typename T2>
        bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(lhs<rhs); }


};



#endif 
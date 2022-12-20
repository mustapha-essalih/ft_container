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
#include "type_traits.hpp"

#include <utility>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;
using std::pair;

namespace ft
{
    template< typename T1, typename T2 >
        class pair
        {
            typedef T1 first_type;
            typedef T2 second_type;

            public:
                T1  first;
                T2  second;

                pair():first(T1()),second(T2())//to initialze template variable in c11
                {
                    // cout << "0\n";
                }

                template<class U, class V>
                pair (const pair<U,V> & pr):first(pr.first),second(pr.second)
                {
                    // cout << "1\n";
                     
                }
                pair( const T1& a, const T2& b ):first(a),second(b)
                {
                    // cout << "2\n";
                    // *this = *this;

                }
                 
                pair& operator = ( const pair  & other )
                {
                    // cout << "3\n";

                    if(this != &other)
                    {
                        // this->first = other.first;
                        this->second = other.second;
                    }
                    return *this;
                }
                ~pair()
                {

                }
        };
        template <typename T1, typename T2> 
        pair<T1,T2> make_pair (T1 x, T2 y)
        {
            // call paramitraze constructor
            return pair<T1,T2>(x,y);
        }

        template <typename T1, typename T2>
        bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return lhs.first==rhs.first && lhs.second==rhs.second; }

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

    // test pair handle pair

};










// 





#endif
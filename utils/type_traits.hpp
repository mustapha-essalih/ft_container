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


  template<class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1, 
            InputIt2 first2)
    {
        for (; first1 != last1; ++first1, ++first2) {
            if (!(*first1 == *first2)) {
                return false;
            }
        }
        return true;
    }
    
    template<class InputIt1, class InputIt2, class BinaryPredicate>
    bool equal(InputIt1 first1, InputIt1 last1, 
            InputIt2 first2, BinaryPredicate p)
    {
        for (; first1 != last1; ++first1, ++first2) {
            if (!p(*first1, *first2)) {
                return false;
            }
        }
        return true;
    }

    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
        {
            if (*first1 < *first2)
                return true;
            if (*first2 < *first1)
                return false;
        }
    
        return (first1 == last1) && (first2 != last2);
    }
    
    template<class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2, Compare comp)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
        {
            if (comp(*first1, *first2))
                return true;
            if (comp(*first2, *first1))
                return false;
        }
    
        return (first1 == last1) && (first2 != last2);
    }

        template <class _T1, class _T2>
        struct pair
        {
            typedef _T1 first_type;
            typedef _T2 second_type;
            
            first_type first;
            second_type second;

            pair() : first(), second() {}
            pair(first_type const &_t1, second_type const &_t2 = second_type()) : first(_t1), second(_t2) {}

            template <class _U1, class _U2>
            pair(const pair<_U1, _U2>& _rhs) : first(_rhs.first), second(_rhs.second) {}
            
            pair& operator=(const pair& _rhs)
            {
                first = _rhs.first;
                second = _rhs.second;
                return (*this);
            }
            void swap(pair& _rhs)
            {
                std::swap(first,  _rhs.first);
                std::swap(second, _rhs.second);
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

        template <typename T>
struct is_integral {
  static const bool value = false;
};

template <>
struct is_integral<bool> {
  static const bool value = true;
};

template <>
struct is_integral<char> {
  static const bool value = true;
};

template <>
struct is_integral<signed char> {
  static const bool value = true;
};

template <>
struct is_integral<unsigned char> {
  static const bool value = true;
};

template <>
struct is_integral<short> {
  static const bool value = true;
};

// ... more specializations for other integral types ...
// template <>
// struct is_integral<short> {
//   static const bool value = true;
// };

template <>
struct is_integral<unsigned short> {
  static const bool value = true;
};

template <>
struct is_integral<int> {
  static const bool value = true;
};

template <>
struct is_integral<unsigned int> {
  static const bool value = true;
};

template <>
struct is_integral<long> {
  static const bool value = true;
};

template <>
struct is_integral<unsigned long> {
  static const bool value = true;
};

template <>
struct is_integral<long long> {
  static const bool value = true;
};

template <>
struct is_integral<unsigned long long> {
  static const bool value = true;
};

        template<bool Cond, class T = void> struct enable_if {};
        template<class T> struct enable_if<true, T> { typedef T type; };
};



#endif 

#ifndef STD_MECHANISM_HPP
#define STD_MECHANISM_HPP


// If B is true, std::enable_if has a public member typedef type, equal to T; otherwise, there is no member typedef.


namespace ft{
// check if T is int data type will create type = int it is  the return value int of the is_odd(), if T not int value will not compile

    
    template<bool B, class T = void>
    struct enable_if {};
    
    template<class T>
    //     non-type template
    struct enable_if<true, T>  
    { 
        typedef T type; 
    };

    template<typename T>

    struct is_integral { enum{value = false};};


    // empty  template
    template<> struct is_integral<char> { enum{value = true};};
    template<> struct is_integral<unsigned char>  { enum{value = true};};
    template<> struct is_integral<unsigned short> { enum{value = true};};
    template<> struct is_integral<unsigned int> { enum{value = true};};
    template<> struct is_integral<unsigned long> { enum{value = true};};

    template<> struct is_integral<signed char> { enum{value = true};};
    template<> struct is_integral<short> { enum{value = true};};
    template<> struct is_integral<int> { enum{value = true};};
    template<> struct is_integral<long> { enum{value = true};};

     template<> struct is_integral<bool> { enum{value = true};};
    
    template<> struct is_integral<wchar_t> { enum{value = true};};
    
    
    
    template<> struct is_integral<char16_t> { enum{value = true};};
    
    template<> struct is_integral<char32_t> { enum{value = true};};


    template<class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1,  InputIt2 first2)
    {
        while (first1 != last1)
        {
            if (*first1 != *first2)
                return false;
            ++first1;
            ++first2;
        }
    
        return true;
    }

    template<class InputIt1, class InputIt2, class BinaryPredicate>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if (!pred(*first1, *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

}








#endif
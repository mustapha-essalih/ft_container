#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP


// is an interface 
 


namespace ft
{
    
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : input_iterator_tag {};
    struct bidirectional_iterator_tag : forward_iterator_tag {};
    struct random_access_iterator_tag : bidirectional_iterator_tag {};


    template <class Iterator>
    struct iterator_traits // to call this you will pass T
    {
         
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };


    template <class T>
    struct iterator_traits<T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template <class T>
    struct iterator_traits<const T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef random_access_iterator_tag iterator_category;
    };



}



#endif
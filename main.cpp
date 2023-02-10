
#include <iostream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <memory>
#include <stack>
#include <vector>
 



using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;


#include "map/map.hpp"
#include "vector/vector.hpp"

#define _ratio 5

 
// use key compar to comapar evryting
// in iterator node privete

// implement std::key_comp
// implement std::map::value_comp


void func()
{
	system("leaks ft_container");
}

//  // compar iterator with const iterator
// // handle const vector iterator 

 

template <typename T>
std::vector<int> iterator_test(ft::vector<T> vector) {
    typename ft::vector<T>::iterator it;
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
        vector.push_back(i);
    // it = vector.begin();
    
    // v.push_back(*(++it));
    // v.push_back(*(--it));
    // v.push_back(*(it + 1));
    // it += 1;
    // v.push_back(*(it - 1));
    // it -= 1;
    // v.push_back(*it);
     return v;
}

template <typename T>
std::vector<int> resize_test(ft::vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(15300 * _ratio, T());
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    v.push_back(vector[65]);
    return v;
}


int main ()
{
    ft::vector<int> myvector;

  // set some initial content:
    for (int i=1;i<10;i++) myvector.push_back(i);

   
    ft::vector<int>::iterator it = myvector.begin();

    *it = 10;
}


 
 
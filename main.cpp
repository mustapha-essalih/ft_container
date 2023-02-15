
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
#include "stack/stack.hpp"
#include "set/set.hpp"
 

 
// use key compar to comapar evryting
// in iterator node privete

// implement std::key_comp
// implement std::map::value_comp
#define _ratio 5

void func()
{
	system("leaks ft_container");
}

 
template <class T>
std::vector<int> swap_test(ft::set<T> st) {
    std::vector<int> v;
    for (int i = 0; i < 25 * _ratio; ++i)
        st.insert(i);
    ft::set<T> st2;
    for (int i = 25 * _ratio; i < 35 * _ratio; ++i)
        st.insert(i);
    long *adr1 = reinterpret_cast<long *>(&st);
    long *adr2 = reinterpret_cast<long *>(&st2);
    st.swap(st2);
    if (reinterpret_cast<long *>(&st) == adr1 && reinterpret_cast<long *>(&st2) == adr2)
    	v.push_back(1);
    v.push_back(st2.size());
    typename ft::set<T>::iterator it = st2.begin();
    for (; it != st2.end(); ++it) {
        v.push_back(*it);
    }
    ft::swap(st, st2);
	std::cout << st2.size() << std::endl;
		std::cout << "ok\n";
    typename ft::set<T>::iterator it2 = st2.begin();
    for (; it2 != st2.end(); ++it2) {
        v.push_back(*it2);
    }
    return v;
}


int main ()
{
  	 
	ft::set<int> first ;
	swap_test(first);
	// std::cout << "first contains:";
	// for (ft::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// std::cout << "second contains:";
	// for (ft::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';


  return 0;
}
 
 
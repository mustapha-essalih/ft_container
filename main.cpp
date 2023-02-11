
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
 

 
// use key compar to comapar evryting
// in iterator node privete

// implement std::key_comp
// implement std::map::value_comp
#define _ratio 5

void func()
{
	system("leaks ft_container");
}
 

template <class T, class V>
        std::vector<int> size_test(ft::map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 100 * _ratio; ++i, ++j)
        mp.insert(ft::make_pair(i, j));
    v.push_back(mp.size());
    for (int i = 0; i < 43 * _ratio; ++i)
        mp.erase(i);
    v.push_back(mp.size());
    return v;
} 
int main ()
{   
	ft::map<char,int> mymap;	 
	 
	size_test(mymap);
	
}


 
 
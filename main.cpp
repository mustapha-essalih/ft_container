
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
#define _ratio 100

void func()
{
	system("leaks ft_container");
}
 
template <class T, class V>
std::vector<int> swap_test(ft::map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 0; i < 25 * _ratio; ++i, ++j)
        mp.insert(ft::make_pair(i, j));
    ft::map<T, V> mp2;
    for (int i = 25 * _ratio, j = 0; i < 35 * _ratio; ++i, --j)
        mp.insert(ft::make_pair(i, j));
    long *adr1 = reinterpret_cast<long *>(&mp);
    long *adr2 = reinterpret_cast<long *>(&mp2);
    
    mp.swap(mp2);
    

    if (reinterpret_cast<long *>(&mp) == adr1 && reinterpret_cast<long *>(&mp2) == adr2)
    	v.push_back(1);
    v.push_back(mp2.size());
    typename ft::map<T, V>::iterator it = mp2.begin();
    for (; it != mp2.end(); ++it) {
        v.push_back(it->first);
        v.push_back(it->second);
    }
    std::swap(mp, mp2);
    typename ft::map<T, V>::iterator it2 = mp2.begin();
    for (; it2 != mp2.end(); ++it2) {
        v.push_back(it2->first);
        v.push_back(it2->second);
    }
    return v;
}

 
int main ()
{   

	ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

	//  atexit(func);
}


 
 
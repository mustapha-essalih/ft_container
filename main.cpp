
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

template<typename T>
void fillMap(ft::map<int,int,T> &mp) {
	mp.insert(ft::make_pair(16, 3));
	mp.insert(ft::make_pair(8, 3));
	mp.insert(ft::make_pair(23, 3));
	mp.insert(ft::make_pair(7, 3));
	mp.insert(ft::make_pair(19, 3));
	mp.insert(ft::make_pair(29, 3));
	mp.insert(ft::make_pair(41, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(11, 3));
}

std::vector<int> comparator_test(ft::map<int,int> mp) {
    std::vector<int> v;
    fillMap(mp);
    for (ft::map<int,int>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
    for (ft::map<int,int>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
    ft::map<int, int, std::greater<int> > mp1;
    fillMap(mp1);
    v.push_back(mp1.begin()->first);
    mp1.erase(41);
    v.push_back(mp1.begin()->first);
    mp1.erase(29);
    v.push_back(mp1.begin()->first);
    ft::map<int, int, std::greater<int> > mp2;
    mp2.insert(ft::make_pair(3, 3));
    v.push_back(mp2.begin()->first);
    mp2.erase(3);
    if (mp2.begin() == mp2.end())
        v.push_back(1);
    ft::map<int, int, std::plus<int> > mp3;
    fillMap(mp3);
    // for ( ft::map<int,int>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
    // for ( ft::map<int,int>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int, std::minus<int> > mp4;
    // fillMap(mp4);
    // for ( ft::map<int,int>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
    // for ( ft::map<int,int>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int, std::greater_equal<int> > mp5;
    // fillMap(mp5);
    // for ( ft::map<int,int>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
    // for ( ft::map<int,int>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int, std::multiplies<int> > mp6;
    // fillMap(mp6);
    // for ( ft::map<int,int>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
    // for ( ft::map<int,int>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int, std::bit_xor<int> > mp7;
    // fillMap(mp7);
    // for ( ft::map<int,int>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
    // for ( ft::map<int,int>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
    // std::map<int, int, std::logical_and<int> > mp8;
     
    // fillMap(mp8);
    // for ( std::map<int,int>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
    // for ( std::map<int,int>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
    // v.push_back(mp1.size());

    return v;
}
 
int main ()
{   

	ft::map<int,int> mymap;
comparator_test(mymap);
	 atexit(func);
}


 
 
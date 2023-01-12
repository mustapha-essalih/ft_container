#include <cstddef>
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



using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;



#include "map/map.hpp"

 // handle const_reverse_iterator operators


void func()
{
	system("leaks ft_container");
}


int main()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	// it=mymap.find('b');
	// mymap.erase (it);                   // erasing by iterator

	// mymap.erase ('c');                  // erasing by key

	it=mymap.find ('b');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	// for (it=mymap.begin(); it!=mymap.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';

	










	// atexit(func);
}
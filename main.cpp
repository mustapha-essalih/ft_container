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
	ft::map<int,int>  m;
	// ft::map<int,int>  m1;

	 
	m.insert(ft::make_pair<int,int>(10,1000));
	 
	m.insert(ft::make_pair<int,int>(20,2000));


	m.remove(ft::make_pair<int,int>(10,1000));
	m.remove(ft::make_pair<int,int>(20,2000));// sigfault in this case
	// ft::map<int,int>::const_reverse_iterator rit;
	atexit(func);
} 
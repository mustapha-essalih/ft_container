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
	 
 
	m.insert(ft::make_pair<int,int>(10,1000));
	
	// m.insert(ft::make_pair<int,int>(19,2000));

	 
	// m.insert(ft::make_pair<int,int>(109,2000));
	// m.insert(ft::make_pair<int,int>(-4,2000));
	// m.insert(ft::make_pair<int,int>(-9,2000));
	// m.insert(ft::make_pair<int,int>(155,2000));
	// m.insert(ft::make_pair<int,int>(15,2000));

	  
 	// m.remove(10);

	// m.remove(19);
	// m.remove(109);
	// m.remove(-4);
	// m.remove(-9);
	// m.remove(15);
	// m.remove(155);
	// m.remove(ft::make_pair<int,int>(-9,2000));
	// m.remove(ft::make_pair<int,int>(155,2000));
	// m.remove(ft::make_pair<int,int>(15,2000));
	 

 
	// m.remove(std::make_pair<int,int>(-4,2000));
	// m.remove(std::make_pair<int,int>(-4,2000));
	// m.clear();
	// m1 = m;

	// cout << m.size() << endl;
	// m1.clear();
	 
	atexit(func);
} 
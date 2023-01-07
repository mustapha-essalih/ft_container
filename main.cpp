
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
  

#include "avl.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"
#include "map.hpp"

int main()
{
	ft::map<int,int> mymap;
  ft::map<int,int>::const_iterator it;

  	mymap.insert(ft::make_pair<int,int>(10,1000));
	mymap.insert(ft::make_pair<int,int>(20,2000));
	mymap.insert(ft::make_pair<int,int>(30,3000));
	mymap.insert(ft::make_pair<int,int>(5,3000));

	  std::cout << "a => " << mymap.find(10)->second << '\n';

	
	return 0;	
}

	
  	// ft::map<int,int> m;

	// m.insert(ft::make_pair<int,int>(10,1000));
	// m.insert(ft::make_pair<int,int>(20,2000));
	// m.insert(ft::make_pair<int,int>(30,3000));
	// m.insert(ft::make_pair<int,int>(5,3000));


	// std::map<int,int> m;

	// m.insert(std::make_pair<int,int>(10,1000));
	// m.insert(std::make_pair<int,int>(20,2000));
	// m.insert(std::make_pair<int,int>(30,3000));
    

	
	
	// cout << rev_until->first << endl;

//   while (rev_from != rev_until) {
//     std::cout << ' ' << *rev_from;
//     rev_from++;
//   }
	// iter_type it = rev_begin.base();

	// // --it;
	// cout << it->first << endl;

    // map<char, int> m;

	// m['a'] =  1;
	// m['b'] =  2;
	// m['c'] =  3;
	// m['d'] =  4;
	// m['e'] =  5;
         
	// std::map<char,int>::reverse_iterator it = m.rbegin();
   	// for (; it != m.rend(); ++it)
    // 	cout << it->first << " = " << it->second << endl;
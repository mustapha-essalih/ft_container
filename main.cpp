
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


// suhould handle const iterator

int main()
{ 
 
	std:: map<int, int> mp;
  
    // insert elements in random order
    mp.insert(std::make_pair<int,int>(12,120));
    mp.insert(std::make_pair<int,int>(11,11));
    mp.insert(std::make_pair<int,int>(15,50));
    mp.insert(std::make_pair<int,int>(14,40));
   
    // when 11 is present
	std::map<int,int>::iterator it = mp.upper_bound(11);
    cout << "The upper bound of key 11 is ";
    cout << (*it).first << " " << (*it).second << endl;
  
    // when 13 is not present
    it = mp.upper_bound(13);
    cout << "The upper bound of key 13 is ";
    cout << (*it).first << " " << (*it).second << endl;
  
    // when 17 is exceeds the maximum key, so size
        // of mp is returned as key and value as 0.
    it = mp.upper_bound(17);
    cout << "The upper bound of key 17 is ";
    cout << (*it).first << " " << (*it).second;

	return 0;	
}

	// std::map<int,int> mymap;
  	




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
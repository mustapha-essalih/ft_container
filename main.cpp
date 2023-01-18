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

#include "map.hpp"

 


int main()
{ 
   ft::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( ft::pair<char,int>('a',100) );
  mymap.insert ( ft::pair<char,int>('z',200) );
  
  // ft::pair<ft::map<char,int>::iterator,bool> ret;
  // ret = mymap.insert ( ft::pair<char,int>('z',500) );
  // if (ret.second==false) {
  //   std::cout << "element 'z' already existed";
  //   std::cout << " with a value of " << ret.first->second << '\n';
  // }

  // second insert function version (with hint position):
  ft::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

  
  // ft::map<char,int>::iterator i = mymap.end();
    // --i;
    // --i;
    // --i;
    // --i;
    // std::cout << i->first << " => " << i->second << '\n';

  // third insert function version (range insertion):
  // ft::map<char,int> anothermap;
  // anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  // std::cout << "mymap contains:\n";
  // for (it=mymap.begin(); it!=mymap.end(); ++it)
    // std::cout << it->first << " => " << it->second << '\n';

  // std::cout << "anothermap contains:\n";
  // for (it=anothermap.begin(); it!=anothermap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

 
}
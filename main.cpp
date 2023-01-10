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
 
 



int main()
{
    ft::map<int,int>  m;

    m.insert(ft::make_pair<int,int>(10,1000));
    m.insert(ft::make_pair<int,int>(20,2000));
    m.insert(ft::make_pair<int,int>(30,3000));
    m.insert(ft::make_pair<int,int>(40,4000));
    

  // show content:
  ft::map<int,int>::reverse_iterator rit;
  for (rit=m.rbegin(); rit!=m.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';
    

} 
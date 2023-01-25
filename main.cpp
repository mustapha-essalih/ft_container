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
  
#include "map.hpp"

int main()
{
    ft::map<int,int> m;
 
    m.insert(ft::make_pair<int,int>(10,100));
    m.insert(ft::make_pair<int,int>(20,100));
    m.insert(ft::make_pair<int,int>(30,100));

    ft::map<int,int>::const_iterator it = m.begin();
            
     
        while (it != m.end())
        {
            cout << it->first << endl;
            it++;
        }
        //     cout << it->first << endl;
        //     cout << it->first << endl;
         
         
}
 
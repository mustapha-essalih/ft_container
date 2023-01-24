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

    // m.insert(std::make_pair<int,int>(10,1000));
    // m.insert(std::make_pair<int,int>(20,1000));
    // m.insert(std::make_pair<int,int>(30,1000));
    

        m.insert(std::make_pair<int,int>(10,100));
        m.insert(std::make_pair<int,int>(20,100));
        m.insert(std::make_pair<int,int>(30,100));
        // m.insert(std::make_pair<int,int>(60,100));
        // m.insert(std::make_pair<int,int>(75,100));
        // m.insert(std::make_pair<int,int>(57,100));
 

        ft::map<int,int>::iterator it = m.end();
             
             
        while (it != m.begin())
        {
            cout << it->first << endl;
            --it;
        }
        //     cout << it->first << endl;
        //     cout << it->first << endl;
         
         
}
 
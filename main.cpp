#include <iostream>
#include <algorithm>
#include <utility>
#include <memory>
#include <stack>
#include <vector>
 


#include "map.hpp"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;


int main()
{
    ft::map<int,int> m;

    m.insert(std::make_pair<int,int>(10,1000));
    m.insert(std::make_pair<int,int>(20,2000));
    // m.insert(std::make_pair<int,int>(30,3000));

    m.get();
    // ft::map<int,int>::iterator it = m.begin();
    // ++it;
    // cout << it->first << endl;


    // m.insert(std::make_pair<int,int>(-10,20));
    // m.insert(std::make_pair<int,int>(100,20));
    // m.insert(std::make_pair<int,int>(130,20));
    // m.insert(std::make_pair<int,int>(-1,20));
    // m.insert(std::make_pair<int,int>(-2,20));
    // m.insert(std::make_pair<int,int>(-3,20));
    // m.insert(std::make_pair<int,int>(232,20));
    // m.insert(std::make_pair<int,int>(-23,20));
 
    
}
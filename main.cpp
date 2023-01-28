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

	m.insert(ft::make_pair<int,int>(10,1000));
	m.insert(ft::make_pair<int,int>(20,2000));
	m.insert(ft::make_pair<int,int>(30,3000));

	 
	ft::map<int,int>::iterator it = m.begin();
	 
	
	m.insert(it,ft::make_pair<int,int>(15,1000));
	it = m.find(15);
	m.insert(it,ft::make_pair<int,int>(16,1000));
 
 
}
 
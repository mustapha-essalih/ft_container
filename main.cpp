
#include <iostream>
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


#include "map/map.hpp"
#include "vector/vector.hpp"

 
// use key compar to comapar evryting
// in iterator node privete

// implement std::key_comp
// implement std::map::value_comp


void func()
{
	system("leaks ft_container");
}

 // compar iterator with const iterator
// handle const vector iterator 
int main ()
{ 
	 
	 ft::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  std::cout << "myvector contains:";
  for (int i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
 
}


// atexit(func);


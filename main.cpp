
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

//  // compar iterator with const iterator
// // handle const vector iterator 
int main ()
{
    ft::vector<int> myints;
    
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i=0; i<10; i++) myints.push_back(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.insert (myints.end(),10,100);
    std::cout << "2. size: " << myints.size() << '\n';

    myints.pop_back();
    std::cout << "3. size: " << myints.size() << '\n';

    atexit(func);
}


 
 
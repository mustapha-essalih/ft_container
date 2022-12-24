#include "avl.hpp"

#include "type_traits.hpp"
#include "map.hpp"




/*
    should handle this :
std::map<int,int>m;

    m[1] = 10;
    // m[2] = 10;
    std::map<int,int>::iterator it = m.begin();

    cout << it->first << " " << it->second << endl;

    ++it;
    
    cout << it->first << " " << it->second << endl;
*/






int main()
{
    // copy assignemnt ovearloding
    // copy constructor

    ft::map<int,int> mymap;

    // mymap['b'] = 100;
    // mymap['a'] = 200;
    // mymap['c'] = 300;

    ft::map<int,int>::iterator it1 = mymap.begin();

    ft::map<int,int>::iterator it;
    
    it = it1;

    // ++it;
    // ++it1;
    cout << it->first << " " << it->second << endl;
    // // cout << it->first << endl;

    // ft::map<int,int> m;
    
    // ft::map<int,int>::iterator it1 = m.begin();

    // ft::map<int,int>::iterator it(it1);
    // cout << it->first << " " << it->second << endl;

    // ++it;
    // cout << it->first << " " << it->second << endl;

    // ++it;
    // cout << it->first << " " << it->second << endl;

  // show content:
//   for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';


}
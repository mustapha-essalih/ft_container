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





// dont end() should print garbeg value
int main()
{
     ft::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( ft::pair<char,int>('a',100) );
  mymap.insert ( ft::pair<char,int>('c',200) );
  mymap.insert ( ft::pair<char,int>('b',200) );
  mymap.insert ( ft::pair<char,int>('d',200) );

    ft::map<char,int>::iterator it=mymap.begin();

    cout << it->first << endl;
    ++it;
    cout << it->first << endl;

// for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
// {
//     std::cout << it->first << " => " << it->second << '\n';
// }
   
}
    // mymap.insert(ft::pair<char,int>('a',100));
    
    // mymap.insert ( ft::pair<char,int>('z',200) );
    // mymap.insert ( ft::pair<char,int>('d',200) );
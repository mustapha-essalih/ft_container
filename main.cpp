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

    mymap.insert ( ft::pair<char,int>('a',100) );
    mymap.insert ( ft::pair<char,int>('z',200) );

    // mymap.insert ( ft::pair<char,int>('z',500) );

    ft::pair<ft::map<char,int>::iterator,bool> ret;
    
    ret = mymap.insert ( ft::pair<char,int>('z',500) );
    
    if (ret.second==false) {
         
        std::cout <<  ret.first->second << '\n';
    }
 
}
    // mymap.insert(ft::pair<char,int>('a',100));
    
    // mymap.insert ( ft::pair<char,int>('z',200) );
    // mymap.insert ( ft::pair<char,int>('d',200) );
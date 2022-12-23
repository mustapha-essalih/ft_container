#include "avl.hpp"

#include "type_traits.hpp"
#include "map.hpp"











int main()
{
    ft::map<int,int>m;

    ft::map<int,int>::iterator it = m.begin();

    cout << it->first << " " << it->second << endl;

    ++it;
    
    cout << it->first << " " << it->second << endl;

    ++it;
    cout << it->first << " " << it->second << endl;

    ++it;
    cout << it->first << " " << it->second << endl;

    ++it;
    
    cout << it->first << " " << it->second << endl;

    ++it;
    
    cout << it->first << " " << it->second << endl;
     
}
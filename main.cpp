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
    ft::map<int,int>m;

    // ft::map<int,int>::iterator it=m.begin();

    // cout << it->first << " => " << it->second << '\n';

    // ++it;
    // cout << it->first << " => " << it->second << '\n';
    // ++it;
    // cout << it->first << " => " << it->second << '\n';
    // ++it;
    // cout << it->first << " => " << it->second << '\n';
    // ++it;
    // cout << it->first << " => " << it->second << '\n';

     

    for (ft::map<int,int>::iterator it=m.begin(); it!=m.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
     
}
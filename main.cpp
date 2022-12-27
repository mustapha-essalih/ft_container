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

// handle iterators

// it => pointor

int main()
{
    // std::map<char,int> mymap;

    // mymap['b'] = 100;
    // mymap['a'] = 200;
    // mymap['c'] = 300;

    // std::map<char,int>::iterator it;
    
    // it = mymap.begin();
    
    // cout << it->first << endl;

    // for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';
    
    // dont forget copy constructor for iterartor(it)

    ft::map<int,int> m;
    
    ft::map<int,int>::iterator it;
    
    it = m.begin();

    ++it;

    

}


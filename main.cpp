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
    ft::map<int,int>m;

    ft::pair<ft::map<int,int>::iterator, bool> res;
    
    m.insert(ft::make_pair<int,int>(10,812));
    m.insert(ft::make_pair<int,int>(101,812));
    m.insert(ft::make_pair<int,int>(4,812));
    // m.insert(ft::make_pair<int,int>(-1,812));
    // m.insert(ft::make_pair<int,int>(0,812));
    // m.insert(ft::make_pair<int,int>(120,812));
    // m.insert(ft::make_pair<int,int>(210,812));
    // m.insert(ft::make_pair<int,int>(4,812));
    // m.insert(ft::make_pair<int,int>(-4,812));
    // m.insert(ft::make_pair<int,int>(-1,812));
    // m.insert(ft::make_pair<int,int>(555,812));
    // m.insert(ft::make_pair<int,int>(-12,812));
     
    ft::map<int,int>::iterator it; 
    // it=m.begin();

    // if(it!=m.end())
    //     cout << "it!=m.end()\n";
    // //     std::cout << it->first << " => " << it->second << '\n';
    // ++it;
    // if(it!=m.end())
    //     cout << "it!=m.end()\n";

    // ++it;
    // if(it!=m.end())
    //     cout << "it!=m.end()\n";
    // ++it;
    // if(it!=m.end())
    //     cout << "it!=m.end()\n";
    // std::cout << it->first << " => " << it->second << '\n';
        
    //     ++it;
    // std::cout << it->first << " => " << it->second << '\n';
    //     ++it;
    // std::cout << it->first << " => " << it->second << '\n';

    for (it=m.begin(); it!=m.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}



// how to compare value
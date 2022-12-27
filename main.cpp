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

    ft::map<char,int> mymap;

  // first insert function version (single parameter):
  ft::pair<ft::map<char,int>::iterator,bool> ret;

    ret =    mymap.insert ( ft::pair<char,int>('a',100) );
    
    cout << mymap.insert ( ft::pair<char,int>('a',100) ).second << endl;
        // std::cout << " with a value of " << ret.first->second << '\n';
    
    // mymap.insert ( ft::pair<char,int>('z',200) );
 
    

    // ret = mymap.insert ( ft::pair<char,int>('z',500) );
    
    // if (ret.second==false) {
        
         
    // }

    

}


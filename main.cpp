#include "avl.hpp"

#include "type_traits.hpp"
#include "map.hpp"




/*
    should handle this :
ft::map<int,int>m;

    m[1] = 10;
    // m[2] = 10;
    ft::map<int,int>::iterator it = m.begin();

    cout << it->first << " " << it->second << endl;

    ++it;
    
    cout << it->first << " " << it->second << endl;
*/





// dont end() should print garbeg value

// handle iterators

// it => pointor

// handle iterator --

// should handle end() => last element print garbeg value
// should handle iterator

int main()
{
    ft::map<int,int> mymap;

    mymap.insert(ft::make_pair<int,int>(10,10000));
    mymap.insert(ft::make_pair<int,int>(20,20000));
    // mymap.insert(ft::make_pair<int,int>(30,30000));
    // mymap.insert(ft::make_pair<int,int>(40,40000));


    ft::map<int,int>::iterator b = mymap.begin();

    ft::map<int,int>::iterator e = mymap.end();
 
    while (e != b)
    {
        
        cout << e->first << endl;
        --e;
    }
    --e;
    cout << e->first << endl;
}



// how to compare value
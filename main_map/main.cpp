#include <iostream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <memory>
#include <stack>
#include <vector>
 #include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

#include <fstream>


using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;


#include "../map/map.hpp"
#include "../vector/vector.hpp"
#include "../set/set.hpp"
#include "../stack/stack.hpp"
 

  
 
int main()
{
    ft::map<int, int> first;
     
    int i = 1;
    while (i < 10)
    {
        first.insert(ft::make_pair<int,int>(i,i * 10));
        i++;
    }
   
    ft::map<int, int> second(first);
    i = 1;

    while (i < 10)
    {
        cout << second[i] << endl;
        i++;
    }

    if (first == second)
        cout << "equals\n";

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";


    ft::map<char,int> first_;
    ft::map<char,int> second_;

    first_['x']=8;
    first_['y']=16;
    first_['z']=32;

    second_=first_;                // second_ now contains 3 ints
    first_=ft::map<char,int>();  // and first_ is now empty

    std::cout << "Size of first_: " << first_.size() << '\n';
    std::cout << "Size of second_: " << second_.size() << '\n';


    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    ft::map<int,int> mymap;

     i = 1;
    while (i < 10)
    {
        mymap.insert(ft::make_pair<int,int>(i,i * 10));
        i++;
    }

    // show content:
    for (ft::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
   
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    ft::map<int,int>::reverse_iterator rit;
    for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
        std::cout << rit->first << " => " << rit->second << '\n';

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    ft::map<char,int> mymap_;

    // first insert function version (single parameter):
    mymap_.insert ( ft::pair<char,int>('a',100) );
    mymap_.insert ( ft::pair<char,int>('z',200) );

    ft::pair<ft::map<char,int>::iterator,bool> ret;
    ret = mymap_.insert ( ft::pair<char,int>('z',500) );
    if (ret.second==false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }

    // second insert function version (with hint position):
    ft::map<char,int>::iterator it = mymap_.begin();
    mymap_.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
    mymap_.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

    // third insert function version (range insertion):
    ft::map<char,int> anothermap;
    anothermap.insert(mymap_.begin(),mymap_.find('c'));

    // showing contents:
    std::cout << "mymap_ contains:\n";
    for (it=mymap_.begin(); it!=mymap_.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "anothermap contains:\n";
    for (it=anothermap.begin(); it!=anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    ft::map<char,int> _mymap;
    ft::map<char,int>::iterator _it;

    // insert some values:
    _mymap['a']=10;
    _mymap['b']=20;
    _mymap['c']=30;
    _mymap['d']=40;
    _mymap['e']=50;
    _mymap['f']=60;

    _it=_mymap.find('b');
    _mymap.erase (_it);                   // erasing by iterator

    _mymap.erase ('c');                  // erasing by key

    _it=_mymap.find ('e');
    _mymap.erase ( _it, _mymap.end() );    // erasing by range

    // show content:
    for (_it=_mymap.begin(); _it!=_mymap.end(); ++_it)
        std::cout << _it->first << " => " << _it->second << '\n';
    
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    ft::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;

    foo.swap(bar);

    std::cout << "foo contains:\n";
    for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "bar contains:\n";
    for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    
    ft::map<char,int> mymap1;

    mymap1['x']=100;
    mymap1['y']=200;
    mymap1['z']=300;

     for (ft::map<char,int>::iterator it1=mymap1.begin(); it1!=mymap1.end(); ++it1)
        std::cout << it1->first << " => " << it1->second << '\n';

    cout << "\n";
    mymap1.clear();// for testing leaks
    mymap1['a']=1101;
    mymap1['b']=2202;

     for (ft::map<char,int>::iterator it1=mymap1.begin(); it1!=mymap1.end(); ++it1)
        std::cout << it1->first << " => " << it1->second << '\n';

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
 

    ft::map<int, int> m;  

    m[10]=  1;
    m[20]=  2;
    m[30]=  3;

    cout << m.lower_bound(19)->first << endl; // if gereter then k return next
    cout << m.lower_bound(20)->first << endl; // if found return it
    cout << m.lower_bound(9)->first << endl;  // if smaller then min return min
    
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";


    cout << m.upper_bound(19)->first << endl; // if gereter then k return next
    cout << m.upper_bound(20)->first << endl; // if found return NEXT
    cout << m.upper_bound(9)->first << endl; // if smaller then min return min


    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    ft::map<char,int> mp;

    mp['a']=10;
    mp['b']=20;
    mp['c']=30;

    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> rt;
    rt = mp.equal_range('a');

    std::cout << "lower bound points to: ";
    std::cout << rt.first->first << " => " << rt.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << rt.second->first << " => " << rt.second->second << '\n';

    system("leaks a.out");

}
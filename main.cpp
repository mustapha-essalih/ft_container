
#include <iostream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <memory>
#include <stack>
#include <vector>
 



using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;


#include "map/map.hpp"
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "set/set.hpp"
 

 
// use key compar to comapar evryting
// in iterator node privete

// implement std::key_comp
// implement std::map::value_comp
#define _ratio 10000

void func()
{
	system("leaks ft_container");
}

template <typename T>
std::vector<int> insert_test_2(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
    vector.insert(vector.end() - 50, 4200 * _ratio , 2);
    cout << "=> " << vector.size() << endl;
    cout << "=> " << vector.capacity() << endl;

	cout << (4200 * _ratio)   << endl;
	// cout << (4200 * _ratio) + vector.capacity() << endl;
	// v.push_back(vector[2121]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> insert_test_2(ft::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1000, 1);
	// cout << "==> " << vector.size() << endl;
    // cout << "==> " << vector.capacity() << endl;
    vector.insert(vector.end() - 50, 4200 * _ratio , 2);
cout << "=> " << vector.size() << endl;
    cout << "=> " << vector.capacity() << endl;

	cout << (4200 * _ratio)   << endl;

    // v.push_back(vector[2121]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());
    return v;
}

int main ()
{
	    // ft::vector<int> myvector;
		// insert_test_2(myvector);
	    // std::vector<int> v;
		// insert_test_2(v);



    std::vector<int> myvector (3,100);

    std::vector<int>::iterator it;

    it = myvector.begin();
    // it = myvector.insert ( it  , 200 );

    cout << myvector.size() << endl;
    cout << myvector.capacity() << endl;
 
    myvector.insert (it ,2,300);
    cout << myvector.size() << endl;
    cout << myvector.capacity() << endl;
     


    // while (it != myvector.end())
    // {
      
    //   cout << *it << endl;
    //   it++;
    // }
    // 
  	 
    // atexit(func);

  return 0;
}
 
 
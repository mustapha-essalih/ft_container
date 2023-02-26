
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

 
#include "../vector/vector.hpp"
 
  
 

// namespace ft = std;
 

 

int main() 
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// constructor tests
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		ft::vector<int> first;                                // empty vector of ints
		ft::vector<int> second (44444,100);                       // four ints with value 100
		ft::vector<int> third (second.begin(),second.end());  // iterating through second
		ft::vector<int> fourth (third);                       // a copy of third
		 
		int myints[] = {16,2,77,29,564,6,4,64,989,87,88,6,86,76,8,68,8787,687,68,7,68,76,87,68,76,87645,54,54,8,78,7,87,8,78,9,9,789,7,89};
		ft::vector<int> fifth (myints, myints + 20 );

		 
		for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';

	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///  std::vector::operator=
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	ft::vector<string> foo (100000,"hello");
	ft::vector<string> bar (100000,"1337");

	bar = foo;
	foo = ft::vector<string>();

	cout << "Size of foo: " << int(foo.size()) << '\n';
	cout << "Size of bar: " << int(bar.size()) << '\n';

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//// 	Iterators:
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	ft::vector<int> myvector;
	for (int i=1; i<=10000; i++) myvector.push_back(i);

 	ft::vector<int>::iterator it = myvector.begin() ;
	
	for (; it != myvector.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	it = myvector.begin() ;
	ft::vector<int>::iterator it2 = myvector.begin() ;
	while (it < myvector.begin() + 500)
	{
		*it2 += *it;
		cout << *it2 << endl;
		cout << *it2 - *it << endl;
		it++;
	}

	ft::vector<int> v;
	for (int i=1; i<=10000; i++) v.push_back(i);

	ft::vector<int>::reverse_iterator rit = v.rbegin();

	int i=0;
	int j= 1000;
	for (rit = v.rbegin(); rit!= v.rend(); ++rit)
	{
		*rit = ++i;
		cout << *rit << endl;
		*rit = *rit -= j;
		*rit = *rit += j;
		cout << *rit << endl;
		j++;
	}
	 
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// resize and reserve
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	ft::vector<int> vec;
  
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
 
   
    for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
 
    cout << endl;
 
    vec.resize(4);
  
    for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
	cout << '\n';


	vec.clear(); // clear for empty the vetetor and resize

	cout << "========== another resize\n";

	vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
 
    
    for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
 
    cout << endl;
 
 
    vec.resize(8);
 
   
    for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
	cout << '\n';

	cout << "========== another resize\n";
	
	vec.clear();
	
	vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
 
   
    for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
 
    cout << endl;
  
    vec.resize(12, 9);
  
    for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

	cout << "\n";


	ft::vector<int> vec1;
	ft::vector<int> vec2;
 	 
	vec2.reserve(35);
	for (ft::vector<int>::size_type i = 0; i < 25; ++i) 
		vec2.push_back(i);
	cout << vec2.size() << " " << vec2.capacity() << endl;
	
		ft::vector<int> foo1 (3,100);   // three ints with a value of 100
		ft::vector<int> bar1 (5,200);   // five ints with a value of 200

		foo1.swap(bar1);

		for (ft::vector<int>::size_type i=0; i<foo1.size(); i++)
			std::cout << ' ' << foo1[i];
		std::cout << '\n';

		std::cout << "bar1 contains:";
		for (unsigned i=0; i<bar1.size(); i++)
			std::cout << ' ' << bar1[i];
		std::cout << '\n';

 

	cout << "\n";


	ft::vector<int> first1;
	ft::vector<int> second1;
	ft::vector<int> third1;

	first1.assign (7,100);             // 7 ints with a value of 100

	ft::vector<int>::iterator it1;
	it1=first1.begin()+1;

	second1.assign (it1,first1.end()-1); // the 5 central values of first1

	int myints_ [] = {1776,7,4};
	third1.assign (myints_ ,myints_ +3);   // assigning from array.

	std::cout << "Size of first1: " <<  (first1.size()) << '\n';
	std::cout << "Size of second1: " <<  (second1.size()) << '\n';
	std::cout << "Size of third1: " <<  (third1.size()) << '\n';


	cout << "\n";


	ft::vector<int> vc;

	vc.push_back(78);
	vc.push_back(16);

	// now front equals 78, and back 16

	vc.front() -= vc.back();

	std::cout << "vc.front() is now " << vc.front() << '\n';

	cout << "\n";

	ft::vector<int> vc1;

	vc1.push_back(10);

	while (vc1.back() != 0)
	{
		vc1.push_back ( vc1.back() -1 );
	}
 
	for (unsigned i=0; i<vc1.size() ; i++)
		std::cout << ' ' << vc1[i];
	std::cout << '\n';

	ft::vector<int> vv;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) vv.push_back(i);

  // erase the 6th element
  vv.erase (vv.begin()+5);

  // erase the first 3 elements:
  vv.erase (vv.begin(),vv.begin()+3);

  std::cout << "vv contains:";
  for (unsigned i=0; i<vv.size(); ++i)
    std::cout << ' ' << vv[i];
  std::cout << '\n';


	ft::vector<int> myvector_ (3,100);
	ft::vector<int>::iterator _it;

	_it = myvector_.begin();
	_it = myvector_.insert ( _it , 200 );

	myvector_.insert (_it,2,300);

	// "_it" no longer valid, get a new one:
	_it = myvector_.begin();

	std::vector<int> anothervector (2,400);
	myvector_.insert (_it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector_.insert (myvector_.begin(), myarray, myarray+3);

	std::cout << "myvector_ contains:";
	for (_it=myvector_.begin(); _it<myvector_.end(); _it++)
		std::cout << ' ' << *_it;
	std::cout << '\n';

	system("leaks a.out");
}

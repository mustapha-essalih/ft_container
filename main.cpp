#include "bst.hpp"
#include "type_traits.hpp"
#include "map.hpp"
#include "iterator.hpp"


























int main()
{
	ft::map<int,int> mymap;
 
	ft::map<int,int>::iterator it =   mymap.end();



  // show content:
	// for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';

	// ft::map<int,int>::iterator it1 = mymap.end();

	

	
	// ft::map<int,int> m;

	// ft::map<int,int>::iterator myIt = m.begin();

	
	 
	// for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';


 	return 0;
}



// void func()
// {
// 	system("leaks ft_container");
// }

// atexit(func);

 
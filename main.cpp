#include "bst.hpp"
#include "type_traits.hpp"















// implement pair  and make pair
// implement map(what is map, how map work...)




int main()
{
	ft::pair<int, char> PAIR1;
    ft::pair<string, double> PAIR2("GeeksForGeeks", 1.23);
    ft::pair<string, double> PAIR3;
 
    PAIR1.first = 100;
    PAIR1.second = 'G';
 
    PAIR3 = ft::make_pair("GeeksForGeeks is Best", 4.56);
 
    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;
 
    cout << PAIR2.first << " ";
    cout << PAIR2.second << endl;
 
    cout << PAIR3.first << " ";
    cout << PAIR3.second << endl;




 	return 0;
}






// void func()
// {
// 	system("leaks ft_container");
// }

// atexit(func);
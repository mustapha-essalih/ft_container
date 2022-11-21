#include "vector.hpp"

#include "iterator.hpp"

#include "iterator_traits.hpp"


#include "reverse_iterator.hpp"

int main() 
{
    
     
    ft::vector<int> myvector;
    for (int i=0; i<10; i++) myvector.push_back(i);

    typedef ft::vector<int>::iterator iter_type;
                                                            // ? 0 1 2 3 4 5 6 7 8 9 ?
    iter_type from (myvector.begin());                     //   ^
                                                            //         ------>
    iter_type until (myvector.end());                      //                       ^
                                                            //
    std::reverse_iterator<iter_type> rev_until (from);     // ^
                                                            //         <------
    std::reverse_iterator<iter_type> rev_from (until);     //                     ^

    std::cout << "myvector:";
    while (rev_from != rev_until)
        std::cout << ' ' << *rev_from++;
    std::cout << '\n';
    
    
    
    return 0;
}
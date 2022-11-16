#include "vector.hpp"

#include "iterator.hpp"
  

int main()
{
     ft::vector<int> v;
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
 
    // prints all the elements
    cout << "The vector elements in reverse order are:\n";
    for (auto it = v.rbegin(); it != v.rend(); it++)
        cout << *it << " ";
    

}











// cout << "size: " << myvector.size() << endl;
// cout << "capacity: " << myvector.capacity() << endl;
//

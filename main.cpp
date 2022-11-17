#include "vector.hpp"

#include "iterator.hpp"
  

int main()
{
    ft::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    ft::vector<int>::iterator i = v.begin();

    i++;
    cout << &v[1] << endl;
    cout << i.base();
     
}











// cout << "size: " << myvector.size() << endl;
// cout << "capacity: " << myvector.capacity() << endl;
//

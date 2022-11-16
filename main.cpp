#include "vector.hpp"

#include "iterator.hpp"
  

int main()
{
    
    ft::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';   
}











// cout << "size: " << myvector.size() << endl;
// cout << "capacity: " << myvector.capacity() << endl;
//

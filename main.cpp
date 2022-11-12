#include "vector.hpp"


 
#include <iostream>
#include <iomanip>
#include <string>
 
int main()
{

  
    vector<int> v(2);

 

    v.push_back(1);
    v.push_back(2);//
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    
  
  
    cout << v.size() << endl;
    cout << v.capacity() << endl;
        
  
  cout << "========\n";
    ft::vector<int> vec(2);

 

    vec.push_back(1);
    vec.push_back(2);//
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    
  
  
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
        
    return 0;
}
#include "vector.hpp"


 
#include <iostream>
#include <iomanip>
#include <string>
 
 

int main()
{
   ft::vector<int> vec;
  
    // 5 elements are inserted
    // in the vector
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
  
    cout << "Contents of vector before resizing:"
         << endl;
  
    // displaying the contents of 
    // the vector before resizing
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
  
    cout << endl;
  
    // vector is resized
    vec.resize(12, 9);
  
    cout << "Contents of vector after resizing:" 
         << endl;
      
    // displaying the contents 
    // of the vector after resizing
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    
}
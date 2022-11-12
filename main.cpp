#include "vector.hpp"


 
#include <iostream>
#include <iomanip>
#include <string>
 
 #define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
int idx;
char buff[BUFFER_SIZE];
};
#define COUNT (MAX_RAM / (int)sizeof(Buffer))

int main()
{

  ft::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  std::cout << "myvector contains:";
  for (int i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
  

}
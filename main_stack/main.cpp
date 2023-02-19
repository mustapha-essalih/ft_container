
#include "../vector/vector.hpp"
#include "../stack/stack.hpp"



int main ()
{

    ft::vector<int> mydeque (3,100);          // deque with 3 elements
    ft::vector<int> myvector (2,200);        // vector with 2 elements

    ft::stack<int> first;                    // empty stack
    ft::stack<int> second (mydeque);         // stack initialized to copy of deque

    ft::stack<int,ft::vector<int> > third;  // empty stack using vector
    ft::stack<int,ft::vector<int> > fourth (myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';

    cout << "\n";

    ft::stack<int> mystack;
    int sum (0);

    for (int i=1;i<=10;i++) mystack.push(i);

    while (!mystack.empty())
    {
        sum += mystack.top();
        mystack.pop();
    }

    std::cout << "total: " << sum << '\n';

    cout << "\n";

    ft::stack<int> mystack1;

    mystack1.push(10);
    mystack1.push(20);

    mystack1.top() -= 5;

    std::cout << "mystack1.top() is now " << mystack1.top() << '\n';

    cout << "\n";

     std::stack<int> mystack_;

    for (int i=0; i<5; ++i) mystack_.push(i);

    std::cout << "Popping out elements...";
    while (!mystack_.empty())
    {
        std::cout << ' ' << mystack_.top();
        mystack_.pop();
    }
  std::cout << '\n';

    ft::stack<int> mystack__;

    for (int i=0; i<5; ++i) mystack__.push(i);

    while (!mystack__.empty())
    {
        std::cout << ' ' << mystack__.top();
        mystack__.pop();
    }
    std::cout << '\n';

       

system("leaks a.out");
  return 0;
}
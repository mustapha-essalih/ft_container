#include "./vector/vector.hpp"
#include "./iterators/iterator.hpp"
#include "./iterators/iterator_traits.hpp"
#include "./iterators/reverse_iterator.hpp"

#include "./type_traits/std_mechanism.hpp"
#include "./map/map.hpp"
#include "./map/avl_tree.hpp"

 

 
 
int main()
{
	 
	avl_tree obj;

    obj.insert(20);
    obj.insert(30);
    obj.insert(40);
    obj.insert(50);
    obj.insert(55);
    obj.insert(0);
    obj.insert(1);



    
	return 0;
}


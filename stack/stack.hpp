#ifndef STACK_HPP
#define STACK_HPP


using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::deque;

#include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef	Container							container_type;
			typedef	typename	Container::value_type	value_type;
			typedef	typename	Container::size_type	size_type;
		protected:
			Container c;
		public:
			stack (const container_type& ctnr = container_type()) : c(ctnr){}
			bool				empty() const {return (c.empty());}
			size_type			size() const {return (c.size());}
			value_type& 		top() {return (c.back());}
			const value_type&	top() const {return (c.back());}
			void				push(const value_type &val)	{ c.push_back(val); }
			void				pop() { c.pop_back(); }

			template <class T1, class Container1>
			friend bool operator==(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);// decalaretion here

			template <class T1, class Container1>
			friend bool operator!=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

			template <class T1, class Container1>
			friend bool operator<(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

			template <class T1, class Container1>
			friend bool operator<=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

			template <class T1, class Container1>
			friend bool operator>(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

			template <class T1, class Container1>
			friend bool operator>=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
	};
	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c == rhs.c); };// implementation here

	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c != rhs.c); };

	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c < rhs.c); };

	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c <= rhs.c); };

	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c > rhs.c); };

	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c >= rhs.c); };
};










#endif
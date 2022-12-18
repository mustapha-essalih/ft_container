#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP




namespace ft
{
    template< typename T1, typename T2 >
        class pair
        {
            typedef T1 first_type;
            typedef T2 second_type;

            public:
                T1 first;
                T2 second;

                pair()
                {
                    first = T1(); // to initialze template variable in c11
                    second = T2();
                }

                template<class U, class V> // this declaration in manuale
                
                pair (const pair<U,V>& pr)
                {
                    first = pr.first;
                    second = pr.second;
                }

                pair& operator= (const pair& pr)
                {
                    if(this != &pr)
                    {
                        this->first = pr.first;
                        this->second = pr.second;
                    }
                    return *this;
                }
                
                
                pair (const first_type& a, const second_type& b)
                {
                    first = a;
                    second = b;
                }
                ~pair()
                {

                }
        };
        template <class T1, class T2> 
        pair<T1,T2> make_pair (T1 x, T2 y)
        {
            return pair<T1,T2>(x,y);
        }
        template <class T1, class T2>
        bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return lhs.first==rhs.first && lhs.second==rhs.second; }

        template <class T1, class T2>
        bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(lhs==rhs); }

        template <class T1, class T2>
        bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); } // if lhs.first==rhs.first wiil pass next statemnet

        template <class T1, class T2>
        bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(rhs<lhs); }// here rhs > lhs

        template <class T1, class T2>
        bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return rhs<lhs; }

        template <class T1, class T2>
        bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(lhs<rhs); }



};

















#endif
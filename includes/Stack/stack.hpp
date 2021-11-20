#ifndef STACK_H__
#define STACK_H__

#include "vector.hpp"

namespace ft
{
    template<class Tp, class Sequence = ft::vector<Tp> >
    class stack
    {
            typedef typename    Sequence::value_type                sequence_value_type;
        public:
            typedef typename    Sequence::value_type                value_type;
            typedef typename    Sequence::reference                 reference;
            typedef typename    Sequence::const_reference           const_reference;
            typedef typename    Sequence::size_type                 size_type;
            typedef             Sequence                            container_type;
        protected:
            Sequence                                                c;
        public:
            stack(const Sequence _c = Sequence()) : c(_c) { }
            ~stack() { }
            bool            empty() const { return c.empty(); }
            size_type       size() const { return c.size(); }
            reference       top() { return c.back(); }
            const_reference top() const { return c.back(); }
            void            push(const value_type& x) { c.push_back(x); }
            void            pop() { c.pop_back(); }
            friend bool operator==(const stack<Tp, Sequence>&__x, const stack<Tp, Sequence>&__y){ return __x.c == __y.c; }
            friend bool operator<(const stack<Tp, Sequence>&__x, const stack<Tp, Sequence>&__y) { return __x.c < __y.c; }
    };
    template<typename _Tp, typename _Seq>
    bool    operator<(const stack<_Tp, _Seq>& __x, const stack<_Tp, _Seq>& __y)
    { return __x.c < __y.c; }
  /// Based on operator==
    template<typename _Tp, typename _Seq>
    bool    operator!=(const stack<_Tp, _Seq>& __x, const stack<_Tp, _Seq>& __y)
    { return !(__x == __y); }
    /// Based on operator<
    template<typename _Tp, typename _Seq>
    bool    operator>(const stack<_Tp, _Seq>& __x, const stack<_Tp, _Seq>& __y)
    { return __y < __x; }
    /// Based on operator<
    template<typename _Tp, typename _Seq>
    bool    operator<=(const stack<_Tp, _Seq>& __x, const stack<_Tp, _Seq>& __y)
    { return !(__y < __x); }
    /// Based on operator<
    template<typename _Tp, typename _Seq>
    bool    operator>=(const stack<_Tp, _Seq>& __x, const stack<_Tp, _Seq>& __y)
    { return !(__x < __y); }

    template<typename _Tp, typename _Seq>
    bool    operator==(const stack<_Tp, _Seq>& __x, const stack<_Tp, _Seq>& __y)
    { return __x.c == __y.c; }
};

#endif
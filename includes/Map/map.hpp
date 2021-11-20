#pragma once
#ifndef MAP_H__
#define MAP_H__

#include "tree.hpp"
#include "../ft_utils.hpp"
#include <iostream>

namespace ft
{
    template <typename Key, typename Tp, typename Compare = std::less<Key>,
                typename Allocator = std::allocator<ft::pair<const Key, Tp> > >
    class map
    {
        public:
            typedef Key                                                                     key_type;
            typedef Tp                                                                      mapped_type;
            typedef ft::pair<key_type, mapped_type>                                         value_type;
            typedef Compare                                                                 key_compare;
            typedef Allocator                                                               allocator_type;
            typedef typename allocator_type::reference                                      reference;
            typedef typename allocator_type::const_reference                                const_reference;
            typedef typename allocator_type::pointer                                        pointer;
            typedef typename allocator_type::const_pointer                                  const_pointer;
            typedef size_t                                                                  size_type;
            typedef std::ptrdiff_t                                                          difference_type;
        private:
            typedef RbTree<key_type, value_type, ft::Select1st<value_type>, Compare>        rep_type;
            rep_type                                                                        root;
        public:
            typedef typename rep_type::iterator                                             iterator;
            typedef typename rep_type::const_iterator                                       const_iterator;
            typedef typename rep_type::reverse_iterator                                     reverse_iterator;
            typedef typename rep_type::reverse_iterator                                     const_reverse_iterator;
            class value_compare : public ft::binary_function<value_type, value_type, bool>
            {
                friend class map<Key, Tp, Compare, Allocator>;
                protected:
                    Compare                                                                 comp;
                    value_compare(Compare c) : comp(c) { }
                public:
                    bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
            };
            map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : root(comp, alloc) { };
            map(const value_type& p) : root(){ root.insert_unique(p); }
            template<typename InputIterator>
            map(InputIterator first, InputIterator last) : root() { root.insert_unique(first, last); }
            map (const map& x, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : root(x.root, comp, alloc) { }
            ~map() { root.~RbTree(); }

            const_iterator                              begin() const { return (root.begin()); }
            const_iterator                              end() const { return (root.end()); } 
            iterator                                    begin() { return (root.begin()); }
            iterator                                    end() { return (root.end()); }
            reverse_iterator                            rbegin() { return (root.rbegin()); }
            reverse_iterator                            rend() { return (root.rend()); }
            bool                                        empty() const { return root.empty(); }
            size_type                                   size() const { return root.size(); }
            size_type                                   max_size() const { return root.max_size(); }
            iterator                                    lower_bound(const key_type& k) { return root.lower_bound(k); }
            const_iterator                              lower_bound(const key_type& k) const { return root.lower_bound(k); }
            iterator                                    upper_bound(const key_type& k) { return root.upper_bound(k); }
            const_iterator                              upper_bound(const key_type& k) const { return root.upper_bound(k); }
            ft::pair<iterator, iterator>                equal_range(const key_type& x) { return root.equal_range(x); }
            ft::pair<const_iterator, const_iterator>    equal_range(const key_type& x) const { return root.equal_range(x); }
            ft::pair<iterator, bool>                    insert(const value_type& p) { return (root.insert_unique(p)); }
            iterator                                    insert (iterator position, const value_type& val) { return (root.insert_unique(position, val)); }
            void                                        swap(map& src) { root.swap(src.root); }
            key_compare                                 key_comp() const { return root.key_comp(); }
            value_compare                               value_comp() const { return value_compare(root.key_comp()); }
            template <class II>
            void                                        insert (II first, II last) { root.insert_unique(first, last); }
            void                                        erase(iterator position) { root.erase(position); }
            size_type                                   erase(const key_type& k) { return root.erase(k); }
            void                                        erase (iterator first, iterator last) { root.erase(first, last); }
            void                                        clear() { root.clear(); }
            iterator                                    find (const key_type& k) { return (root.find(k)); }
            const_iterator                              find (const key_type& k) const { return (root.find(k)); }
            size_type                                   count (const key_type& k) const { return (root.count(k)); }
            allocator_type                              get_allocator() const { return allocator_type(root.get_allocator());}
            map&                                        operator=(const map& x) { root = x.root; return *this; }
            mapped_type&                                operator[](const key_type& k)
            {
                iterator i = lower_bound(k);
                // i->first is greater than or equivalent to k.
                if (i == end() || key_comp()(k, (*i).first))
                    i = insert(i, value_type(k, mapped_type()));
                return (*i).second;
            }
            template<typename _K1, typename _T1, typename _C1, typename _A1>
            friend bool                                 operator==(const map<_K1, _T1, _C1, _A1>&,
                                                                    const map<_K1, _T1, _C1, _A1>&);
            template<typename _K1, typename _T1, typename _C1, typename _A1>
            friend bool                                 operator<(const map<_K1, _T1, _C1, _A1>&,
                                                                    const map<_K1, _T1, _C1, _A1>&);

    };
    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool    operator==(const map<_Key, _Tp, _Compare, _Alloc>& __x,
               const map<_Key, _Tp, _Compare, _Alloc>& __y)
    { return __x.root == __y.root; }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool    operator<(const map<_Key, _Tp, _Compare, _Alloc>& __x,
              const map<_Key, _Tp, _Compare, _Alloc>& __y)
    { return __x.root < __y.root; }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool    operator!=(const map<_Key, _Tp, _Compare, _Alloc>& x,
               const map<_Key, _Tp, _Compare, _Alloc>& y)
    { return !(x == y); }

  /// Based on operator<
    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool    operator>(const map<_Key, _Tp, _Compare, _Alloc>& x,
              const map<_Key, _Tp, _Compare, _Alloc>& y)
    { return y < x; }

  /// Based on operator<
    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool    operator<=(const map<_Key, _Tp, _Compare, _Alloc>& x,
               const map<_Key, _Tp, _Compare, _Alloc>& y)
    { return !(y < x); }

  /// Based on operator<
    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool    operator>=(const map<_Key, _Tp, _Compare, _Alloc>& x,
               const map<_Key, _Tp, _Compare, _Alloc>& y)
    { return !(x < y); }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    void    swap(map<_Key, _Tp, _Compare, _Alloc>& x,
         map<_Key, _Tp, _Compare, _Alloc>& y)
    { x.swap(y); }
}

#endif

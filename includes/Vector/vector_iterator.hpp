#pragma once
#ifndef VECTOR_ITERATOR_H__
#define VECTOR_ITERATOR_H__

#include <iostream>
#include "../ft_utils.hpp"

template<typename _Iterator>
class VectorIterator
{
    protected:
        _Iterator                                           current;
        typedef typename ft::iterator_traits<_Iterator>     traits_type;
    public:
        typedef _Iterator                                   iterator_type;
        typedef typename traits_type::iterator_category     iterator_category;
        typedef typename traits_type::value_type            value_type;
        typedef typename traits_type::difference_type       difference_type;
        typedef typename traits_type::reference             reference;
        typedef typename traits_type::pointer               pointer;

        VectorIterator() : current(_Iterator()) { }
        VectorIterator(const _Iterator& i) : current(i) { }
        // Allow iterator to const_iterator conversion
        template<typename _Iter>
        VectorIterator(const VectorIterator<_Iter>& src) : current(src.base()) {}

  // Forward iterator requirements
  reference             operator*() const { return *current; }
  pointer               operator->() const { return current; }
  VectorIterator&       operator++() { ++current; return *this; }
  VectorIterator        operator++(int) { return VectorIterator(current++); }
  // Bidirectional iterator requirements
  VectorIterator&       operator--() { --current; return *this; }
  VectorIterator        operator--(int) { return VectorIterator(current--); }
  // Random access iterator requirements
  reference             operator[](difference_type n) const { return current[n]; }
  VectorIterator&       operator+=(difference_type n) { current += n; return *this; }
  VectorIterator        operator+(difference_type n) const { return VectorIterator(current + n); }
  VectorIterator&       operator-=(difference_type n) { current -= n; return *this; }
  VectorIterator        operator-(difference_type n) const { return VectorIterator(current - n); }
  const _Iterator&      base() const { return current; }
};
  // Note: In what follows, the left- and right-hand-side iterators are
  // allowed to vary in types (conceptually in cv-qualification) so that
  // comparison between cv-qualified and non-cv-qualified iterators be
  // valid.  However, the greedy and unfriendly operators in std::rel_ops
  // will make overload resolution ambiguous (when in scope) if we don't
  // provide overloads whose operands are of the same type.  Can someone
  // remind me what generic programming is about? -- Gaby
  // Forward iterator requirements
template<typename _IteratorL, typename _IteratorR>
bool  operator==(const VectorIterator<_IteratorL>& lhs,
             const VectorIterator<_IteratorR>& rhs)
{ return lhs.base() == rhs.base(); }

template<typename _Iterator>
bool  operator==(const VectorIterator<_Iterator>& lhs,
             const VectorIterator<_Iterator>& rhs)
{ return lhs.base() == rhs.base(); }

template<typename _IteratorL, typename _IteratorR>
bool  operator!=(const VectorIterator<_IteratorL>& lhs,
             const VectorIterator<_IteratorR>& rhs)
{ return lhs.base() != rhs.base(); }

template<typename _Iterator>
bool  operator!=(const VectorIterator<_Iterator>& lhs,
             const VectorIterator<_Iterator>& rhs)
{ return lhs.base() != rhs.base(); }
  // Random access iterator requirements

template<typename _IteratorL, typename _IteratorR>
bool  operator<(const VectorIterator<_IteratorL>& lhs,
              const VectorIterator<_IteratorR>& rhs)
{ return lhs.base() < rhs.base(); }
  
template<typename _Iterator>
bool  operator<(const VectorIterator<_Iterator>& lhs,
              const VectorIterator<_Iterator>& rhs)
{ return lhs.base() < rhs.base(); }

template<typename _IteratorL, typename _IteratorR>
bool  operator>(const VectorIterator<_IteratorL>& lhs,
            const VectorIterator<_IteratorR>& rhs)
{ return lhs.base() > rhs.base(); }

template<typename _Iterator>
bool  operator>(const VectorIterator<_Iterator>& lhs,
              const VectorIterator<_Iterator>& rhs)
    
    { return lhs.base() > rhs.base(); }
  template<typename _IteratorL, typename _IteratorR>
     bool
    operator<=(const VectorIterator<_IteratorL>& lhs,
               const VectorIterator<_IteratorR>& rhs)
    
    { return lhs.base() <= rhs.base(); }
  template<typename _Iterator>
     bool
    operator<=(const VectorIterator<_Iterator>& lhs,
               const VectorIterator<_Iterator>& rhs)
    
    { return lhs.base() <= rhs.base(); }
  template<typename _IteratorL, typename _IteratorR>
     bool
    operator>=(const VectorIterator<_IteratorL>& lhs,
               const VectorIterator<_IteratorR>& rhs)
    
    { return lhs.base() >= rhs.base(); }
  template<typename _Iterator>
     bool
    operator>=(const VectorIterator<_Iterator>& lhs,
               const VectorIterator<_Iterator>& rhs)
    
    { return lhs.base() >= rhs.base(); }
  // _GLIBCXX_RESOLVE_LIB_DEFECTS
  // According to the resolution of DR179 not only the various comparison
  // operators but also operator- must accept mixed iterator/const_iterator
  // parameters.
    template<typename _IteratorL, typename _IteratorR>
    typename VectorIterator<_IteratorL>::difference_type
    operator-(const VectorIterator<_IteratorL>& lhs,
              const VectorIterator<_IteratorR>& rhs)
    { return lhs.base() - rhs.base(); }

    template<typename _Iterator>
    typename VectorIterator<_Iterator>::difference_type
    operator-(const VectorIterator<_Iterator>& lhs,
              const VectorIterator<_Iterator>& rhs)    
    { return lhs.base() - rhs.base(); }

    template<typename _Iterator>
    VectorIterator<_Iterator>
    operator+(typename VectorIterator<_Iterator>::difference_type
              n, const VectorIterator<_Iterator>& i)    
    { return VectorIterator<_Iterator>(i.base() + n); }
   
   template <class T>
   VectorIterator<T> operator+(typename VectorIterator<T>::difference_type i, VectorIterator<T> &tmp)
   {
      return tmp.base() + i;
   }

   template <class T>
   VectorIterator<T> operator+(VectorIterator<T> &tmp, typename VectorIterator<T>::difference_type i)
   {
      return tmp.base() + i;
   }

#endif
//
// Created by cjw on 2018/6/15.
//

#ifndef MINI_STL_ITERATOR_H
#define MINI_STL_ITERATOR_H

#include <cstddef>

namespace miniSTL {

    //protocol for iterator
    template <typename Category,
            typename T,
            typename Distance = ptrdiff_t,
            typename Pointer = T *,
            typename Reference = T&>
    class iterator {
    public:
        using iterator_category = Category;
        using value_type = T;
        using difference_type = Distance;
        using pointer = Pointer;
        using reference = Reference;
    };

    //5 different kind of iterators
    class input_iterator_tag {};
    class output_iterator_tag {};
    class forward_iterator_tag: input_iterator_tag {};
    class bidirectional_iterator_tag: forward_iterator_tag {};
    class random_access_iterator_tag: bidirectional_iterator_tag {};

    //extraction for associated type of different kind of iterator
    template <typename I>
    class iterator_traits {
    public:
        using iterator_category = typename I::iterator_category;
        using value_type = typename I::value_type;
        using difference_type = typename I::difference_type;
        using pointer = typename I::pointer;
        using reference = typename I::reference;
    };

    //partial template specialization for raw pointer
    template <typename T>
    class iterator_traits<T *> {
    public:
        using iterator_category = random_access_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T *;
        using reference = T &;
    };

    template <typename T>
    class iterator_traits<const T *> {
    public:
        using iterator_category = random_access_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T *;
        using reference = T &;
        using const_reference = const T &;//TODO:check correctness
    };

    template <typename Iterator>
    class reverse_iterator: iterator<
            typename iterator_traits<Iterator>::iterator_category,
            typename iterator_traits<Iterator>::value_type,
            typename iterator_traits<Iterator>::difference_type,
            typename iterator_traits<Iterator>::pointer,
            typename iterator_traits<Iterator>::reference>
    {
    public:
        //type definition
        using iterator_type = Iterator;
        using iterator_category = typename iterator_traits<Iterator>::iterator_category;
        using value_type = typename iterator_traits<Iterator>::value_type;
        using difference_type = typename iterator_traits<Iterator>::difference_type;
        using pointer = typename iterator_traits<Iterator>::pointer;
        using reference = typename iterator_traits<Iterator>::reference;
        using const_reference = typename iterator_traits<Iterator>::const_reference;

        reverse_iterator(): currentIter(nullptr) {};
        explicit reverse_iterator(Iterator i): currentIter(i) {};
        ~reverse_iterator()
        {
            currentIter->~value_type();
        }

        reverse_iterator &operator=(const reverse_iterator<Iterator> &ri);
        const_reference operator*()
        {
            return *(currentIter - 1);
        }
        pointer operator->();
        reverse_iterator &operator++();//pre-fix ++
        const reverse_iterator operator++(int);//post-fix ++
        reverse_iterator &operator--();
        const reverse_iterator operator--(int);
        friend reverse_iterator operator+(reverse_iterator ri, difference_type step);
        reverse_iterator &operator+=(difference_type step);
        friend reverse_iterator operator-(reverse_iterator ri, difference_type step);
        reverse_iterator &operator-=(difference_type step);
        reference &operator[](difference_type step);

        bool operator==(const reverse_iterator &iter2)
        {
            return this->currentIter == iter2.currentIter;
        }

        bool operator!=(const reverse_iterator &iter2)
        {
            return this->currentIter != iter2.currentIter;
        }

        bool operator<(const reverse_iterator &iter2)
        {
            return this->currentIter > iter2.currentIter;
        }

        bool operator>(const reverse_iterator &iter2)
        {
            return this->currentIter < iter2.currentIter;
        }

        bool operator<=(const reverse_iterator &iter2)
        {
            return this->currentIter >= iter2.currentIter;
        }

        bool operator>=(const reverse_iterator &iter2)
        {
            return this->currentIter <= iter2.currentIter;
        }

    private:
        Iterator currentIter;
    protected:
    };

    template <typename iterator>
    reverse_iterator<iterator> &reverse_iterator<iterator>::operator=(const reverse_iterator<iterator> &ri)
    {
        this->currentIter = ri.currentIter;
        return *this;
    }

    /*
    template <typename iterator>
    const typename reverse_iterator<iterator>::reference reverse_iterator<iterator>::operator*()
    {
        return *(currentIter - 1);
    }
*/
    template <typename iterator>
    typename reverse_iterator<iterator>::pointer reverse_iterator<iterator>::operator->()
    {
        return &operator*();
    }

    template <typename iterator>
    reverse_iterator<iterator>& reverse_iterator<iterator>::operator++()
    {
        --currentIter;
        return *this;
    }

    template <typename iterator>
    const reverse_iterator<iterator> reverse_iterator<iterator>::operator++(int)
    {
        reverse_iterator<iterator> tmp = *this;
        --currentIter;
        return tmp;
    }

    template <typename iterator>
    reverse_iterator<iterator>& reverse_iterator<iterator>::operator--()
    {
        ++currentIter;
        return *this;
    }

    template <typename iterator>
    const reverse_iterator<iterator> reverse_iterator<iterator>::operator--(int)
    {
        reverse_iterator tmp = *this;
        ++currentIter;
        return tmp;
    }

    template <typename iterator>
    reverse_iterator<iterator> operator+(const reverse_iterator<iterator> ri, typename reverse_iterator<iterator>::difference_type step)
    {
        return reverse_iterator<iterator>(ri.currentIter - step);
    }

    template <typename iterator>
    reverse_iterator<iterator> operator-(const reverse_iterator<iterator> ri, typename reverse_iterator<iterator>::difference_type step)
    {
        return reverse_iterator<iterator>(ri.currentIter + step);
    }

    template <typename iterator>
    reverse_iterator<iterator>& reverse_iterator<iterator>::operator+=(difference_type step)
    {
        this->currentIter -= step;
        return *this;
    }

    template <typename iterator>
    reverse_iterator<iterator>& reverse_iterator<iterator>::operator-=(difference_type step)
    {
        this->currentIter += step;
        return *this;
    }

    template <typename iterator>
    typename reverse_iterator<iterator>::reference & reverse_iterator<iterator>::operator[](difference_type step)
    {
        this->currentIter += step;
        return *currentIter;
    }

    template<class InputIt, class OutputIt>
    OutputIt copy( InputIt first, InputIt last, OutputIt d_first)
    {
        auto source = first, destination = d_first;
        for (; source != last;
             ++source, ++destination) {
            *destination = *source;
        }
        return destination;
    };
}

#endif //MINI_STL_ITERATOR_H

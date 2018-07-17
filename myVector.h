//
// Created by cjw on 2018/6/15.
//

#ifndef MINI_STL_VECTOR_H
#define MINI_STL_VECTOR_H


#include <cstddef>
#include "myIterator.h"
#include <stdexcept>
#include <memory>



namespace miniSTL {
    //reference && not added
    template <typename T, typename Alloc = std::allocator<T>>
    class vector {
    public:
        //type definition, C++ 11 required
        using value_type = T;
        using pointer = value_type *;
        using const_pointer = const value_type *;
        using reference = value_type &;
        using const_reference = const value_type &;
        using iterator = pointer;
        using const_iterator = const_pointer;
        using size_type = size_t;
        using difference_type = ptrdiff_t;
        using const_reverse_iterator = reverse_iterator<const_iterator>;
        using reverse_iterator = reverse_iterator<iterator>;
        using allocator_type = Alloc;

        //constructor and destructor
        vector(): __begin(nullptr), __end_of_arr(nullptr), __end(nullptr) {};

        explicit vector(size_type size)
        {
            allocator_type alloc = allocator_type();
            __begin = alloc.allocate(size);
            __end = __begin;
            __end_of_arr = __begin + size;
        }
/*
        vector(const vector &initVec)
        {
            allocator_type alloc;
            __begin = alloc.allocate(initVec.capacity());
            __end_of_arr = __begin + initVec.capacity();
            difference_type size = initVec.size();
            __end = __begin + size;

            for (auto source = initVec.cbegin(), destination = this->begin();
                 source != initVec.cend();
                 ++source, ++destination) {
                *destination = *source;
            }
        }
*/
        vector(size_type size, const value_type &value)
        {
            allocator_type alloc;
            __begin = alloc.allocate(size);
            __end_of_arr = __end = __begin + size;
            //difference_type
            for (auto iter = this->begin(); iter != this->end(); ++iter) {
                *iter = value;
            }
        }

        ~vector()
        {
            Alloc alloc = Alloc();
            for (auto iter = this->begin(); iter != this->__end_of_arr; ++iter) {
                iter->~value_type();
            }
            alloc.deallocate(begin(), capacity());
        }

        vector &operator=(const vector &vec)
        {
            if (vec.size() > capacity()) {
                reserve(newSize(vec.size() - capacity()));
            } else {
                for (auto iter = begin(); iter != end(); ++iter) {
                    iter->~value_type();
                }
            }
            for (auto source = vec.cbegin(), destination = begin();
                 source != vec.cend();
                 ++source, ++destination) {
                *destination = *source;
            }
            return *this;
        }
/*
        //assign
        void assign(size_type size, const value_type &value)
        {
            for (auto iter = begin(); iter != __end; ++iter) {
                iter->~value();
            }
            for (__end = begin(); __end != begin() + size; ++__end) {
                *__end = value;
            }
        }

        template< class InputIt >
        void assign(InputIt first, InputIt last)
        {
            for (auto iter = begin(); iter != __end; ++iter) {
                iter->~value();
            }
            __end = copy(first, last, begin());
        }

        //element access
        reference at(size_type position)
        {
            auto iter = begin() + position;
            if (iter < begin() || iter > __end_of_arr) throw std::out_of_range("vector index out of range.");
            return *iter;
        }

        reference operator[](size_type position)
        {
            return *(begin() + position);
        }

        reference front()
        {
            return *begin();
        }

        reference back()
        {
            return *__end;
        }

        pointer data()
        {
            return static_cast<pointer>(begin());
        }
*/
        //iterators
        iterator begin()
        {
            return __begin;
        }

        const_iterator begin() const
        {
            return __begin;
        }

        iterator end()
        {
            return __end;
        }

        const_iterator end() const
        {
            return __end;
        }
/*
        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const
        {
            return reverse_iterator(end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const
        {
            return reverse_iterator(begin());
        }
*/
        const_iterator cbegin() const
        {
            return begin();
        }

        const_iterator cend() const
        {
            return end();
        }

        const_reverse_iterator crbegin() const
        {
            return const_reverse_iterator(end());
        }

        const_reverse_iterator crend() const
        {
            auto result = const_reverse_iterator(begin());
            return result;
        }
/*
        //capacity and size
        bool empty() const
        {
            return __begin == __end;
        }
*/
        size_type size() const
        {
            return __end - __begin;
        }
/*
        size_type max_size() const
        {
            return capacity();
        }
*/
        void reserve(size_type newCapacity)//extend the current capacity to newCapacity
        {
            if (newCapacity <= capacity()) return;
            Alloc alloc = Alloc();
            iterator iter = alloc.allocate(newCapacity);
            alloc.construct(iter, value_type());
            copy(begin(), end(), iter);
            for (auto i = begin(); i != end(); ++i) {
                i->~value_type();
            }
            alloc.deallocate(begin(), capacity());
            __end = iter + this->size();
            __begin = iter;
            __end_of_arr = __begin + newCapacity;
        }

        size_type capacity() const
        {
            return __end_of_arr - __begin;
        }
/*
        //modifier
        void clear()//Removes all elements from the container
        {
            for (auto iter = begin(); iter != __end; ++iter) {
                iter->~value_type();
            }
            __end = begin();
        }

        iterator insert(iterator position, const value_type &value)
        {
            if (size() == capacity()) {
                difference_type diff = position - begin();//position will be invalid if the space is reshaped
                reserve(newSize());
                position = begin() + diff;
            }
            auto iter = __end - 1;
            for (; iter != position - 1; --iter) {
                *(iter + 1) = *iter;
            }
            *iter = value;
            ++__end;
            return position;
        }

        iterator insert(iterator position, size_type count, const value_type &value)
        {
            if (size() + count > capacity()) {
                difference_type diff = position - begin();
                reserve(newSize());
                position = begin() + diff;
            }
            auto iter = __end - 1;
            for (; iter != position - 1; --iter) {
                *(iter + count) = *iter;
            }
            for (; iter != position + count; ++iter) {
                *iter = value;
            }
            __end += count;
            return position;
        }

        iterator erase(iterator position)//Removes specified elements from the container
        {
            auto iter = position;
            iter->~value();
            for (++iter; iter != __end; ++iter) {
                *(iter - 1) = *iter;
            }
            --__end;
            return position;
        }

        iterator erase(iterator first, iterator last)
        {
            auto iter = first;
            difference_type count = last - first;
            for (; iter != last; ++iter) {
                iter->~value();
            }
            for (; iter != __end; ++iter) {
                *(iter - count) = *iter;
            }
            __end -= count;
            return first;
        }
*/
        void push_back(const value_type &value)
        {
            if (capacity() == size()) {
                reserve(newSize());
            }
            *(__end++) = value;
        }
/*
        void pop_back()//Removes the last element of the container.
        {
            --__end;
            __end->~value_type();
        }

        void resize(size_type size)
        {
            if (size < this->size()) {
                for (auto iter = begin() + size; iter != __end; ++iter) {
                    iter->~value_type();
                }
                __end -= this->size() - size;
            } else {
                if (size > capacity()) {
                    reserve(newSize(size - capacity()));
                }
                for (; __end != begin() + size; ++__end) {
                    *__end = value_type();
                }
            }
        }

        void resize(size_type size, const value_type &value)
        {
            if (size < this->size()) {
                for (auto iter = begin() + size; iter != __end; ++iter) {
                    iter->~value_type();
                }
                __end -= this->size() - size;
            } else {
                if (size > capacity()) {
                    reserve(newSize(size - capacity()));
                }
                for (; __end != begin() + size; ++__end) {
                    *__end = value;
                }
            }
        }
*/
        template <typename iter>
        friend void swap(vector<iter> &vec1, vector<iter> &vec2);

    private:
        static const size_type criticalCapacity= 128;
        //when capacity is small, the space will extend fastly
        size_type newSize(size_type more = 1)
        {
            size_type newCapacityLowBound = capacity() + more;
            size_type newCapacity = capacity();
            if (newCapacity == 0) ++newCapacity;
            while (newCapacity <= newCapacityLowBound) {
                if (newCapacity < criticalCapacity) {
                    newCapacity *= 4;
                } else {
                    newCapacity *= 2;
                }
            }
            return newCapacity;
        }

    protected:
        iterator __begin;
        iterator __end;
        iterator __end_of_arr;
    };
/*
    template <typename iter>
    void swap(vector<iter> &vec1, vector<iter> &vec2)
    {
        typename vector<iter>::iterator begin_temp, end_of_arr_temp, end_temp;
        begin_temp = vec1.begin();
        end_temp = vec1.end();
        end_of_arr_temp = vec1.__end_of_arr;

        vec1.__begin = vec2.begin();
        vec1.__end = vec2.end();
        vec1.__end_of_arr = vec2.__end_of_arr;

        vec2.__begin = begin_temp;
        vec2.__end = end_temp;
        vec2.__end_of_arr = end_of_arr_temp;
    }
    */
}


#endif //MINI_STL_VECTOR_H

//
// Created by cjw on 2018/6/15.
//

#ifndef MINI_STL_VECTOR_H
#define MINI_STL_VECTOR_H


#include <cstddef>
#include "myIterator.h"
#include <stdexcept>
#include <memory>
#include <iostream>//for test



namespace miniSTL {
    //rvalue reference && not added
    template <typename T, typename Alloc = std::allocator<T>>
    class vector {
    public:
        //type definition
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

        explicit vector(size_type size)//tested
        {
            allocator_type alloc = allocator_type();
            __begin = alloc.allocate(size);
            __end = __begin;
            __end_of_arr = __begin + size;
        }

        vector(const vector &initVec)//tested
        {
            allocator_type alloc;
            __begin = alloc.allocate(initVec.capacity());
            __end_of_arr = __begin + initVec.capacity();
            difference_type size = initVec.size();
            __end = __begin + size;
            iterator destination = this->begin();
            
            //copy elements of vector
            for (auto *source = initVec.cbegin();
                 source != initVec.cend();
                 ++source, ++destination) {
                *destination = *source;
            }
        }

        vector(size_type size, const value_type &value)//tested
        {
            allocator_type alloc;
            __begin = alloc.allocate(size);
            __end_of_arr = __end = __begin + size;
            
            //assign initial value
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

        vector &operator=(const vector &vec)//tested
        {
            if (vec.size() > capacity()) {
                //need to re-allocate the space
                reserve(newSize(vec.size() - capacity()));
            } else {
                for (auto iter = begin(); iter != end(); ++iter) {
                    iter->~value_type();
                }
            }
            //copy elements from another vector
            for (auto source = vec.cbegin(), destination = begin();
                 source != vec.cend();
                 ++source, ++destination) {
                *destination = *source;
            }
            return *this;
        }

        //assign
        //bug: 当对vector<double>调用assign(int, int)时似乎会把函数匹配错误
        void assign(size_type size, const value_type &value)
        {
            //free space of previous elements
            for (auto iter = begin(); iter != __end; ++iter) {
                iter->~value_type();
            }
            
            //assign new value
            for (__end = begin(); __end != begin() + size; ++__end) {
                *__end = value;
            }
        }
        
        //bug: 当对vector<double>调用assign(int, int)时似乎会把函数匹配错误
        //assign elements of [first, last) to this vector
        template <class InputIt>
        void assign(InputIt first, InputIt last)
        {
            for (auto iter = begin(); iter != __end; ++iter) {
                iter->~value_type();
            }
            __end = copy(first, last, begin());
        }

        //element access, the difference from operator[]: this method will throw exception if the index is out of range
        reference at(size_type position)//tested
        {
            auto iter = begin() + position;
            if (iter < begin() || iter >= end()) throw std::out_of_range("vector index out of range.");
            return *iter;
        }

        reference operator[](size_type position)//tested
        {
            return *(begin() + position);
        }

        //return the first element of vector
        reference front()//tested
        {
            return *begin();
        }

        //return the last element of vector
        reference back()//tested
        {
            return *(end() - 1);
        }

        //return the raw pointer of the data array inside the vector
        pointer data()//tested
        {
            return static_cast<pointer>(begin());
        }

        //iterators
        iterator begin()//tested
        {
            return __begin;
        }

        const_iterator begin() const//tested
        {
            return __begin;
        }

        iterator end()//tested
        {
            return __end;
        }

        const_iterator end() const//tested
        {
            return __end;
        }

        //reverse iterator
        reverse_iterator rbegin()//tested
        {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const//tested
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

        //const iterator
        const_iterator cbegin() const
        {
            return __begin;
        }

        const_iterator cend() const
        {
            return __end;
        }
        
        //const reverse iterator has some bugs
        /*
        const_reverse_iterator crbegin() const
        {
            return const_reverse_iterator(__end);
        }

        const_reverse_iterator crend() const
        {
            return const_reverse_iterator(__begin);
        }
*/
        //capacity and size
        bool empty() const//tested
        {
            return __begin == __end;
        }

        //return the size of the data in the vector
        size_type size() const//tested
        {
            return __end - __begin;
        }

        //return the capacity of the vector instead of the size of dat
        size_type max_size() const//tested
        {
            return capacity();
        }

        //reserve space for vector
        void reserve(size_type newCapacity)//extend the current capacity to newCapacity //tested
        {
            //if new capcacity is less then the current capacity, then do nothing
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

        size_type capacity() const//tested
        {
            return __end_of_arr - __begin;
        }

        //modifier
        //Removes all elements from the container
        void clear()//tested
        {
            for (auto iter = begin(); iter != __end; ++iter) {
                iter->~value_type();
            }
            __end = begin();
        }

        //insert the given value into the given position of vector, and return the iterator pointing the position
        iterator insert(iterator position, const value_type &value)//tested
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
            *position = value;
            ++__end;
            return position;
        }

        //insert count given value in given position
        iterator insert(iterator position, size_type count, const value_type &value)//tested
        {
            if (size() + count > capacity()) {
                //need to re-allocate the space
                difference_type diff = position - begin();
                reserve(newSize());
                position = begin() + diff;
            }
            
            //move elements
            auto iter = __end - 1;
            for (; iter != position - 1; --iter) {
                *(iter + count) = *iter;
            }
            ++iter;
            
            //assign new element
            for (; iter != position + count; ++iter) {
                *iter = value;
            }
            __end += count;
            return position;
        }

        iterator erase(iterator position)//Removes specified elements from the container
        {
            auto iter = position;
            iter->~value_type();
            for (++iter; iter != __end; ++iter) {
                *(iter - 1) = *iter;
            }
            --__end;
            return position;
        }

        iterator erase(iterator first, iterator last)//tested
        {
            auto iter = first;
            difference_type count = last - first;
            for (; iter != last; ++iter) {
                iter->~value_type();
            }
            for (; iter != __end; ++iter) {
                *(iter - count) = *iter;
            }
            __end -= count;
            return first;
        }

        void push_back(const value_type &value)//tested
        {
            if (capacity() == size()) {
                reserve(newSize());
            }
            *(__end++) = value;
        }

        void pop_back()//Removes the last element of the container. //tested
        {
            --__end;
            __end->~value_type();
        }

        void resize(size_type size)//tested
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

        //resize the vector, if new size is smaller than the current size, the remaining elements will be removed
        void resize(size_type size, const value_type &value)//tested
        {
            if (size < this->size()) {
                //new size is smaller, remove some elements
                for (auto iter = begin() + size; iter != __end; ++iter) {
                    iter->~value_type();
                }
                __end -= this->size() - size;
            } else {
                if (size > capacity()) {
                    //re-allocate the space of vector
                    reserve(newSize(size - capacity()));
                }
                
                //assign new value
                for (; __end != begin() + size; ++__end) {
                    *__end = value;
                }
            }
        }

        template <typename iter>
        friend void swap(vector<iter> &vec1, vector<iter> &vec2);
        
        //test
        //this method is designed for test to print elements of the vector in a single line
        void print()
        {
            for (auto iter = cbegin(); iter != cend(); ++iter) {
                std::cout << *iter << " ";
            }
            std::cout << std::endl;
        }

    private:
        //critical capcacity to determine the increasing factor
        static const size_type criticalCapacity= 128;
        
        //determine the new size if the space of the vector need to be re-allocated
        //when capacity is small, the space will extend fastly (multiply by 4), when space is large, multiplied by 2
        size_type newSize(size_type more = 1)//tested
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
        iterator __begin; //pointer to the first element
        iterator __end;//pointer to the last element
        iterator __end_of_arr;//pointer to the tail of vector space
    };

    //swap two vectors' elements
    template <typename iter>
    void swap(vector<iter> &vec1, vector<iter> &vec2)//tested
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
}


#endif //MINI_STL_VECTOR_H

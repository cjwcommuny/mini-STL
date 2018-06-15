//
// Created by cjw on 2018/6/15.
//

#ifndef MINI_STL_VECTOR_H
#define MINI_STL_VECTOR_H

//#include <iterator>

#include <cstddef>
#include <memory>

namespace miniSTL {

    template <typename T>
    class vector {
    public:
        using sizeT = size_t

        class iterator {

        };

        //constructor
        vector();
        vector(vector<T> initVec);
        vector(sizeT num, T value);

        //destructor
        ~vector();

        //assignment
        vector<T> &operator=(vector<T> vec);
        void assign(sizeT num, T value);//assign value in batch

        //other method
        iterator begin();
        iterator end();


        //access
        T at(sizeT index);
        T operator[](sizeT index);
        T &front();
        T &back();
        T *data(); //return underlining array

        //capacity
        bool empty();
        sizeT size();
        sizeT max_size();
        void reserve(sizeT newCapacity);//extend the current capacity to newCapacity


        //modifier
        void clear(); //leave capacity unchanged
        void push_back(T value);
        //vector<T> &emplace_back();
        void pop_back();
        void resize(sizeT newSize);
        void resize(sizeT newSize, const T &value);
        void swap(vector<T> &vec);

        /* omitted
         * get_allocator
         * cbegin
         * cend
         * rbegin
         * rend
         * crbegin
         * crend
         * shrink_to_fit
         * insert
         * emplace
         * erase
         * non-member function
         */
    private:
        static const sizeT initDefaultSize;//as init count of constructor
        T *_begin;
        T *_end;//end of the storage
        T *_last;//the position of last element
    protected:
    };
}

#endif //MINI_STL_VECTOR_H

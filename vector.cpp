//
// Created by cjw on 2018/6/15.
//


#include <stdexcept>
#include "vector.h"

namespace miniSTL {
    template <typename T>
    vector::vector()
    {
        std::allocator<T> alloc;
        _begin = alloc.allocate(initDefaultSize);
        _end = _begin + initDefaultSize;
        _last = _begin;
    }

    template <typename T>
    T vector::at(sizeT index)
    {
        T *valuePointer = _begin + index;
        if (valuePointer >= _end || valuePointer < _begin) throw std::out_of_range;//?
        return *(valuePointer);
    }

    template <typename T>
    T vector::operator[](sizeT index)
    {
        return *(_begin + index);
    }

    template <typename T>
    T &vector::front()
    {
        return *_begin;
    }

    template <typename T>
    T &vector::back()
    {
        return *(--_end);
    }

    template <typename T>
    T* vector::data()
    {
        return _begin;
    }

    bool vector::empty()
    {
        return _begin == _end;
    }

    vector::sizeT vector::size()
    {
        return _last - _begin;
    }

    vector::sizeT vector::max_size()
    {
        return _end - _begin;
    }

    void vector::reserve(sizeT newCapacity)
    {
        if (newCapacity <= max_size()) return;
        //TODO
    }

    template <typename T>
    void vector::push_back(T value)
    {
        if (max_size() > size()) {
            *(_last++) = value;
        } else {
            //TODO
        }
    }

    void vector::pop_back()
    {
        //free the last element
        --_last;
    }

    template <typename T>
    void vector::swap(vector<T> &vec)
    {
        T *begin_tmp, *last_tmp, *end_tmp;
        begin_tmp = this->_begin;
        last_tmp = this->_last;
        end_tmp = this->_end;
        this->_begin = vec._begin;
        this->_last = vec._last;
        this->_end = vec._end;
        vec._begin = begin_tmp;
        vec._last = last_tmp;
        vec._end = end_tmp;
    }

    template <typename T>
    vector::vector(vector<T> initVec)
    {
        
        for (auto currentPointer = this->begin(); currentPointer < this->end(); ++currentPointer) {
            
        }
    }
}
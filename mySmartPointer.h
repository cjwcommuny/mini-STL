//
//  smartpointer.h
//  test-mini-STL2
//
//  Created by cjw on 2018/6/18.
//  Copyright © 2018年 cjw. All rights reserved.
//

#ifndef mySmartPointer_h
#define mySmartPointer_h

#include <utility>
#include <iostream>


namespace miniSTL {
    //only support space management in heap
    template <typename T>
    class shared_ptr {
    public:
        using element_type = T;
        //using weak_type =
        
        
        //this method is designer for testing
        void print(std::ostream &stream = std::cout)
        {
            stream << "reference count: " << use_count() << std::endl;
            stream << "element: " << operator*() << std::endl;
        }
        
        //constructor and destructor
        shared_ptr()
        {
            __counter = new counter();
        }
        
        explicit shared_ptr(element_type *ptr)//tested
        {
            __counter = new counter(ptr);
        }
        
        shared_ptr(const shared_ptr<element_type> &ptr2)//tested
        {
            __counter = ptr2.__counter;
            ++__counter->count;
        }
        
        //operator oveload, behave like the normal pointer
        shared_ptr<element_type> &operator=(const shared_ptr<element_type> &ptr2)//tested
        {
            __counter = ptr2.__counter;
            ++__counter->count;
            return *this;
        }
        
        //if the count of reference is 1, then the object pointed will be destroyed. the counter will be reset to 0
        void reset()//tested
        {
            if (__counter != nullptr && __counter->count == 1) {
                __counter->pointer->~element_type();
                __counter->pointer = nullptr;
                __counter->count = 0;
            }
        }
        
        //if the count of reference is 1, destroy the object and reset the pointer to the given one
        void reset(element_type *ptr)//tested
        {
            if (__counter != nullptr && __counter->count == 1) {
                __counter->pointer->~element_type();
                __counter->pointer = ptr;
            }
        }
        
        //swap the object two smart pointer point
        void swap(shared_ptr& ptr)//tested
        {
            auto temp = __counter;
            __counter = ptr.__counter;
            ptr.__counter = temp;
        }
        
        //return the raw pointer inside the smart pointer class
        element_type* get() const//tested
        {
            //assert __counter != nullptr
            return __counter->pointer;
        }
        
        element_type& operator*() const//tested
        {
            return *(__counter->pointer);
        }
        
        element_type* operator->() const//tested
        {
            return &operator*();
        }
        
        //make the smart pointer act like an array
        element_type& operator[](std::ptrdiff_t index)//C++ 17,tested
        {
            return *(__counter->pointer + index);
        }
        
        //return the count of reference
        long long use_count() const//return counter::count_type //tested
        {
            return __counter->count;
        }
        
        //return true if there is only one pointer pointing to the object
        bool unique() const//tested
        {
            return __counter->count == 1;
        }
        
        //convert the smart pointer to bool type
        explicit operator bool() const//tested
        {
            return get() != nullptr;
        }
        
        //variadic template
        template< class element_type, class... Args >
        friend shared_ptr<element_type> make_shared(Args&&... args);
        
        template <typename U>
        friend void swap( shared_ptr<U>& lhs, shared_ptr<U>& rhs );
        
        //binary relational operator
        template < class V, class U >
        friend bool operator==(const shared_ptr<V>& lhs, const shared_ptr<U>& rhs);
        
        template< class V, class U >
        friend bool operator!=( const shared_ptr<V>& lhs, const shared_ptr<U>& rhs );
        
        /*
        template< class V, class U >
        friend bool operator<( const shared_ptr<V>& lhs, const shared_ptr<U>& rhs );
        
        template< class V, class U >
        friend bool operator>( const shared_ptr<V>& lhs, const shared_ptr<U>& rhs );
        
        template< class V, class U >
        friend bool operator<( const shared_ptr<V>& lhs, const shared_ptr<U>& rhs );
        
        template< class V, class U >
        friend bool operator<=( const shared_ptr<V>& lhs, const shared_ptr<U>& rhs );
        
        template< class V, class U >
        friend bool operator<( const shared_ptr<V>& lhs, const shared_ptr<U>& rhs );
        
        template< class V, class U >
        friend bool operator>=( const shared_ptr<V>& lhs, const shared_ptr<U>& rhs );
        */
        
        template< class V >
        friend bool operator==( const shared_ptr<V>& lhs, std::nullptr_t rhs );//tested
        
        template< class V >
        friend bool operator!=( const shared_ptr<V>& lhs, std::nullptr_t rhs );//tested
        
        /*
        template< class V >
        friend bool operator>( const shared_ptr<V>& lhs, std::nullptr_t rhs );
        
        template< class V >
        friend bool operator<( const shared_ptr<V>& lhs, std::nullptr_t rhs );
        
        template< class V >
        friend bool operator>=( const shared_ptr<V>& lhs, std::nullptr_t rhs );
        
        template< class V >
        friend bool operator<=( const shared_ptr<V>& lhs, std::nullptr_t rhs );
        */
        
        template< class V >
        friend bool operator==( std::nullptr_t lhs, const shared_ptr<V>& rhs );//tested
        
        template< class V >
        friend bool operator!=( std::nullptr_t lhs, const shared_ptr<V>& rhs );//tested
        
        /*
        template< class V >
        friend bool operator<( std::nullptr_t lhs, const shared_ptr<V>& rhs );
        
        template< class V >
        friend bool operator>( std::nullptr_t lhs, const shared_ptr<V>& rhs );
        
        template< class V >
        friend bool operator<=( std::nullptr_t lhs, const shared_ptr<V>& rhs );
        
        template< class V >
        friend bool operator>=( std::nullptr_t lhs, const shared_ptr<V>& rhs );
        */
        
        //explicit shared_ptr( const std::weak_ptr<Y>& r );
        //shared_ptr( std::unique_ptr<Y,Deleter>&& r );
        
    private:
        
        //counter is a private class for containing the reference counter and the real pointer pointing to the object
        class counter {
        public:
            using count_type = long long;
            using element_type = T;
            
            //constructor and desturctor
            counter(): count(0), pointer(nullptr) {}
            counter(element_type *ptr): count(1), pointer(ptr) {}
            
            ~counter()
            {
                if (pointer != nullptr) {
                    delete pointer;
                }
            }
            
            //refernce counter
            count_type count;
            
            //raw pointer
            element_type *pointer;
        private:
        };
        
        //pointer to a counter class
        counter *__counter;
    };
    
    template< class element_type, class... Args >
    shared_ptr<element_type> make_shared(Args&&... args)//has bug
    {
        return shared_ptr<element_type>(element_type(std::forward<Args...>(args...)));
    }
    
    template < class V, class U >
    bool operator==(const shared_ptr<V>& lhs, const shared_ptr<U>& rhs)//tested
    {
        return lhs.get() == rhs.get();
    }
    
    template< class V, class U >
    bool operator!=( const shared_ptr<V>& lhs, const shared_ptr<U>& rhs )//tested
    {
        return lhs.get() != rhs.get();
    }
    
    /*
    template< class V, class U >
    bool operator<( const shared_ptr<V>& lhs, const shared_ptr<U>& rhs )
    {
        return lhs.get() < rhs.get();
    }
    
    template< class V, class U >
    bool operator>( const shared_ptr<V>& lhs, const shared_ptr<U>& rhs )
    {
        return lhs.get() > rhs.get();
    }
    
    template< class V, class U >
    bool operator<=( const shared_ptr<V>& lhs, const shared_ptr<U>& rhs )
    {
        return lhs.get() <= rhs.get();
    }
    
    template< class V, class U >
    bool operator>=( const shared_ptr<V>& lhs, const shared_ptr<U>& rhs )
    {
        return lhs.get() >= rhs.get();
    }
    */
    
    template< class V >
    bool operator==( const shared_ptr<V>& lhs, std::nullptr_t rhs )
    {
        return !lhs;
    }
    
    template< class V >
    bool operator==( std::nullptr_t lhs, const shared_ptr<V>& rhs )
    {
        return !rhs;
    }
    
    template< class V >
    bool operator!=( const shared_ptr<V>& lhs, std::nullptr_t rhs )
    {
        return (bool) lhs;
    }
    
    template< class V >
    bool operator!=( std::nullptr_t lhs, const shared_ptr<V>& rhs )
    {
        return (bool) rhs;
    }
    
    /*
    template< class V >
    bool operator<( const shared_ptr<V>& lhs, std::nullptr_t rhs )
    {
        return lhs.get() < nullptr;
    }
    
    template< class V >
    bool operator<( std::nullptr_t lhs, const shared_ptr<V>& rhs )
    {
        return nullptr < rhs.get();
    }
    
    template< class V >
    bool operator>( const shared_ptr<V>& lhs, std::nullptr_t rhs )
    {
        return lhs.get() > nullptr;
    }
    
    template< class V >
    bool operator>( std::nullptr_t lhs, const shared_ptr<V>& rhs )
    {
        return nullptr > rhs.get();
    }
    
    template< class V >
    bool operator<=( const shared_ptr<V>& lhs, std::nullptr_t rhs )
    {
        return lhs.get() <= nullptr;
    }
    
    template< class V >
    bool operator<=( std::nullptr_t lhs, const shared_ptr<V>& rhs )
    {
        return nullptr <= rhs.get();
    }
    
    template< class V >
    bool operator>=( const shared_ptr<V>& lhs, std::nullptr_t rhs )
    {
        return lhs.get() >= nullptr;
    }
    
    template< class V >
    bool operator>=( std::nullptr_t lhs, const shared_ptr<V>& rhs )
    {
        return nullptr >= rhs.get();
    }
    */
    
    template< class V >
    void swap( shared_ptr<V>& lhs, shared_ptr<V>& rhs )
    {
        auto temp = lhs.__counter;
        lhs.__counter = rhs.__counter;
        rhs.__counter = temp;
    }
}

#endif /* mySmartPointer_h */

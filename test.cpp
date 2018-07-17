//
//  test.cpp
//  test-mini-STL2
//
//  Created by cjw on 2018/6/22.
//  Copyright © 2018年 cjw. All rights reserved.
//

#include "test.h"
#include <iostream>

void testIterator()
{
    //test in testVector()
}

struct st {
    int i;
    double d;
};

void testSmartpointer()
{
    std::cout << std::endl;
    std::cout << "*****SMART POINTER TEST BEGIN******" << std::endl;
    std::cout << std::endl;
    int x = 139;
    int *x_ptr = &x;
    miniSTL::shared_ptr<int> smartptr1(x_ptr);
    miniSTL::shared_ptr<int> smartptr2(smartptr1);
    
    //constructor test
    std::cout << "##constructor test:" << std::endl;
    std::cout << "smart pointer 1 pointing to x = 139" << std::endl;
    std::cout << "smart pointer 1: " << std::endl;
    smartptr1.print();
    std::cout << "smart pointer 2 copy from smart pointer 1: " << std::endl;
    smartptr2.print();
    std::cout << std::endl;
    
    //unique() test
    int y = 102;
    int *y_ptr = &y;
    miniSTL::shared_ptr<int> smartptr4(y_ptr);
    std::cout << "##unique() test:" << std::endl;
    std::cout << "smart pointer: " << std::endl;
    smartptr4.print();
    std::cout << "Is smart pointer unique? 1 means unique: " << std::endl;
    std::cout << smartptr4.unique() << std::endl;
    std::cout << std::endl;
    
    //reset() test
    std::cout << "##reset() test:" << std::endl;
    std::cout << "smart pointer before reset: " << std::endl;
    smartptr4.print();
    smartptr4.reset(y_ptr);
    std::cout << "smart pointer after reset, set counter to 0: " << std::endl;
    smartptr4.print();
    std::cout << std::endl;
    
    //swap() test
    std::cout << "##swap() test:" << std::endl;
    std::cout << "swap two smart pointer" << std::endl;
    std::cout << "first pointer: " << std::endl;
    smartptr2.print();
    std::cout << "second pointer: " << std::endl;
    smartptr4.print();
    std::cout << "after swap: " << std::endl;
    miniSTL::swap(smartptr4, smartptr2);
    std::cout << "first pointer: " << std::endl;
    smartptr2.print();
    std::cout << "second pointer: " << std::endl;
    smartptr4.print();
    std::cout << std::endl;
    
    //operator[] test
    int a[3] = {1,6,3};
    miniSTL::shared_ptr<int> smartptr6(a);
    std::cout << "##operator[] test:" << std::endl;
    std::cout << "pointee is a[3] = {1,6,3}, access pointer by operator[]: " << std::endl;
    std::cout << "pointer[0]: " << smartptr6[0] << " pointer[1]" << smartptr6[1] << " poitner[2]" << smartptr6[2] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    
    //bool convertion test
    std::cout << "##bool convertion test:" << std::endl;
    std::cout << "bool convertion test, smartptr1 is not null, while smartptr2 is null." << std::endl;
    miniSTL::shared_ptr<int> smartptr9;
    std::nullptr_t nul = std::nullptr_t();
    std::cout << "smartptr1 == nul ? " << std::endl << (smartptr9 == nul) << std::endl << " " << "smartptr2 == nul ? " << std::endl << (smartptr4 == nul) << std::endl;
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "*****SMART POINTER TEST END*****" << std::endl;
    std::cout << std::endl;
}

void testVector()
{
    std::cout << std::endl;
    std::cout << "*****VECTOR TEST BEGIN******" << std::endl;
    std::cout << std::endl;
    miniSTL::vector<double> x(4);
    miniSTL::vector<int *> y(4);
    
    
    //push_back test
    std::cout << "##push_back() test:" << std::endl;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    miniSTL::vector<double> z(x);
    std::cout << "push_back_test: empty vector, push_back 1, 2, 3, 4, current vector: " << std::endl;
    x.print();
    std::cout << std::endl;
    
    //front(), back() test
    std::cout << "##front(), back() test" << std::endl;
    std::cout << "x.front(): " << x.front() << " " << std::endl;
    std::cout << "x.back(): " << x.back() << " " << std::endl;
    std::cout << std::endl;
    
    //max_size(), size() test
    std::cout << "##max_size(), size() test" << std::endl;
    std::cout << "max_size: "<< x.max_size() << std::endl;
    std::cout << "size: "<< x.size() << std::endl;
    std::cout << std::endl;
    
    //pop_back() test
    x.pop_back();
    std::cout << "##pop back test, current vector: " << std::endl;
    x.print();
    std::cout << std::endl;
    
    //clear(), empty() test
    std::cout << "##clear(), empty() test:" << std::endl;
    std::cout << "before clear element, current vector: " << std::endl;
    x.print();
    x.clear();
    std::cout << "clear element, current vector: " << std::endl;
    x.print();
    std::cout << "is empty? 1 means empty: " << x.empty() << std::endl;
    std::cout << std::endl;
    
    //copy constructor test
    std::cout << "##copy constructor test:" << std::endl;
    std::cout << "copy from {1,2,3,4}, current vector: " << std::endl;
    z.print();
    std::cout << std::endl;
    
    //reserve() test
    std::cout << "##reserve() test:" << std::endl;
    std::cout << "vector before reserve():" << std::endl;
    z.print();
    z.reserve(1);
    std::cout << "after invoking reserve(1), current vector: " << std::endl;
    z.print();
    std::cout << std::endl;
    
    //insert() test
    std::cout << "##insert() test:" << std::endl;
    std::cout << "before inserted,  the vector: " << std::endl;
    z.print();
    auto iter = z.begin() + 2;
    z.insert(iter, 5, 202);
    std::cout << "insert five '202' in position 2, current vector: " << std::endl;
    z.print();
    std::cout << std::endl;
    
    //erase() test
    std::cout << "##erase() test:" << std::endl;
    std::cout << "before inserted,  the vector: " << std::endl;
    z.print();
    auto iter2 = z.begin() + 2;
    z.erase(iter2);
    std::cout << "erase element in position 2, current vector: " << std::endl;
    z.print();
    std::cout << std::endl;
    
    //resize() test
    std::cout << "##resize() test:" << std::endl;
    std::cout << "before resized, the vector: " << std::endl;
    z.print();
    z.resize(15, 108);
    std::cout << "resize to 15 cells, extra elements are set to 108, current vector: " << std::endl;
    z.print();
    std::cout << std::endl;
    
    //operator= test
    std::cout << "##operator= test:" << std::endl;
    std::cout << "source vector: " << std::endl;
    z.print();
    std::cout << "destination vector (copy from source vector): " << std::endl;
    miniSTL::vector<double> w = z;
    w.print();
    std::cout << std::endl;
    
    //assign() test
    std::cout << "##assign() test:" << std::endl;
    std::cout << "vector before assign: " << std::endl;
    z.print();
    std::cout << "vector after assign 199.1, size = 3: " << std::endl;
    z.assign(3, 199.1);
    z.print();
    std::cout << std::endl;
    
    //iterator and operator* test
    std::cout << "##iterator, operator* test:" << std::endl;
    std::cout << "vector: " << std::endl;
    w.print();
    std::cout << "normal iterator traverse the vector: " << std::endl;
    for (auto iter = w.cbegin(); iter != w.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    std::cout << "reverse iterator traverse the vector: " << std::endl;
    for (auto iter = w.rbegin(); iter != w.rend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "*****VECTOR TEST END*****" << std::endl;
    std::cout << std::endl;
}
















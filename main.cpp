#include <iostream>
#include "myVector.h"
#include <vector>

int main()
{
    miniSTL::vector<double> x(4, 10.2);
    //miniSTL::vector<int *> y(4);
    //miniSTL::vector<double> z(x);
    //x.~vector();
    //auto iter = x.crbegin();

    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    int t = 9;
    //auto rend = x.crend();
    double j = 9.3;

    for (auto iter = x.crbegin(); iter != x.crend(); ++iter) {
        //*iter  = 1;
        std::cout << *iter << std::endl;
    }


    /*
    std::vector<int> vec = {1,2,3,4,5,6,7,8};
    for (auto iter = vec.crbegin(); iter != vec.crend(); ++iter) {
        *iter  = 1;
        std::cout << *iter << std::endl;
    }
*/
    /*
    double a = 13;
    const double b = 14;
    const double *test = &a;
    std::cout << *test << std::endl;
    const double &ref = a;
    const double &ref2 = *test;
     */
    return 0;
}
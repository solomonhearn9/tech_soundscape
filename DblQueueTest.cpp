// File name:
// Author:
// userid:
// Email:
// Class: CS2201 @ Vanderbilt U.
// Assignment Number:
// Description:
// Honor statement:
// Last Changed:

#include "DblQueue.h"
#include <iostream>

int main()
{

    DblQueue<double> d;
    d.enqueue(3);
    d.enqueue(5);
    d.enqueue(6);
    d.dequeue();
    std::cout << d.isEmpty() << std::endl;
    std::cout << d.front() << std::endl;
    std::cout << d.size() << std::endl;


    return 0;
}

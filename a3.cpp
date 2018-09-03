/***
 *  File: a3.cpp
 *  Author: Jaroslaw Zola <jzola@buffalo.edu>
 */

// DO NOT EDIT THIS FILE !!!
// YOUR CODE MUST BE CONTAINED IN a3.hpp ONLY

#include <iostream>
#include "a3.hpp"


int main(int argc, char* argv[]) {
    key_value_sequences A;

    {
        key_value_sequences T;
        // k will be our key
        for (int k = 0; k < 10; ++k) {
            // v is our value
            // here we are creating 10 sequences:
            // key = 0, sequence = (0)
            // key = 1, sequence = (0 1)
            // key = 2, sequence = (0 1 2)
            // ...
            // key = 9, sequence = (0 1 2 3 4 5 6 7 8 9)
            for (int v = 0; v < k + 1; ++v) T.insert(k, v);
        }

        T = T;

        key_value_sequences V = T;
        A = V;
    }

    std::vector<int> ref;

    if (A.size(-1) != -1) {
        std::cout << "fail" << std::endl;
        return -1;
    }

    for (int k = 0; k < 10; ++k) {
        if (A.size(k) != k + 1) {
            std::cout << "fail";
            return -1;
        } else {
            ref.clear();
            for (int v = 0; v < k + 1; ++v) ref.push_back(v);
            if (!std::equal(ref.begin(), ref.end(), A.data(k))) {
                std::cout << "fail";
                return -1;
            }
        }
    }

    std::cout << "pass" << std::endl;

    return 0;
} // main

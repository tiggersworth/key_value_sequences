/***
 *  File: a3.hpp
 *  Author: Tammy Chang 
 */

#ifndef A3_HPP
#define A3_HPP
#include <algorithm>
#include <list>
#include <vector>
using namespace std;
class key_value_sequences {
public:
    // YOU SHOULD USE C++ CONTAINERS TO AVOID RAW POINTERS
    // IF YOU DECIDE TO USE POINTERS, MAKE SURE THAT YOU MANAGE MEMORY PROPERLY

    // SHOULD RETURN SIZE OF A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN -1

    int size(int key) {
    
      int key1 = bsearch(key);

      if(potkey == true){
        return valuevector[key1].size();
      }
      if(potkey == false){
      return -1;
    }
    }


    // SHOULD RETURN POINTER TO A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN nullptr
     int* data(int key) {
    /*  for(int i =0; i < keyvector.size(); ++i){
        if(keyvector[i] == key){
        return valuevector[i].data();
        }
      }
      // once it reaches this point, it has not found a match
    return nullptr;

    */
    int bla = bsearch(key);

    if( potkey == true){
      return valuevector[bla].data();
    }
    if(potkey == false){
      return nullptr;
    }
    }

    //returns position to insert key
    int bsearch (int key) {
      flag = false;
      int left = 0;
      int right = keyvector.size() -1;
      while (left <= right){
        int middle = (left + right) / 2;
        if(keyvector[middle] == key){
            flag = true;
            potkey = true;
            return middle;   //key exists return position
        }
        if (keyvector[middle] > key ) {
          right = middle -1;
        }
        if(keyvector[middle] < key){
          left = middle +1;
        }
      }
      potkey = false;
      return left; // key doesn't exist, return left position to insert at
    }

    // INSERT VALUE INTO A SEQUENCE IDENTIFIED BY GIVEN KEY
    void insert(int key, int value){
      int position = bsearch(key);

      //key exists
      if(flag == true){
      valuevector[position].push_back(value);
      }

      //key doesn't exist
      if(flag != true){
          keyvector.insert( keyvector.begin()+ position, key ); 
          std::vector<int> newvector;
          newvector.push_back(value);
          valuevector.insert( valuevector.begin()+ position, newvector); 
      }


  /*  //if key already exists
      for(int i =0; i < keyvector.size(); ++i){
      if(keyvector[i] == key){ //it exists!!!
         valuevector[i].push_back(value);
        }
      }

      if(std::find(keyvector.begin(), keyvector.end(), key) == keyvector.end()) {
        //key doesn't exist
          keyvector.push_back(key);
          std::vector<int> valuev;
          valuev.push_back(value);
          valuevector.push_back(valuev);
      }
      */
  }

private:
  std::vector <std::vector<int>> valuevector;
  std::vector<int> keyvector;
  bool flag;
  bool potkey;
  //int v;
}; // class key_value_sequences

#endif // A3_HPP

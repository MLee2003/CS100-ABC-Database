#include "../headers/Databases/LinkedListDatabase.h"
#include "../src/nodes/JSONNode.cpp"

#include <string>
#include <sstream>
using namespace std;


string LinkedListDatabase::at(int index){
    LinkedListNode* temp = head;
    int cur = 0;
    while(temp && cur < index){
        temp = temp->next;
        cur++;
    }
    return temp->data->print();
}

//example context add/str
void LinkedListDatabase::add(const string &context){
    istringstream ss(context);
    int idx = context.rfind('/');
    string name = context.substr(idx+1);
    string temp;
    ss >> temp >> temp >> temp;
    if(temp.substr(0,4) == "json"){
        if(head == nullptr){
            head = new LinkedListNode(new JSONDatabaseNode(temp.substr(6,temp.length()-6)));
            tail = head;
        }else{
            tail->next = new LinkedListNode(new JSONDatabaseNode(temp.substr(6,temp.length()-6)));
            tail = tail->next;
        }
    }
}
DatabaseNode* LinkedListDatabase::get(const string &context){
    istringstream ss(context);
    string temp;
    ss >> temp >> temp >> temp;
    if(temp.substr(0,4) == "json"){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i]->print() ==  temp.substr(6,temp.length()-6)){
                return arr[i];
            }
        }
    }
    return nullptr;
}    
void LinkedListDatabase::set(const string &context){
    //??
}
void LinkedListDatabase::remove(const string &context){
    istringstream ss(context);
    string temp;
    ss >> temp >> temp >> temp;
    if(temp.substr(0,4) == "json"){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i]->print() ==  temp.substr(6,temp.length()-6)){
                arr.erase(arr.begin()+i);
            }
        }
    }
}
// #ifndef ARRAYDATABASE
// #define ARRAYDATABASE
// #include "SortingStrats/SortingStrategy.hpp"
// #include <bits/stdc++.h>

// #include "../headers/Database.h"
// using namespace std;

// class ArrayDatabase : Database{
// private:
//     DatabaseNode *arr = nullptr;
//     int size;
// public:
//     string at(unsigned int index){
//         if(index < 0 || index >= size) return "";
//         return arr[index];
//     }
    
//     unsigned int size(){
//         return size;
//     }
    
//     void sort(string sortStrat="insertion"){
//         SortingStrategy* strat = nullptr;
//         if(toLower(sortStrat) == "bogo"){
//             strat = new BogoSort(size);
//         }else if(toLower(sortStrat) == "quick"){
//             strat = new QuickSort(size);
//         }else{
//             strat = new InsertionSort(size);
//         }
//         strat->sort(array);
//         delete strat;
//     }
// }
// #endif

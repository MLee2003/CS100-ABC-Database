#ifndef __DATABASE_TEST_HPP__
#define __DATABASE_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>  

using namespace std;
#include "../src/DatabaseManager.cpp"

DatabaseManager* manager = new DatabaseManager();


//QuickSort

TEST(ARRAYDBTest, QuickSortTesting) {
   manager->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager->getDatabase("test")->add("string test_s" + to_string(i));
   }
   manager->getDatabase("test")->QuickSort();
   EXPECT_EQ(0, manager->getDatabase("test")->at(0));
}


TEST(ARRAYDBTest, QuickSortTestingJSON) {
   manager->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager->getDatabase("test3")->add("json test_j {\"key\":\"to_string(i)\"}");
   }
   manager->getDatabase("test3")->QuickSort();
   EXPECT_EQ("{\"key\":\"0\"}", manager->getDatabase("test3")->at(0));
}

//Array selectionsort

TEST(ARRAYDBTest, SelectionSortTesting) {
   manager->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager->getDatabase("test")->add("string test_s" + to_string(i));
   }
   manager->getDatabase("test")->SelectionSort();
   EXPECT_EQ(0, manager->getDatabase("test")->at(0));
}



TEST(ARRAYDBTest, SelectionSortTestingJSON) {
   manager->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager->getDatabase("test3")->add("json test_j {\"key\":\"to_string(i)\"}");
   }
   manager->getDatabase("test3")->SelectionSort();
   EXPECT_EQ("{\"key\":\"0\"}", manager->getDatabase("test3")->at(0));
}


//BOGO

TEST(ARRAYDBTest, BogoSortTesting) {
   manager->createDatabase("test", "array");
   for (int i = 0; i < 3; i++) {
      manager->getDatabase("test")->add("string test_s" + to_string(i));
   }
   manager->getDatabase("test")->BogoSort();
   EXPECT_EQ(0, manager->getDatabase("test")->at(0));
}

TEST(ARRAYDBTest, BogoSortTestingJSON) {
   manager->createDatabase("test", "array");
   for (int i = 0; i < 3; i++) {
      manager->getDatabase("test3")->add("json test_j {\"key\":\"to_string(i)\"}");
   }
   manager->getDatabase("test3")->BogoSort();
   EXPECT_EQ("{\"key\":\"0\"}", manager->getDatabase("test3")->at(0));
}
//insetionSort

TEST(ARRAYDBTest, InsertionSortTesting) {
   manager->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager->getDatabase("test")->add("string test_s" + to_string(i));
   }
   manager->getDatabase("test")->BogoSort();
   EXPECT_EQ(0, manager->getDatabase("test")->at(0));
}

TEST(ARRAYDBTest, InsertionSortTestingJSON) {
   manager->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager->getDatabase("test3")->add("json test_j {\"key\":\"to_string(i)\"}");
   }
   manager->getDatabase("test3")->BogoSort();
   EXPECT_EQ("{\"key\":\"0\"}", manager->getDatabase("test3")->at(0));
}





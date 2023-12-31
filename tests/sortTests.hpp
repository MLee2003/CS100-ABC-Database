#ifndef __SORT_TEST_HPP__
#define __SORT_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>

using namespace std;

DatabaseManager *manager2 = new DatabaseManager();

// QuickSort

TEST(ARRAYSORTDBTest, QuickSortTesting)
{
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++)
   {
      manager2->getDatabase("test")->add("string test_s" + to_string(i) + " " + to_string(i));
   }
   manager2->getDatabase("test")->sort("quick");
   EXPECT_EQ("0", manager2->getDatabase("test")->at(0));
}

TEST(ARRAYSORTDBTest, QuickSortTestingJSON)
{
   manager2->createDatabase("test3", "array");
   for (int i = 0; i < 10; i++)
   {
      manager2->getDatabase("test3")->add("json test_j" + to_string(i) + " {\"key\":\"" + to_string(i) + "\"}");
   }
   manager2->getDatabase("test3")->sort("quick");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0));
}

// Array selectionsort

TEST(ARRAYSORTDBTest, SelectionSortTesting) {
   manager2->createDatabase("test4", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test4")->add("string test_s" + to_string(i) + " " + to_string(i));
   }
   manager2->getDatabase("test4")->sort("selection");
   EXPECT_EQ("0", manager2->getDatabase("test4")->at(0));
}

TEST(ARRAYSORTDBTest, SelectionSortTestingJSON) {
   manager2->createDatabase("test5", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test5")->add("json test_j" + to_string(i) + " {\"key\":\"" + to_string(i) + "\"}");
   }
   manager2->getDatabase("test3")->sort("selection");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test5")->at(0));
}

//BOGO
TEST(ARRAYSORTDBTest, BogoSortTesting) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 3; i++) {
      manager2->getDatabase("test")->add("string test_s" + to_string(i) + " " + to_string(i));
   }
   manager2->getDatabase("test")->sort("bogo");
   EXPECT_EQ("0", manager2->getDatabase("test")->at(0));
}

TEST(ARRAYSORTDBTest, BogoSortTestingJSON) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 3; i++) {
      manager2->getDatabase("test3")->add("json test_j" + to_string(i) + " {\"key\":\"" + to_string(i) + "\"}");
   }
   manager2->getDatabase("test3")->sort("bogo");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0));
}
//insetionSort

TEST(ARRAYSORTDBTest, InsertionSortTesting) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test")->add("string test_s" + to_string(i) + " " + to_string(i));
   }
   manager2->getDatabase("test")->sort("insertion");
   EXPECT_EQ("0", manager2->getDatabase("test")->at(0));
}

TEST(ARRAYSORTDBTest, InsertionSortTestingJSON) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test3")->add("json test_j" + to_string(i) + " {\"key\":\"" + to_string(i) + "\"}");
   }
   manager2->getDatabase("test3")->sort("insertion");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0));
}

TEST(ARRAYSORTDBTest, DatabaseDelete) {
   manager2->removeDatabase("test");
   manager2->removeDatabase("test2");
   manager2->removeDatabase("test3");
   manager2->removeDatabase("test4");
   manager2->removeDatabase("test5");
}


TEST(LINKEDLISTSORTDBTest, QuickSortTesting)
{
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++)
   {
      manager2->getDatabase("test")->add("string test_s" + to_string(i) + " " + to_string(i));
   }
   manager2->getDatabase("test")->sort("quick");
   EXPECT_EQ("0", manager2->getDatabase("test")->at(0));
}

TEST(LINKEDLISTSORTDBTest, QuickSortTestingJSON)
{
   manager2->createDatabase("test3", "array");
   for (int i = 0; i < 10; i++)
   {
      manager2->getDatabase("test3")->add("json test_j" + to_string(i) + " {\"key\":\"" + to_string(i) + "\"}");
   }
   manager2->getDatabase("test3")->sort("quick");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0));
}

// Array selectionsort

TEST(LINKEDLISTSORTDBTest, SelectionSortTesting) {
   manager2->createDatabase("test4", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test4")->add("string test_s" + to_string(i) + " " + to_string(i));
   }
   manager2->getDatabase("test4")->sort("selection");
   EXPECT_EQ("0", manager2->getDatabase("test4")->at(0));
}

TEST(LINKEDLISTSORTDBTest, SelectionSortTestingJSON) {
   manager2->createDatabase("test5", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test5")->add("json test_j" + to_string(i) + " {\"key\":\"" + to_string(i) + "\"}");
   }
   manager2->getDatabase("test3")->sort("selection");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test5")->at(0));
}

//BOGO
TEST(LINKEDLISTSORTDBTest, BogoSortTesting) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 3; i++) {
      manager2->getDatabase("test")->add("string test_s" + to_string(i) + " " + to_string(i));
   }
   manager2->getDatabase("test")->sort("bogo");
   EXPECT_EQ("0", manager2->getDatabase("test")->at(0));
}

TEST(LINKEDLISTSORTDBTest, BogoSortTestingJSON) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 3; i++) {
      manager2->getDatabase("test3")->add("json test_j" + to_string(i) + " {\"key\":\"" + to_string(i) + "\"}");
   }
   manager2->getDatabase("test3")->sort("bogo");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0));
}
//insetionSort

TEST(LINKEDLISTSORTDBTest, InsertionSortTesting) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test")->add("string test_s" + to_string(i) + " " + to_string(i));
   }
   manager2->getDatabase("test")->sort("insertion");
   EXPECT_EQ("0", manager2->getDatabase("test")->at(0));
}

TEST(LINKEDLISTSORTDBTest, InsertionSortTestingJSON) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test3")->add("json test_j" + to_string(i) + " {\"key\":\"" + to_string(i) + "\"}");
   }
   manager2->getDatabase("test3")->sort("insertion");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0));
}


TEST(LINKEDLISTSORTDBTest, DatabaseDelete2) {
   manager2->removeDatabase("test");
   manager2->removeDatabase("test2");
   manager2->removeDatabase("test3");
   manager2->removeDatabase("test4");
   manager2->removeDatabase("test5");
}


TEST(HASHTABLESORTDBTest, QuickSortTesting)
{
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++)
   {
      manager2->getDatabase("test")->add("string test_s" + to_string(i) + " " + to_string(i));
   }
   manager2->getDatabase("test")->sort("quick");
   EXPECT_EQ("0", manager2->getDatabase("test")->at(0));
}

TEST(HASHTABLESORTDBTest, QuickSortTestingJSON)
{
   manager2->createDatabase("test3", "array");
   for (int i = 0; i < 10; i++)
   {
      manager2->getDatabase("test3")->add("json test_j" + to_string(i) + " {\"key\":\"" + to_string(i) + "\"}");
   }
   manager2->getDatabase("test3")->sort("quick");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0));
}

// Array selectionsort

TEST(HASHTABLESORTDBTest, SelectionSortTesting) {
   manager2->createDatabase("test4", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test4")->add("string test_s" + to_string(i) + " " + to_string(i));
   }
   manager2->getDatabase("test4")->sort("selection");
   EXPECT_EQ("0", manager2->getDatabase("test4")->at(0));
}

TEST(HASHTABLESORTDBTest, SelectionSortTestingJSON) {
   manager2->createDatabase("test5", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test5")->add("json test_j" + to_string(i) + " {\"key\":\"" + to_string(i) + "\"}");
   }
   manager2->getDatabase("test3")->sort("selection");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test5")->at(0));
}

//BOGO
TEST(HASHTABLESORTDBTest, BogoSortTesting) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 3; i++) {
      manager2->getDatabase("test")->add("string test_s" + to_string(i) + " " + to_string(i));
   }
   manager2->getDatabase("test")->sort("bogo");
   EXPECT_EQ("0", manager2->getDatabase("test")->at(0));
}

TEST(HASHTABLESORTDBTest, BogoSortTestingJSON) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 3; i++) {
      manager2->getDatabase("test3")->add("json test_j" + to_string(i) + " {\"key\":\"" + to_string(i) + "\"}");
   }
   manager2->getDatabase("test3")->sort("bogo");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0));
}
//insetionSort

TEST(HASHTABLESORTDBTest, InsertionSortTesting) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test")->add("string test_s" + to_string(i) + " " + to_string(i));
   }
   manager2->getDatabase("test")->sort("insertion");
   EXPECT_EQ("0", manager2->getDatabase("test")->at(0));
}

TEST(HASHTABLESORTDBTest, InsertionSortTestingJSON) {
   manager2->createDatabase("test", "array");
   for (int i = 0; i < 10; i++) {
      manager2->getDatabase("test3")->add("json test_j" + to_string(i) + " {\"key\":\"" + to_string(i) + "\"}");
   }
   manager2->getDatabase("test3")->sort("insertion");
   EXPECT_EQ("{\"key\":\"0\"}", manager2->getDatabase("test3")->at(0));
}

TEST(LINKEDLISTDBTest, DatabaseDelete) {
   manager2->removeDatabase("test");
   manager2->removeDatabase("test2");
   manager2->removeDatabase("test3");
   manager2->removeDatabase("test4");
   manager2->removeDatabase("test5");
   EXPECT_EQ(0, manager2->size());
}



#endif
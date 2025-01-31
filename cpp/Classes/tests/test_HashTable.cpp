#include <gtest/gtest.h>
#include <iostream>
#include "../HashTable/HashTable.h"

using namespace std;

TEST(HashTableTest, Constructor){
    EXPECT_NO_THROW({
        HashTable* hashtable = new HashTable();
    });
}
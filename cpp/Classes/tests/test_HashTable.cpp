#include <gtest/gtest.h>
#include <iostream>
#include "../HashTable/HashTable.h"

using namespace std;

TEST(HashTableTest, Constructor){
    EXPECT_NO_THROW({
        HashTable* hashtable = new HashTable();
    });
}

TEST(HashTableTest, Hash){
    HashTable* hashTable = new HashTable();
    string key = "key";
    int keyHash = hashTable->hash(key);
    EXPECT_TRUE(keyHash == 0);
}
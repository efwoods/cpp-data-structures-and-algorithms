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

TEST(HashTableTest, Set){
    HashTable* hashTable = new HashTable();
    EXPECT_NO_THROW({
        hashTable->set("nails", 100);
    });
}

TEST(HashTableTest, Get){
    HashTable* hashTable = new HashTable();
    EXPECT_NO_THROW({
        hashTable->set("nails", 100);
        hashTable->set("tile", 50);
        hashTable->set("lumber", 80);

        hashTable->printTable();
    });
}
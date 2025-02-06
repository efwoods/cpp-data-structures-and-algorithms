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

    cout << "key: " << keyHash << endl;

    key = "lumber";
    keyHash = hashTable->hash(key);
    cout << "lumber: " << keyHash << endl;

    key = "bolts";
    keyHash = hashTable->hash(key);
    cout  << "bolts: " << keyHash << endl;


    key = "tile";
    keyHash = hashTable->hash(key);
    cout  << key << ": " << keyHash << endl;
}

TEST(HashTableTest, Set){
    HashTable* hashTable = new HashTable();
    EXPECT_NO_THROW({
        hashTable->set("nails", 100);
    });
    hashTable->printTable();
}

TEST(HashTableTest, Get){
    HashTable* hashTable = new HashTable();
    // EXPECT_NO_THROW({
        hashTable->set("nails", 100);
        hashTable->set("tile", 50);
        hashTable->set("lumber", 80);

        hashTable->printTable();

        cout << "Lumber: " << hashTable->get("lumber") << endl;

        cout << "Bolts: " << hashTable->get("bolts") << endl;
    // });
}

TEST(HashTableTest, LectureExampleTest){
    HashTable* myHashTable = new HashTable();

    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    cout << "Lumber: " << myHashTable->get("lumber") << endl;
    cout << "Bolts: " << myHashTable->get("bolts") << endl;
}

TEST(HashTableTest, Keys){
    HashTable* hashTable = new HashTable();

    hashTable->set("nails", 100);
    hashTable->set("tile", 50);
    hashTable->set("lumber", 80);

    vector<string> allKeys = hashTable->keys();
    EXPECT_TRUE(allKeys[0] == "nails");
    EXPECT_TRUE(allKeys[1] == "tile");
    EXPECT_TRUE(allKeys[2] == "lumber");
}

TEST(HashTableTest, ItemInCommonTest){
    vector<int> vector1 = {1, 2, 3};
    vector<int> vector2 = {4, 5, 2};
    HashTable* hashTable = new HashTable();
    EXPECT_TRUE(hashTable->itemInCommon(vector1, vector2));
}

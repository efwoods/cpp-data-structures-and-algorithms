#!/bin/sh

g++ -std=c++17 -isystem /usr/include/gtest -pthread test_DoublyLinkedList.cpp ../DoublyLinkedList.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -o test_DoublyLinkedList
./test_DoublyLinkedList
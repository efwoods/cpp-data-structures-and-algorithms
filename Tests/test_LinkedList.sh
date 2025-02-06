#!/bin/sh

g++ -std=c++17 -isystem /usr/include/gtest -pthread test_LinkedList.cpp ../LinkedList.cpp /usr/lib/libgtest.a /usr/lib/libgtest_main.a -o test_LinkedList
./test_LinkedList
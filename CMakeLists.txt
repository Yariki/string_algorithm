cmake_minimum_required(VERSION 3.6)
project(string_algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp construct_trie.h construst_trie.cpp trie_mathing.h trie_mathing.cpp bwt.cpp bwt.h kmp.cpp kmp.h)
add_executable(string_algorithm ${SOURCE_FILES})
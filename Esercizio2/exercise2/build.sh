
#! /bin/bash

g++ -O3 -std=c++20 -o main main.cpp \
  zmytest/test.cpp zlasdtest/test.cpp zlasdtest/container/container.cpp \
  zlasdtest/exercise1a/simpletest.cpp zlasdtest/exercise1a/fulltest.cpp \
  zlasdtest/exercise1b/simpletest.cpp zlasdtest/exercise1b/fulltest.cpp \
  zlasdtest/exercise2a/simpletest.cpp zlasdtest/exercise2a/fulltest.cpp \
  zlasdtest/exercise2b/simpletest.cpp zlasdtest/exercise2b/fulltest.cpp

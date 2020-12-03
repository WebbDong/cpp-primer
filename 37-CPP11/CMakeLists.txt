cmake_minimum_required(VERSION 3.15)
project(37_CPP11)

set(CMAKE_CXX_STANDARD 11)

add_executable(37_CPP11 main.cpp AutoTest.cpp AutoTest.h DecltypeTest.cpp DecltypeTest.h model/Person.cpp model/Person.h
        TrailingReturnTypeTest.cpp TrailingReturnTypeTest.h DefinitionByUsingTest.cpp DefinitionByUsingTest.h
        InitializationListTest.cpp InitializationListTest.h LambdaTest.cpp LambdaTest.h UnrestrictedUnionTest.cpp UnrestrictedUnionTest.h ForLoopTest.cpp ForLoopTest.h ConstexprTest.cpp ConstexprTest.h LongLongTest.cpp LongLongTest.h RightValueReferenceTest.cpp RightValueReferenceTest.h NullptrTest.cpp NullptrTest.h)
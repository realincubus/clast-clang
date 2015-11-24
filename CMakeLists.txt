CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(clast-clang)

SET( CMAKE_BUILD_TYPE DEBUG )

#SET( CMAKE_C_COMPILER clang++ )
#SET( CMAKE_CXX_COMPILER clang++ )
SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -fno-exceptions -fno-rtti -fPIC -fvisibility-inlines-hidden -fno-omit-frame-pointer -DCLOOG_INT_GMP=1 -DOSL_SUPPORT " )
SET( CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -pedantic -DGLIBCXX_DEBUG" )
SET( CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS} -std=c++1y" )
SET( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CMAKE_C_FLAGS_DEBUG}" )
SET( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}" )

#SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
#SET( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib )

include_directories( ../../clan/osl/include )

SET( CMAKE_EXPORT_COMPILE_COMMANDS on )

#INCLUDE_DIRECTORIES( )
ADD_LIBRARY( clast-clang_omp SHARED clast_omp.cpp)
ADD_LIBRARY( clast-clang_acc SHARED clast_acc.cpp)



TARGET_LINK_LIBRARIES( clast-clang_omp cloog-isl gmp osl )
TARGET_LINK_LIBRARIES( clast-clang_acc cloog-isl gmp osl )


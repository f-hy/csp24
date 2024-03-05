set(CMAKE_VERSION 3.26)
set(CMAKE_CXX_STANDARD 14)
cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(csp24)
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)# 静态库生成的路径
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)# 测试程序生成的路径
add_subdirectory(test)#
add_subdirectory(dp)#
add_subdirectory(acwing)
add_subdirectory(luogu)
add_subdirectory(leetcode)
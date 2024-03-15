set(CMAKE_VERSION 3.26)
set(CMAKE_CXX_STANDARD 14)
cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(csp24)
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)# 静态库生成的路径
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)# 测试程序生成的路径
add_definitions(-DDEBUG)# 定义DEBUG宏

file(GLOB SUBDIRECTORIES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)# 获取本文件目录下的所有子目录
#如果在${SUBDIRECTORIES}中有子目录名为test或tmp或.*，则将其从${SUBDIRECTORIES}中删除
list(REMOVE_ITEM SUBDIRECTORIES bin build lib .*)
#message(STATUS "SUBDIRECTORIES: ${SUBDIRECTORIES}")
# 遍历子目录查看是否有CMakeLists.txt，若有则添加为子项目
foreach(subdir ${SUBDIRECTORIES})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir})
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt)
            add_subdirectory(${subdir})
        endif()
    endif()
endforeach()
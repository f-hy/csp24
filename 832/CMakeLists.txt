cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(832)#
link_directories(${LIB_PATH})
set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})
#获取本文件目录下所有子目录，将其用add_subdirectory作为子项目添加
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
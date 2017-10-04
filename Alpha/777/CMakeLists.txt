cmake_minimum_required(VERSION 3.6)
project(777)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -stdlib=libc++")

set(SOURCE_FILES
        main.cpp)
add_executable(777 ${SOURCE_FILES})

#------------------------------------------------------------------
#-------------------------------------------------------------------

# add extra include directories
# include_directories(/immagini)
# add extra lib directories
# link_directories(/immagini)

#-------------------------------------------------------------------
#-------------------------------------------------------------------

# find SFML
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(777 ${SFML_LIBRARIES})
endif()

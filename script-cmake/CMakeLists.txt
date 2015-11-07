cmake_minimum_required(VERSION 2.6)

# Include macros HEADER_DIRECTORIES and CreateSourceGroups
#----------------------------------------------------------------------------------------------------------------------
set (CMAKE_UTILS_PATH ../script-cmake/cmake-utils)
set (CMAKE_MODULE_PATH ../script-cmake/cmake-utils)
include(${CMAKE_UTILS_PATH}/macro_HeaderDirectories.cmake)
include(${CMAKE_UTILS_PATH}/macro_CreateSourceGroups.cmake)

set(PROJECT_NAME CppInterview)
project(${PROJECT_NAME})

find_package(GTest REQUIRED)

# Set the include and link directories
#----------------------------------------------------------------------------------------------------------------------
# Add all directories containing at least one .h or .hpp files in include_directories
HEADER_DIRECTORIES(../src header_directories)
include_directories(${header_directories}
                    ${GTEST_INCLUDE_DIRS}
					/usr/local/lib/
					/usr/local/include/)  
                    
# Set compiler and linker flags
#----------------------------------------------------------------------------------------------------------------------
include(${CMAKE_UTILS_PATH}/compilation-flags.cmake) #standard compilation flags
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
	message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
				 
# Create the list of source files to build the library
#----------------------------------------------------------------------------------------------------------------------
# source_files will contains all .cpp and .hpp files
file(GLOB_RECURSE
     source_files
     ../src/*.cpp
     ../src/*.hpp
     ../src/*.tpp) 
     
# source_files_to_remove will contains *UTest*, *example*, main* and files in InterfaceADS and Capture
file(GLOB_RECURSE 
     source_files_to_remove
     ../src/*UTest*
     ../src/*example*
     ../src/main*)
     
# source_files_for_utests will contains all *UTest* files
file(GLOB_RECURSE 
  	source_files_for_utests
	../src/*UTest*) 
    
# Group sources, mimic the directory tree in ../src
CreateSourceGroups(${CMAKE_CURRENT_SOURCE_DIR}/../src "${source_files}")

# Add static library target
#----------------------------------------------------------------------------------------------------------------------
set(LIBRARY_NAME Interview)

# For the library, remove all Utest, example, main files from the sources.
list(REMOVE_ITEM source_files ${source_files_to_remove})
message(${source_files})
add_library( ${LIBRARY_NAME}
             ${source_files})

# Add Test app
#----------------------------------------------------------------------------------------------------------------------
set(APP_DEV_NAME Interview_main)
add_executable(${APP_DEV_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/../src/main_dev.cpp)
target_link_libraries(${APP_DEV_NAME} ${LIBRARY_NAME})

set(UTEST_NAME Interview_Utest) 
add_executable(${UTEST_NAME} 
               ${source_files_for_utests}
               ${CMAKE_CURRENT_SOURCE_DIR}/../src/main_utest.cpp)
target_link_libraries(${UTEST_NAME} ${LIBRARY_NAME}) 
target_link_libraries(${UTEST_NAME} ${GTEST_LIBRARIES}) 


# Install the build applications/library in ../build/bin
#----------------------------------------------------------------------------------------------------------------------
install(TARGETS ${LIBRARY_NAME}
        ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/lib)  

install(TARGETS ${APP_DEV_NAME}
        RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/bin) 		

install(TARGETS ${UTEST_NAME}
        RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/bin)
 
# Install all headers files in ../build/include and keep the folder structure
#----------------------------------------------------------------------------------------------------------------------
install(DIRECTORY ../src/ DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/include
        FILES_MATCHING PATTERN "*.hpp"
        PATTERN "*UTest*" EXCLUDE)        
# Author: M.Emad-ELKHOLY
# CMAKE CONFIGURATION & HEADER #########
cmake_minimum_required(VERSION 3.1)
project(Generic-CMake)
cmake_policy(SET CMP0057 NEW)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
########################################



#   USER CONFIGURATION
#   
#           Y
#           Y
#           Y
#           Y
#           Y
#           Y
#       \   Y   /
#        \  Y  / 
#         \ Y / 
#          \Y/
#           Y

# USER CONFIGURATION SECTION ##############################
###########################################################
# Give your application a name
SET(APP_NAME "Umap_Test")
# Specify the source directory to start the file recursion from
SET(SOURCES_PATH "${CMAKE_SOURCE_DIR}/../../unordered-map")
# To add specific source files to the compilation add them (separated by space) in the below variable
SET(SPECIFIC_SOURCE_FILE "")
# To add specific header directory to the compilation add them (separated by space) in the below variable
SET(SPECIFIC_HEADER_DIRECTORY "")
# To link any library after the compilation add them (separated by space) in the below variable
SET(LINK_LIBS "")
# To execlude whole directory from compilation add them (separated by space) in the below variable
SET(EXECLUDE_DIRS "")
# To execlude source files from compilation add them (separated by space) in the below variable
SET(EXECLUDE_SRC_FILES "feature_tests.c umap.cpp ")
###########################################################





#   CORE LOGIC AND SCRIPT
#   
#           Y
#           Y
#           Y
#           Y
#           Y
#           Y
#       \   Y   /
#        \  Y  / 
#         \ Y / 
#          \Y/
#           Y

######################################################################################################################################################################
####            THE  "DONT TOUCH UNLESS YOU KNOW" SECTION                                                                                                         ####

set(CMAKE_DIR "CompilerIdC CompilerIdCXX")
# Preparing The Variables Start ##################################################
string(STRIP ${SOURCES_PATH} SOURCES_PATH)
string(STRIP ${APP_NAME} APP_NAME)
set(EXECLUDE_DIRS "${EXECLUDE_DIRS} ${CMAKE_DIR}")
if(SPECIFIC_SOURCE_FILE)
    string(REPLACE " " ";" SPECIFIC_SOURCE_FILE  ${SPECIFIC_SOURCE_FILE})
endif()
if(SPECIFIC_HEADER_DIRECTORY)
    string(REPLACE " " ";" SPECIFIC_HEADER_DIRECTORY  ${SPECIFIC_HEADER_DIRECTORY})
endif()
if(EXECLUDE_DIRS)
    string(REPLACE " " ";" EXECLUDE_DIRS  ${EXECLUDE_DIRS})
endif()    
if(EXECLUDE_SRC_FILES)
    string (REPLACE " " ";" EXECLUDE_SRC_FILES ${EXECLUDE_SRC_FILES})
endif()
if(LINK_LIBS)
    string(STRIP ${LINK_LIBS} LINK_LIBS)
endif()
# Preparing The Variables End ####################################################

# Header Include START ############################################################################################################################
FILE(GLOB_RECURSE TMP_ALL_HEADERS ${SOURCES_PATH}/*.h ${SOURCES_PATH}/*.hpp)
SET(header_dir_list "")
FOREACH(file_path ${TMP_ALL_HEADERS})
    GET_FILENAME_COMPONENT(dir_path ${file_path} DIRECTORY)
    GET_FILENAME_COMPONENT(dir_name ${dir_path} NAME)
    SET(EXEC_FLAG 0)
    if(EXECLUDE_DIRS)
        if(${dir_name} IN_LIST EXECLUDE_DIRS)
            SET(EXEC_FLAG 1)
        endif()
    endif()
    if(NOT (${EXEC_FLAG} EQUAL 1))
        SET(ALL_HEADERS ${ALL_HEADERS} ${dir_path})
    endif()
ENDFOREACH()
LIST(REMOVE_DUPLICATES ALL_HEADERS)
include_directories(${ALL_HEADERS} ${SPECIFIC_HEADER_DIRECTORY})
# Header Include END ##############################################################################################################################

# Sources Include START ############################################################################################################################
FILE(GLOB_RECURSE TMP_ALL_SRCS ${SOURCES_PATH}/*.c ${SOURCES_PATH}/*.cpp)
SET(source_files_list "")
FOREACH(file_path ${TMP_ALL_SRCS})
    GET_FILENAME_COMPONENT(dir_path ${file_path} DIRECTORY)
    GET_FILENAME_COMPONENT(dir_name ${dir_path} NAME)
    GET_FILENAME_COMPONENT(file_name ${file_path} NAME)
    SET(EXEC_FLAG 0)
    if(EXECLUDE_DIRS)
        if(${dir_name} IN_LIST EXECLUDE_DIRS)
            SET(EXEC_FLAG 1)
        endif()
    endif()
    if(EXECLUDE_SRC_FILES)
        if(${file_name} IN_LIST EXECLUDE_SRC_FILES)
            SET(EXEC_FLAG 1)
        endif()
    endif()
    if(NOT (${EXEC_FLAG} EQUAL 1))
        SET(ALL_SRCS ${ALL_SRCS} ${file_path})
    endif()
ENDFOREACH()
LIST(REMOVE_DUPLICATES ALL_SRCS)
# Sources Include END ##############################################################################################################################

# Compiling the test
add_executable(${APP_NAME} ${ALL_SRCS} ${SPECIFIC_SOURCE_FILE})

# To link any needed toolchain library dependencies
target_link_libraries(${APP_NAME} ${LINK_LIBS})

## DEBUG 
#message(STATUS "appname= ${APP_NAME} , \n\n\n\n\n\n\n\nHEADERS= ${ALL_HEADERS} , \n\n\n\n\n\n\n\n\n\nSOURCES= ${ALL_SRCS}")


####            END OF  "DONT TOUCH UNLESS YOU KNOW" SECTION                                                                                                      ####
######################################################################################################################################################################


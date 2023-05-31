# set minimum cmake version
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# project name and language
project(CrossPlatformLib LANGUAGES CXX)

#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_definitions(-DCROSS_PLATFORM_LIBRARY_EXPORTS)

#配置编译后的输出路径
 # 设定动态链接库的存储路径
SET(LIBRARY_OUTPUT_PATH  ${CMAKE_CURRENT_LIST_DIR}/Bin64)

aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/Src SrcPath)

# generate a library from sources
add_library(${PROJECT_NAME}
  SHARED
  ${SrcPath}
)

set(IncludePath 
      ./Include
      ./Interface
)

IF(WIN32)
set(ThirdPath ../ThirdLibWin/libxl/inc)
ELSE()
set(ThirdPath ../ThirdLibLinux/libxl/include_cpp)

add_library(libxl
  SHARED
  IMPORTED
)
set_target_properties(libxl PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../ThirdLibLinux/libxl/lib64/libxl.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../ThirdLibLinux/libxl/include_cpp"
)
ENDIF()

set(AllIncludePath ${IncludePath} ${ThirdPath})
      
target_include_directories(${PROJECT_NAME} PUBLIC ${AllIncludePath})

IF(WIN32)

ELSE()
target_link_libraries(${PROJECT_NAME} libxl)
ENDIF()
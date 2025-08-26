cmake_minimum_required( VERSION 3.19 )

set( library_name Template-Project )

project( ${library_name} CXX )

set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

file( GLOB SRC_FILES
  ${PROJECT_SOURCE_DIR}/src/*.cpp
  ${PROJECT_SOURCE_DIR}/src/*.h
)

link_directories( ${PROJECT_SOURCE_DIR}/lib )

add_executable( ${library_name} ${SRC_FILES} )

set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${library_name} )

if( UNIX AND NOT APPLE )
  set( LINK_LIBS
  #
  )
elseif( APPLE )
  set( LINK_LIBS
  #
  )
elseif( WIN32 )
  set( LINK_LIBS
  #
  )
endif()

target_link_libraries( ${library_name} PRIVATE ${LINK_LIBS} )

target_include_directories( ${library_name} PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/include )

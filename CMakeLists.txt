cmake_minimum_required( VERSION 3.19 )

set( library_name Template-Project )

project( ${library_name} CXX )

set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

if( MSVC )
	add_compile_options(
    $<$<CONFIG:>:/MT> #---------|
    $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
    $<$<CONFIG:Release>:/MT> #--|
  )
endif()

file( GLOB SRC_FILES
  ${PROJECT_SOURCE_DIR}/src/*.cpp
  ${PROJECT_SOURCE_DIR}/src/*.h
  ${PROJECT_SOURCE_DIR}/src/internal/widevine/*.h
  ${PROJECT_SOURCE_DIR}/src/internal/widevine/*.cc
)

link_directories( ${PROJECT_SOURCE_DIR}/lib )

add_executable( ${library_name} ${SRC_FILES} )

set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${library_name} )

if( UNIX AND NOT APPLE )
  set( LINK_LIBS
  # libavcodec.so libavdevice.so libavfilter.so libavformat.so libavutil.so libpostproc.so libswresample.so libswscale.so
  )
elseif( APPLE )
  set( LINK_LIBS
  # libavcodec.dylib libavdevice.dylib libavfilter.dylib libavformat.dylib libavutil.dylib libpostproc.dylib libswresample.dylib libswscale.dylib
  )
elseif( WIN32 )
  set( LINK_LIBS
  libavcodec libavformat libavutil libswresample
  libprotobuf.lib
  botan.lib
  # Ws2_32.lib Crypt32.lib Wldap32.lib Normaliz.lib
  )
endif()

target_link_libraries( ${library_name} PRIVATE ${LINK_LIBS} ) # Qt5::Core Qt5::Gui Qt5::Network Qt5::Widgets

target_include_directories( ${library_name} PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/include )

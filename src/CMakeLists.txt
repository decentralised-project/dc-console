
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/build/bin")

SET( CORE_INC_DIR "${CMAKE_SOURCE_DIR}/dependencies/dc-core/src" )

include_directories ( ${CORE_INC_DIR} )
link_directories( "${CMAKE_SOURCE_DIR}/build/dependencies/dc-core/src/Debug" )

set  (MAIN_SOURCES      
      "main.cpp")

source_group( "" FILES ${MAIN_SOURCES} )

add_executable (dcConsole ${MAIN_SOURCES} )
target_link_libraries ( dcConsole dcCore )

IF( WIN32 )
	ADD_DEFINITIONS( -DDC_WINDOWS )
ENDIF(  )

if( UNIX )
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
ENDIF(  )

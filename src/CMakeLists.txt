
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/build/bin")

set  (MAIN_SOURCES      
      "main.cpp")

source_group( "" FILES ${MAIN_SOURCES} )

add_executable (dcConsole ${MAIN_SOURCES} )
target_link_libraries ( dcConsole )

IF( WIN32 )
	ADD_DEFINITIONS( -DDC_WINDOWS )
ENDIF(  )
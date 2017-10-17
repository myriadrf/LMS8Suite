set(lms8suiteEvents_src_files	
	lms8suiteEvents.cpp
)

add_library(lms8suiteEvents STATIC ${lms8suiteEvents_src_files})
target_include_directories(lms8suiteEvents PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

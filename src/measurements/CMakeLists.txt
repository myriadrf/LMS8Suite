set(lime_E4440A_src_files	
	lime_E4440A.cpp
	gpiblib.cpp
)

set(LMS7002M_parameters_src_files	
	LMS7002M_parameters.cpp
)

add_library(measurements
	${lime_E4440A_src_files} 
	${LMS7002M_parameters_src_files} 
	gpib-32.obj
	)
	
target_link_libraries(measurements LMS8001)
target_include_directories(measurements PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

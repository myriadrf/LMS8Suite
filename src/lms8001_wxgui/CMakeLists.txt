set(lms8001_gui_src_files	
	lms8001_wxgui.cpp
	lms8001_mainPanel.cpp
	lms8001_pnlConfig_view.cpp
	lms8001_pnlLDO_view.cpp
	lms8001_pnlChannel_view.cpp
	lms8001_pnlHLMIX_view.cpp
	lms8001_pnlPLLConfig_view.cpp
	lms8001_pnlPLLProfiles_view.cpp	
	lms8001_gui_utilities.cpp
)
add_library(lms8001_wxgui STATIC ${lms8001_gui_src_files})
target_include_directories(lms8001_wxgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lms8001_wxgui LMS8001 lms8suiteEvents utilities_gui)

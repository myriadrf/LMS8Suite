set(connectionManager_gui_src_files	
	dlgConnectionSettings.cpp
)

set(spi_gui_src_files	
	SPI_wxgui.cpp
)

set(deviceinfo_gui_src_files	
	dlgDeviceInfo.cpp
)

set(messageLog_gui_src_files	
	pnlMiniLog.cpp
	dlgFullMessageLog.cpp
)

set(gpio_gui_src_files	
	GPIO_wxgui.cpp
)

set(tempcalibrate_gui_src_files	
	dlgTempCalibrate.cpp
)

set(connectionManagerLMS7_gui_src_files	
	dlgConnectionSettingsLMS7.cpp
)

add_library(utilities_gui STATIC utilities_gui.cpp 
	${connectionManager_gui_src_files} 
	${spi_gui_src_files}
	${messageLog_gui_src_files}	
	${deviceinfo_gui_src_files}	
	${gpio_gui_src_files}
	${tempcalibrate_gui_src_files}
	${measurements_gui_src_files}
	${connectionManagerLMS7_gui_src_files} 
	)
target_link_libraries(utilities_gui lms8suiteEvents LMS8001)
target_include_directories(utilities_gui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

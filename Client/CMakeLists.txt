cmake_minimum_required(VERSION 2.6)
project(client)

file(GLOB SOURCES
	main.cpp
	general.h
	mywindow.cpp
	mywindow.h
	guipad.cpp
	guipad.h
	orientationwidget.cpp
	orientationwidget.h
	radarwidget.cpp
	radarwidget.h
	widget/arc.cpp
	widget/arc.h
	widget/arrow.cpp
	widget/arrow.h
	widget/colormanager.cpp
	widget/colormanager.h
	widget/filledarc.cpp
	widget/filledarc.h
	widget/quad.cpp
	widget/quad.h
)

set (CMAKE_CXX_STANDARD 11)


add_executable(client ${SOURCES})

install(TARGETS client RUNTIME DESTINATION bin)

if(WIN32)
	set(SFML_STATIC_LIBRARIES TRUE)
	find_package(SFML 2 COMPONENTS graphics window system)
	target_link_libraries(client sfml-graphics-s)

else()
	find_package(SFML 2 COMPONENTS graphics window system)
	target_link_libraries(client sfml-graphics)
	target_link_libraries(client X11)
endif()


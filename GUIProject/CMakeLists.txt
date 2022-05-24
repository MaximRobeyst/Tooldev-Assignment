set( QtBaseDir "C:/Program Files (x86)/qt6")
LIST (APPEND CMAKE_PREFIX_PATH "${QtBaseDir}/lib/cmake/")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Widgets)
qt_add_executable(GUIProject 
	objForm.cpp objForm.h objForm.ui
	main.cpp
)
set_target_properties(GUIProject PROPERTIES 
	WIN32_EXECUTABLE TRUE
	MACOSX_BUNDLE TRUE
)

target_include_directories(GUIProject PUBLIC ${CommonCodeProjectIncDir})
target_link_libraries(GUIProject PUBLIC CommonCodeProject)

target_link_libraries(
	GUIProject PUBLIC
	Qt::Core
	Qt::Gui
	Qt::Widgets
)



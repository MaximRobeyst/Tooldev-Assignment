# root directory
cmake_minimum_required(VERSION 3.22)
project(Assignment)

add_subdirectory(CommonCodeProject)
add_subdirectory(CommandLineProject)
add_subdirectory(GUIProject)
add_subdirectory(UnitTests)
add_dependencies(CommandLineProject UnitTestsRun)
add_dependencies(GUIProject UnitTestsRun)
	
message(STATUS "include directory: ${PROJECT_SOURCE_DIR}")
install(TARGETS GUIProject DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_NSIS_MODIFY_PATH ON)
include(CPack)

# root directory
cmake_minimum_required(VERSION 3.22)
project(Assignment)

add_subdirectory(CommonCodeProject)
add_subdirectory(CommandLineProject)
add_subdirectory(GUIProject)
add_subdirectory(UnitTests)
add_dependencies(CommandLineProject UnitTestsRun)
add_dependencies(GUIProject UnitTestsRun)
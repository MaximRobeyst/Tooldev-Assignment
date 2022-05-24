add_library(CommonCodeProject Conversion.cpp Conversion.h)
add_subdirectory(rapidjson)
set(CommonCodeProjectIncDir ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
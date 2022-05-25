#UnitTests directory
Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)
FetchContent_MakeAvailable(Catch2)
add_executable(UnitTests UnitTestsMain.cpp )
target_link_libraries(UnitTests PRIVATE CommonCodeProject Catch2::Catch2WithMain)
add_custom_target(UnitTestsRun
  COMMAND UnitTests -d yes
  COMMENT "running tests"
)
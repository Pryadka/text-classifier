cmake_minimum_required(VERSION 3.15)
project(text-classifier VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

add_subdirectory(src)
add_subdirectory(tst)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/075810f7a20405ea09a93f68847d6e963212fa62.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

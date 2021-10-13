set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB SOURCES *.h *.cpp)

set(SOURCES ${SOURCES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(${BINARY} ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB SOURCES *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY} ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})
set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB TEST_SOURCES *.cpp)

set(SOURCES ${TEST_SOURCES})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(${BINARY} ${SOURCES})
target_include_directories(${BINARY} PUBLIC ${PROJECT_SOURCE_DIR}/src)

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

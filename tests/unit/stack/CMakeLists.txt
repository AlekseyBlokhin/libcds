set(PACKAGE_NAME cdsu-stack)

set(CDSUNIT_STACK_SOURCES
    stack_push.cpp
    stack_pushpop.cpp
    stack_intrusive_pushpop.cpp)

add_executable(${PACKAGE_NAME} ${CDSUNIT_STACK_SOURCES} $<TARGET_OBJECTS:${TEST_COMMON}>)
target_link_libraries(${PACKAGE_NAME} ${CDS_SHARED_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME ${PACKAGE_NAME} COMMAND ${PACKAGE_NAME} WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
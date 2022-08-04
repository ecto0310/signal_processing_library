cmake_minimum_required(VERSION 3.8)
project(signal_processing_library)

file(GLOB_RECURSE SOURCE_LIST LIST_DIRECTORIES false CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.c)
add_library(signal_processing SHARED ${SOURCE_LIST})


if(DEVELOP)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)


    file(GLOB_RECURSE TEST_SOURCE_LIST LIST_DIRECTORIES false CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/test/*.cpp)
    add_executable(
        signal_processing_test
        ${TEST_SOURCE_LIST}
    )
    set_property(TARGET signal_processing_test PROPERTY CXX_STANDARD 17)
    target_include_directories(signal_processing_test PUBLIC ${PROJECT_SOURCE_DIR}/include)
    target_link_libraries(
        signal_processing_test
        signal_processing
        GTest::gtest_main
        GTest::gtest
    )


    enable_testing()

    include(GoogleTest)
    gtest_discover_tests(signal_processing_test)
endif()

install(TARGETS signal_processing LIBRARY DESTINATION lib)
file(GLOB_RECURSE INCLUDE_LIST LIST_DIRECTORIES false CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/include/signal_processing/*.h)
install(FILES "${INCLUDE_LIST}" DESTINATION include/signal_processing)

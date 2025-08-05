include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(storycore-tests main_tests.cpp)

target_link_libraries(
    storycore-tests
    GTest::gtest_main
    GTest::gmock_main
)

target_include_directories(
    storycore-tests
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

include(GoogleTest)

gtest_discover_tests(storycore-tests)

include(CTest)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        52eb8108c5bdec04579160ae17225d66034bd723 # release-1.17.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable (test_core "${CMAKE_CURRENT_SOURCE_DIR}/test_core.cpp")
target_link_libraries (test_core GTest::gtest_main game_core)

include(GoogleTest)
gtest_discover_tests(test_core)

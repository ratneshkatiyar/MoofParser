cmake_minimum_required(VERSION 3.10)
project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG master
    SOURCE_DIR "/home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-src"
    BINARY_DIR "/home/rkatiyar/Project/2020/backup/20-04-21/final/MoofParser/build/googletest-build"
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    TEST_COMMAND ""
)

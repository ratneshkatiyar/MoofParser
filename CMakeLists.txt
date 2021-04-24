cmake_minimum_required(VERSION 3.10)

project(moofparser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build"
)

# The gtest/gmock targets carry header search path dependencies
# automatically when using CMake 2.8.11 or later. Otherwise we
# have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include"
    )
endif()

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate
include_directories(build/googletest-src/googlemock/include)
include_directories(build/googletest-src/googletest/include)


#sudo apt-get install libcurl4-openssl-dev
#sudo apt-get install pkg-config

include(FindPkgConfig)
pkg_check_modules(CURL libcurl REQUIRED)
#pkg_check_modules(RAPID rapidxml REQUIRED)

include_directories(
  SYSTEM ${CURL_INCLUDE_DIRS}
)
#sudo apt install librapidxml-dev -y
add_library(rapidxml INTERFACE)
target_include_directories(rapidxml INTERFACE rapidxml/ )

add_executable(moofparser
                src/main.cpp
                src/boxes.cpp
                src/mediaDataBox.cpp
                )

target_include_directories(moofparser PRIVATE inc)

#find_package(CryptoPP REQUIRED)
#add_subdirectory(test)
#sudo apt-get install libcrypto++-dev libcrypto++-doc libcrypto++-utils
target_link_libraries(moofparser
                        PUBLIC
                         ${CURL_LIBRARIES}
                         rapidxml
                         cryptopp                         
                         gtest_main
                         gtest)




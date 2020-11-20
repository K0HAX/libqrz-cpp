cmake_minimum_required(VERSION 3.17)
# set the project name and version
project(CallLookup VERSION 1.0)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

include(InstallRequiredSystemLibraries)
include(CPack)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

include(FetchContent)
# CPR::CPR
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG 41fbaca90160950f1397e0ffc6b58bd81063f131) # the commit hash for 1.5.2
set(BUILD_CPR_TESTS OFF)
set(SKIP_TESTS TRUE)
set(USE_SYSTEM_CURL ON)
##set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
#set(BUILD_SHARED_LIBS OFF)
##set(CMAKE_EXE_LINKER_FLAGS "-static")
#set(OPENSSL_USE_STATIC_LIBS TRUE)
#set(CURL_STATICLIB ON)
FetchContent_MakeAvailable(cpr)
# End CPR::CPR

# tinyxml2
FetchContent_Declare(tinyxml2 GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git GIT_TAG bf15233ad88390461f6ab0dbcf046cce643c5fcb) # the commit has for 8.0.0
set(BUILD_TESTS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
FetchContent_MakeAvailable(tinyxml2)
# End tinyxml2

set(SOURCES CallLookup.cpp qrz_utils.cpp credentials.cpp callsign.cpp include/qrz_utils.h include/callsign.h include/credentials.h)
add_executable(CallLookup ${SOURCES})
target_link_libraries(CallLookup cpr::cpr)
target_link_libraries(CallLookup tinyxml2)

#set(CPACK_PACKAGE_VERSION_MAJOR "${CallLookup_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${CallLookup_VERSION_MINOR}")

install(TARGETS CallLookup EXPORT CallLookupTargets
  RUNTIME DESTINATION bin
)

target_include_directories(CallLookup PRIVATE "includes/")
#target_include_directories(CallLookup PUBLIC
#  "${PROJECT_BINARY_DIR}"
#  )

cmake_minimum_required(VERSION 3.13)
project(algorithm VERSION 0.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SRC_FILES src/*.c)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME}
PUBLIC "${PROJECT_SOURCE_DIR}/include"
)

if(APPLE)
  set(CPACK_GENERATOR "DragNDrop")
  set(CPACK_PACKAGE_INSTALL_DIRECTORY "/Applications/")
elseif(UNIX AND NOT APPLE)
  set(CPACK_GENERATOR "DEB")
  set(CPACK_PACKAGE_CONTACT "kinwlsgh33@gmail.com")
endif()

# Specify the fies to be included in the package
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION .)
install(FILES README.md DESTINATION .)

# Include CPack module to enable packaging
include(CPack)

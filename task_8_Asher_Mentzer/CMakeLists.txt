# CMakeList.txt : CMake project for task_8_Asher_Mentzer, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (task_8_Asher_Mentzer "task_8_Asher_Mentzer.cpp" "task_8_Asher_Mentzer.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET task_8_Asher_Mentzer PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

cmake_minimum_required(VERSION 3.25)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(cpp_novice_fetch_project_options)
run_conan()

project(cpp_novice LANGUAGES CXX)

include(cpp_novice_custom_project_options)
include(add_code)

# -----------------------------------------------------------------------------------------------------------------------
add_code_options(
  DEPENDENCIES
  fmt
  range-v3

  LIBRARIES
  fmt::fmt
  range-v3::range-v3

  INCLUDES
  include
)

# ------------------------------------------------------------------------------------------------------------------------
add_code(test
  test/main.cpp
)
add_code(example_single
  src/example_single/main.cpp
)
add_code(example_multiple
  src/example_multiple/main.cpp
  src/example_multiple/hello.cpp
)
add_code(Score
  test/Score.cpp
)
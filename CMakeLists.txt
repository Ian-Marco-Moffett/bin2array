project(BinToCArray C)
cmake_minimum_required(VERSION 3.0)

file (GLOB_RECURSE CFILES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")


set (CMAKE_C_FLAGS "-Werror=implicit -Werror=implicit-function-declaration -Werror=implicit-int \
-Werror=int-conversion \
-Werror=incompatible-pointer-types -Werror=int-to-pointer-cast")

add_executable(out ${CFILES})
set_target_properties(out PROPERTIES OUTPUT_NAME "${PROJECT_SOURCE_DIR}/bin2array")

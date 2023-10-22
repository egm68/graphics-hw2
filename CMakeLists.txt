cmake_minimum_required (VERSION 3.1.0)
project(assignment2)
set (CMAKE_CXX_STANDARD 11)

# Source
set ( COMMON_ALL
  #src/common/rtweekend.h
  src/common/camera.h
  src/common/ray.h
  src/common/vec3.h
)

set ( SOURCE_ONE_WEEKEND
  ${COMMON_ALL}
  src/InOneWeekend/hittable.h
  src/InOneWeekend/hittable_list.h
  src/InOneWeekend/material.h
  src/InOneWeekend/sphere.h
  src/InOneWeekend/main.cc
)

add_executable(inOneWeekend      ${SOURCE_ONE_WEEKEND})

include_directories(src/common)
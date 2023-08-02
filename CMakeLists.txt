 cmake_minimum_required(VERSION 3.5)
  project(Nomoto_v2.0)
  find_package(yaml-cpp)
  
  add_executable(main Nomo_sim.cpp main.cpp)

  include_directories(${CMAKE_SOURCE_DIR}/yaml-cpp/include)
  
  target_link_libraries(main yaml-cpp) 
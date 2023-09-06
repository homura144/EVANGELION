cmake_minimum_required(VERSION 3.26)
project(EVANGELION)

set(EasyX_DIR ./lib/EasyX)

include_directories(include ${EasyX_DIR}/include)

link_directories(${EasyX_DIR}/lib/VC2015/x64)

aux_source_directory(src DIR_SRCS)

add_executable(EVANGELION ${DIR_SRCS})

target_link_libraries(EVANGELION EasyXa EasyXw)
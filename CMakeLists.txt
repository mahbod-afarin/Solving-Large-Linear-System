cmake_minimum_required(VERSION 2.8)

project (cs211-lab2)


add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)

include_directories(/act/opt/intel/mkl/include)
link_directories(/act/opt/intel/mkl/lib/intel64)
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath=/act/opt/intel/mkl/lib/intel64")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -W -DMKL_ILP64 -lmkl_avx2 -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread -lm -ldl -m64")
add_executable(verify example/main_verification.c)


target_link_libraries(verify IncludeFuncs SrcFuncs TestFuncs)


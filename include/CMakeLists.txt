file(GLOB headers *.h)

add_library(IncludeFuncs INTERFACE)

include_directories(/act/opt/intel/mkl/include)
link_directories(/act/opt/intel/mkl/lib/intel64)
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath=/act/opt/intel/mkl/lib/intel64")

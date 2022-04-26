aux_source_directory(. DIR_LIB_SRCS)

add_library(TestFuncs ${DIR_LIB_SRCS})

include_directories(/act/opt/intel/mkl/include)
link_directories(/act/opt/intel/mkl/lib/intel64)
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath=/act/opt/intel/mkl/lib/intel64")

target_link_libraries(TestFuncs IncludeFuncs SrcFuncs)

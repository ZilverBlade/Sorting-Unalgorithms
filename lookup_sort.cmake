set(SH_SRC "${CMAKE_SOURCE_DIR}/src/lookup_sort")
file(GLOB_RECURSE ENDF6_SRC
      "${SH_SRC}/*.h"
      "${SH_SRC}/*.cpp")
      
add_executable("lookup_sort" ${ENDF6_SRC})

foreach(_source IN ITEMS ${ENDF6_SRC})
    get_filename_component(_source_path "${_source}" PATH)
    string(REPLACE "${SH_SRC}" "" _group_path "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_group_path}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()

set_target_properties("lookup_sort" PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
  POSITION_INDEPENDENT_CODE False
  INTERPROCEDURAL_OPTIMIZATION False
)

if (WIN32)
set_property(TARGET "lookup_sort" 
PROPERTY MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug> #no DLL because of simdjson
)
endif(WIN32)

set_target_properties("lookup_sort" PROPERTIES
  OUTPUT_NAME "lookup_sort"
  ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH}
  LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
  RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

target_include_directories("lookup_sort" PRIVATE
  vendor/zstd/lib
)

add_subdirectory("vendor/zstd/build/cmake")
target_link_libraries(lookup_sort PUBLIC 
  libzstd
)

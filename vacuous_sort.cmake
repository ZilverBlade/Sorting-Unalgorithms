set(SH_SRC "${CMAKE_SOURCE_DIR}/src/vacuous_sort")
file(GLOB_RECURSE ENDF6_SRC
      "${SH_SRC}/*.h"
      "${SH_SRC}/*.cpp")
      
add_executable("vacuous_sort" ${ENDF6_SRC})

foreach(_source IN ITEMS ${ENDF6_SRC})
    get_filename_component(_source_path "${_source}" PATH)
    string(REPLACE "${SH_SRC}" "" _group_path "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_group_path}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()

set_target_properties("vacuous_sort" PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
  POSITION_INDEPENDENT_CODE False
  INTERPROCEDURAL_OPTIMIZATION False
)
target_include_directories("vacuous_sort" PRIVATE 
  ${CMAKE_SOURCE_DIR}/src
)
if (WIN32)
set_property(TARGET "vacuous_sort" 
PROPERTY MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>DLL
)
endif(WIN32)

set_target_properties("vacuous_sort" PROPERTIES
  OUTPUT_NAME "vacuous_sort"
  ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH}
  LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
  RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

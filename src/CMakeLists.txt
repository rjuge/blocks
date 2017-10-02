
file(GLOB headers   blk*.hpp)
file(GLOB lib_files blk*.cpp)

add_library(blk SHARED ${lib_files})

target_include_directories(blk PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options    (blk PUBLIC -std=c++11                 )

install(TARGETS blk        DESTINATION lib                          )
install(FILES   ${headers} DESTINATION include/${CMAKE_PROJECT_NAME})

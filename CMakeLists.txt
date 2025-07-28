# Add spdlog as a subdirectory
set(CMAKE_FOLDER "External")
add_subdirectory(vendor/spdlog EXCLUDE_FROM_ALL)

# Define a static library named 'engine'
add_library(Earl STATIC
    src/earl.cpp          # Add all your engine source files here
    src/Earl/entryPoint.cpp
    src/Earl/application.cpp
    src/Earl/log.cpp
)

target_compile_definitions(Earl PRIVATE $<$<CONFIG:Debug>:EARL_DEBUG>)

# Make the headers in 'include/' visible to anything that links this library
target_include_directories(Earl PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Optional: help organize the built artifacts
set_target_properties(Earl PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

target_link_libraries(Earl PUBLIC spdlog::spdlog_header_only)

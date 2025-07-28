# Define a static library named 'engine'
add_library(Earl STATIC
    src/earl.cpp          # Add all your engine source files here
    src/Earl/entryPoint.cpp
    src/Earl/application.cpp
)

# Make the headers in 'include/' visible to anything that links this library
target_include_directories(Earl PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Optional: help organize the built artifacts
set_target_properties(Earl PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

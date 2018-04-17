
project(kolokula)

set(HEDEAR_FILES KoloKula.h)
set(SOURCE_FILES KoloKula.cpp)

add_library(libkolokula STATIC ${SOURCE_FILES})
target_include_directories(libkolokula PUBLIC .)

add_executable(kolokula ${SOURCE_FILES} main.cpp)

target_link_libraries(kolokula libkolokula)



project(liczba)

set(HEDEAR_FILES Liczba.h)
set(SOURCE_FILES Liczba.cpp)

add_library(libliczba STATIC ${SOURCE_FILES})
target_include_directories(libliczba PUBLIC .)

add_executable(liczba ${SOURCE_FILES} main.cpp)

target_link_libraries(liczba libliczba)


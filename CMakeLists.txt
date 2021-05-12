# требуем минимальную версию cmake
cmake_minimum_required(VERSION 3.9.3)

# устанавливаем имя проекта
project(mydynamic_library CXX)

# устанавливаем директории в которые будут собираться библиотеки и исполняемые файлы
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dll)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# устанавливаем дополнительные флаги компиляции для visual studio
if(MSVC)
    add_compile_options(
        $<$<CONFIG:>:/MT>
        $<$<CONFIG:Debug>:/MTd>
        $<$<CONFIG:Release>:/MT>
    )
endif()

# устанавливаем стандарт c++
set(CMAKE_CXX_STANDARD 14)

# органезуем таргеты по директорям
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


add_subdirectory(mydll)
add_subdirectory(gtest)

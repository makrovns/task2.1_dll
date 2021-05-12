# задаем набор исходников
set(SOURCES_DLL
sin_library.h
sin_library.cpp
)

# создаем статическую библиотеку
add_library(mysin_dyn SHARED ${SOURCES_DLL})

# добавлем путь к исходникам для возожности подключения библиотеки
target_include_directories(mysin_dyn PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# группируем исходники по типу по категориям
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCES_DLL})

# В solution эта библиотека лежит в simple_project
set_property(TARGET mysin_dyn PROPERTY FOLDER "sin_dll")


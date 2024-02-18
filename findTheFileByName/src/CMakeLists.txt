# Список исходных файлов в вашем проекте
set(SOURCES
    findTheName.cpp
    findTheName.hpp
    main.cpp
    ThreadPool.cpp
    ThreadPool.hpp
)

# Добавьте исполняемый файл
add_executable(YourExecutable ${SOURCES})

# Добавьте библиотеки
find_package(Threads REQUIRED)
target_compile_features(YourExecutable PRIVATE cxx_std_17)
# target_link_libraries(YourExecutable PRIVATE std::filesystem)

target_link_libraries(YourExecutable
    PRIVATE
    Threads::Threads
)
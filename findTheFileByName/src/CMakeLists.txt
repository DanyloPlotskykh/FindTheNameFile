
set(SOURCES
    findTheName.cpp
    findTheName.hpp
    main.cpp
    ThreadPool.cpp
    ThreadPool.hpp
)


add_executable(YourExecutable ${SOURCES})


find_package(Threads REQUIRED)
target_compile_features(YourExecutable PRIVATE cxx_std_17)
# target_link_libraries(YourExecutable PRIVATE std::filesystem)

target_link_libraries(YourExecutable
    PRIVATE
    Threads::Threads
)

cmake_minimum_required(VERSION 2.8.12) # first version with add_compile_options()
project(SQLiteCpp_Example)

# add SQLite3 C++ wrapper arround sqlite3 library (and sqlite3 itself provided for ease of use)
include_directories(SQLiteCpp/include)
add_subdirectory(SQLiteCpp)

# add main.cpp example source code
set(SOURCE_FILES src/main.cpp)
add_executable(SQLiteCpp_Example ${SOURCE_FILES})

# Link SQLiteCpp_example1 with SQLiteCpp and sqlite3 (and also pthread and dl for linux)
if(UNIX AND NOT APPLE)
   # Linux
   target_link_libraries(SQLiteCpp_Example SQLiteCpp sqlite3 pthread dl)
else(UNIX AND APPLE)
   # Mac OS
   target_link_libraries(SQLiteCpp_Example SQLiteCpp sqlite3 pthread)
else()
   # Windows
   target_link_libraries(SQLiteCpp_Example SQLiteCpp sqlite3)
endif()

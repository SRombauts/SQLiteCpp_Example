cmake_minimum_required(VERSION 2.8.12) # first version with add_compile_options()
project(SQLiteCpp_Example)

# add SQLite3 C++ wrapper arround sqlite3 library (and sqlite3 itself provided for ease of use)
# NOTE: here you can set CMake variables to avoid building Example, as well as cpplint, cppcheck...
# NOTE: or set them in the cmake commande line (see for instance provided build.bat/build.sh scripts)
set(SQLITECPP_RUN_CPPCHECK OFF CACHE BOOL "" FORCE)
set(SQLITECPP_RUN_CPPLINT OFF CACHE BOOL "" FORCE)

add_subdirectory(SQLiteCpp)

# add main.cpp example source code
set(SOURCE_FILES src/main.cpp)
add_executable(SQLiteCpp_Example ${SOURCE_FILES})

# Link SQLiteCpp_example1 with SQLiteCpp and sqlite3 (and also pthread and dl for linux)
if(UNIX AND NOT APPLE)
   # Linux
   target_link_libraries(SQLiteCpp_Example SQLiteCpp sqlite3 pthread dl)
elseif(UNIX AND APPLE)
   # Mac OS
   target_link_libraries(SQLiteCpp_Example SQLiteCpp sqlite3 pthread)
else()
   # Windows
   target_link_libraries(SQLiteCpp_Example SQLiteCpp sqlite3)
endif()

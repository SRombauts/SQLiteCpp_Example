cmake_minimum_required(VERSION 2.8.12) # first version with add_compile_options()
project(SQLiteCpp_Example)

# add SQLite3 C++ wrapper arround sqlite3 library (and sqlite3 itself provided for ease of use)
# NOTE: here you can set CMake variables to avoid building Example, as well as cpplint, cppcheck...
# NOTE: or set them in the cmake commande line (see for instance provided build.bat/build.sh scripts)
set(SQLITECPP_RUN_CPPCHECK OFF CACHE BOOL "" FORCE)
set(SQLITECPP_RUN_CPPLINT OFF CACHE BOOL "" FORCE)

add_subdirectory(SQLiteCpp)

# add main.cpp example source code
set(MAIN_TARGET_NAME SQLiteCpp_Example)
add_executable(SQLiteCpp_Example src/main.cpp)

if(UNIX AND NOT APPLE)
  # Linux
  # Removed linking to pthread, more detail:
  # https://github.com/tstack/lnav/issues/153
  # https://stackoverflow.com/questions/33697072/why-is-pthread-necessary-for-usage-of-stdthread-in-gcc-and-clang
  target_link_libraries(${MAIN_TARGET_NAME} SQLiteCpp sqlite3 dl)
else()
  target_link_libraries(${MAIN_TARGET_NAME} SQLiteCpp sqlite3)
endif()


set(MODULE_CORE core)
set(UTIL util)
set(COMMANDS commands)

set(SOURCES 
    ${MODULE_CORE}/accounts.cpp ${MODULE_CORE}/accounts.h
    ${MODULE_CORE}/PandaDB.cpp ${MODULE_CORE}/PandaDB.h
    ${MODULE_CORE}/server.cpp ${MODULE_CORE}/server.h
    ${MODULE_CORE}/Logger.cpp ${MODULE_CORE}/Logger.h
    ${MODULE_CORE}/Application.h ${MODULE_CORE}/Application.cpp

    ${UTIL}/util.h ${UTIL}/util.cpp

    ${COMMANDS}/Command.h ${COMMANDS}/Command.cpp
)


add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

target_precompile_headers(${PROJECT_NAME} PRIVATE header.hpp)
target_include_directories(${PROJECT_NAME} PRIVATE
    ./
    src
)

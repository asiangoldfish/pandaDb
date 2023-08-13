
set(MODULE_CORE core)
set(UTIL util)
set(COMMANDS commands)

set(SOURCES
    main.cpp
    config.hpp

    ${COMMANDS}/cmd_header.h
    ${COMMANDS}/Command.h
    ${COMMANDS}/SelectFile.h        ${COMMANDS}/SelectFile.cpp
    ${COMMANDS}/CreateFile.h        ${COMMANDS}/CreateFile.cpp
    ${COMMANDS}/ShowFiles.h         ${COMMANDS}/ShowFiles.cpp
    ${COMMANDS}/ShowData.h          ${COMMANDS}/ShowData.cpp
    ${COMMANDS}/DeleteFile.h        ${COMMANDS}/DeleteFile.cpp
    ${COMMANDS}/CreateEntry.h       ${COMMANDS}/CreateEntry.cpp
    ${COMMANDS}/Help.h              ${COMMANDS}/Help.cpp
    
    ${MODULE_CORE}/PandaDB.cpp      ${MODULE_CORE}/PandaDB.h
    ${MODULE_CORE}/Logger.cpp       ${MODULE_CORE}/Logger.h
    ${MODULE_CORE}/Application.h    ${MODULE_CORE}/Application.cpp

    ${UTIL}/util.h                  ${UTIL}/util.cpp
)


add_executable(${PROJECT_NAME} ${SOURCES})

target_precompile_headers(${PROJECT_NAME} PRIVATE header.hpp)

target_include_directories(${PROJECT_NAME} PRIVATE
    ./
    src
)

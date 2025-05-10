cmake_minimum_required(VERSION 3.31)
project(sleeptimer)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# If using GitHub Actions, set the Qt prefix path dynamically
if(DEFINED ENV{QT_INSTALL_PATH})
    set(CMAKE_PREFIX_PATH $ENV{QT_INSTALL_PATH}/lib/cmake)
else()
    set(CMAKE_PREFIX_PATH "C:/Qt/6.9.0/mingw_64/lib/cmake")
endif()

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(sleeptimer src/main.cpp
        include/mainwindow.h
        lib/mainwindow.cpp
        lib/mainwindow.ui
)
target_include_directories(sleeptimer PRIVATE include ui)
target_link_libraries(sleeptimer
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

# Post-build steps to copy necessary Qt DLLs after the build
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()

    # Using the correct Qt install path
    set(QT_INSTALL_PATH $ENV{QT_INSTALL_PATH})

    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
    endif ()

    # Copy Qt platform DLLs (for example, qwindows.dll for Windows)
#    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
#        add_custom_command(TARGET sleeptimer POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E make_directory
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#        add_custom_command(TARGET sleeptimer POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy
#                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#    endif ()

    # Copy Qt DLLs (Core, Gui, Widgets) to the target folder
#    foreach (QT_LIB Core Gui Widgets)
#        add_custom_command(TARGET sleeptimer POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy
#                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
#    endforeach (QT_LIB)
endif ()

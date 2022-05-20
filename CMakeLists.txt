cmake_minimum_required(VERSION 3.5)

project(FSyncX VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt5 COMPONENTS Network REQUIRED)


set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui

        ChildWindow/SettingWindow.h 
        ChildWindow/SettingWindow.cpp 
        ChildWindow/SettingWindow.ui
        
        Theme/APPTheme.qrc
        icons/APPicons.qrc

        DATA/DATA_Sync/FileWatcher.h
        DATA/DATA_Sync/FileWatcher.cpp
        DATA/DATA_Sync/FileTransfer.h
        DATA/DATA_Sync/FileTransfer.cpp

        DATA/DATA_Base/FileBase.h
        DATA/DATA_Base/FileBase.cpp


        UI_Modules/QHeaders.h
        UI_Modules/CommonHelper.cpp
        UI_Modules/CommonHelper.h
        UI_Modules/PageManager.cpp
        UI_Modules/PageManager.h
        UI_Modules/SyncPage.cpp
        UI_Modules/SyncPage.h
        UI_Modules/BasePage.cpp
        UI_Modules/BasePage.h
        UI_Modules/ContextMenu.cpp
        UI_Modules/ContextMenu.h
        UI_Modules/ListenFromDATA.cpp
        UI_Modules/ListenFromDATA.h

        CONFIG/ConfigManager.cpp
        CONFIG/ConfigManager.h

        UI_Modules/ThemeManager.cpp
        UI_Modules/ThemeManager.h

        icons/logo.rc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(FSyncX
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET FSyncX APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(FSyncX SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FSyncX
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(FSyncX PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(FSyncX PRIVATE Qt${QT_VERSION_MAJOR}::Network)

set_target_properties(FSyncX PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FSyncX)
endif()

cmake_minimum_required(VERSION 3.5)

project(obs-multiview-ext LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(ARCH 64)
else()
    set(ARCH 32)
endif()

find_package(LibObs REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Network REQUIRED)
#find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

include_directories(
    "${LIBOBS_INCLUDE_DIR}/../UI/obs-frontend-api"
    SYSTEM
    ${Qt${QT_VERSION_MAJOR}Core_INCLUDES}
    ${Qt${QT_VERSION_MAJOR}Widgets_INCLUDES}
    ${Qt${QT_VERSION_MAJOR}Network_INCLUDES}
    #    "${CMAKE_SOURCE_DIR}/UI"
    )

set(PROJECT_SOURCES
    obs_multiview_ext.cpp
    )
set(PROJECT_HEADERS
    obs_multiview_ext.h
    )

add_library(obs-multiview-ext MODULE
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS})

target_link_libraries(obs-multiview-ext
    "${OBS_FRONTEND_LIB}"
    ${obs-midi_DEPS}
    Qt5::Core
    Qt5::Widgets
    Qt5::Network
    libobs)

if(UNIX AND NOT APPLE)
    include(GNUInstallDirs)

    set_target_properties(obs-multiview-ext PROPERTIES PREFIX "")
    target_link_libraries(obs-multiview-ext obs-frontend-api)

    #	file(GLOB locale_files data/locale/*.ini)

    #    if(${USE_UBUNTU_FIX})
    install(TARGETS obs-multiview-ext
        LIBRARY DESTINATION
        "/usr/lib/obs-plugins"
        )
    #    endif()
    #    install(TARGETS obs-multiview-ext
    #        LIBRARY DESTINATION "${CMAKE_INSTALL_FULL_LIBDIR}/obs-plugins")

    #	install(FILES ${locale_files}
    #		DESTINATION "${CMAKE_INSTALL_FULL_DATAROOTDIR}/obs/obs-plugins/obs-multiview-ext/locale")
endif()

#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(LibObs REQUIRED)
#find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

#if(CMAKE_SIZEOF_VOID_P EQUAL 8)
#        set(ARCH 64)
#else()
#        set(ARCH 32)
#endif()


#add_library(obs-mv-ext SHARED
#  obs-mv-ext_global.h
#  obs_multiview_ext.cpp
#  obs_multiview_ext.h
#)

#target_link_libraries(obs-mv-ext PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

#target_compile_definitions(obs-mv-ext PRIVATE OBSMVEXT_LIBRARY)

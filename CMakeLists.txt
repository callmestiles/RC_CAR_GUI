cmake_minimum_required(VERSION 3.16)

project(RC_CAR_QUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add SerialPort and Network to the required components
find_package(Qt6 REQUIRED COMPONENTS Quick SerialPort Network)

qt_standard_project_setup(REQUIRES 6.8)

# Add the .qrc file as a Qt resource
qt_add_resources(resources resources.qrc)

qt_add_executable(appRC_CAR_QUI
    PathfindingEngine.h
    PathfindingEngine.cpp
    CarController.h
    CarController.cpp
    ThumbstickController.h
    ThumbstickController.cpp
    main.cpp
    ${resources}  # Add the compiled qrc resources to your target
)

# Add your QML files (you can keep this for structured QML modules)
qt_add_qml_module(appRC_CAR_QUI
    URI RC_CAR_QUI
    VERSION 1.0
    QML_FILES
        Main.qml
        TopographicalMapView.qml
)

set_target_properties(appRC_CAR_QUI PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Add SerialPort and Network to the linked libraries
target_link_libraries(appRC_CAR_QUI
    PRIVATE 
    Qt6::Quick
    Qt6::SerialPort
    Qt6::Network
)

include(GNUInstallDirs)
install(TARGETS appRC_CAR_QUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
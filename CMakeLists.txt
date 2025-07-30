# cmake_minimum_required(VERSION 3.16)

# project(RC_CAR_QUI VERSION 0.1 LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(Qt6 REQUIRED COMPONENTS Quick)

# qt_standard_project_setup(REQUIRES 6.8)

# # Add the .qrc file as a Qt resource
# qt_add_resources(resources resources.qrc)

# qt_add_executable(appRC_CAR_QUI
#     PathfindingEngine.h
#     PathfindingEngine.cpp
#     CarController.h
#     CarController.cpp
#     main.cpp
#     ${resources}  # Add the compiled qrc resources to your target
# )

# # Add your QML files (you can keep this for structured QML modules)
# qt_add_qml_module(appRC_CAR_QUI
#     URI RC_CAR_QUI
#     VERSION 1.0
#     QML_FILES
#         Main.qml
#         TopographicalMapView.qml
# )

# set_target_properties(appRC_CAR_QUI PROPERTIES
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# target_link_libraries(appRC_CAR_QUI
#     PRIVATE Qt6::Quick
# )

# include(GNUInstallDirs)
# install(TARGETS appRC_CAR_QUI
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

cmake_minimum_required(VERSION 3.5)

project(RC_CAR_QUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5 components, including SerialPort
find_package(Qt5 REQUIRED COMPONENTS Core Quick Network SerialPort)

# Enable Qt5 tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Add Qt5 resources
qt5_add_resources(QT_RESOURCES resources.qrc)

# Create executable
add_executable(appRC_CAR_QUI
    PathfindingEngine.h
    PathfindingEngine.cpp
    CarController.h
    CarController.cpp
    ThumbstickController.h
    ThumbstickController.cpp
    main.cpp
    ${QT_RESOURCES}
)

# Set target properties (optional, platform specific)
set_target_properties(appRC_CAR_QUI PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Link Qt5 libraries including SerialPort
target_link_libraries(appRC_CAR_QUI
    PRIVATE
    Qt5::Core
    Qt5::Quick
    Qt5::Network
    Qt5::SerialPort
)

# Install configuration
include(GNUInstallDirs)
install(TARGETS appRC_CAR_QUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


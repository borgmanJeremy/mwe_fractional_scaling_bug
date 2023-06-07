find_package(
  Qt6
  CONFIG
  REQUIRED
  Core
  Gui
  Widgets
  Svg
  DBus)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(screenshot_mwe)
add_executable(Screenshot_mwe::screenshot_mwe ALIAS screenshot_mwe)

target_sources(
  screenshot_mwe
  PRIVATE
           screenshot.cpp
          main.cpp)


target_link_libraries(
  screenshot_mwe
  project_warnings
  project_options
  Qt6::Svg
  Qt6::DBus
  Qt6::Widgets)



# ######################################################################################################################
# Installation instructions

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/screenshot_mwe)

# Install binary
install(TARGETS screenshot_mwe
        EXPORT screenshot_mwe-targets
        BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
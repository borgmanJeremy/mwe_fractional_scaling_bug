find_package(
  Qt5
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
  Qt5::Svg
  Qt5::DBus
  Qt5::Widgets)

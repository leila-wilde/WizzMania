cmake_minimum_required(VERSION 3.16)
project(WizzMania)

set(CMAKE_CXX_STANDARD 17)

# Qt build automation tools
set(CMAKE_AUTOMOC ON) # meta-object compiler (processes .h files with Qt signal/slots, generates moc_*.cpp files automatically, required for any class with Q_OBJECT macro)
set(CMAKE_AUTORCC ON) # resource compiler (processes .qrc files(resource bundles), embeds images, icons, stylesheets into executable, generates qrc_*.cpp files)
set(CMAKE_AUTOUIC ON) # user inferface compiler (processes .ui files, generates ui_*.h header files, makes UI elements accessible in code)

find_package(Qt6 COMPONENTS Core Network Gui Widgets REQUIRED)

# server executable
add_executable()

target_link_libraries()

# client executable
add_executable()

target_link_libraries()

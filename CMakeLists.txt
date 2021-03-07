cmake_minimum_required(VERSION 3.15)
project(Alpaca VERSION 1.1.0)

add_library(alpaca SHARED alpaca.h alpaca.cpp)
target_include_directories(alpaca PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(alpaca PROPERTIES VERSION 1.1.0 SOVERSION 1)
set_target_properties(alpaca PROPERTIES PUBLIC_HEADER alpaca.h)

configure_file(alpaca.pc.in alpaca.pc @ONLY)

add_executable(alpacaDemo main.cpp)
target_link_libraries(alpacaDemo LINK_PUBLIC alpaca)

include(GNUInstallDirs)
install(TARGETS alpaca alpacaDemo
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/alpaca.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

message("Have a good day!")

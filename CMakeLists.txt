cmake_minimum_required(VERSION 3.10)
project(SimpleSensoray_Project)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D_LINUX -no-pie -lm")
link_directories("/home/naghmehz/Documents/sensoray-sdk/driver")



set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_definitions(-DOSTYPE_linux)

add_library(
	simple826
	simple826.cpp
	simple826.hpp
	)
add_library(
	forcesensor
	forcesensor.cpp
	forcesensor.hpp
	)

add_executable(Sensoray_demo main.cpp)

INCLUDE_DIRECTORIES("/home/naghmehz/Documents/sensoray-sdk/driver")

target_link_libraries(simple826 PRIVATE  "/home/naghmehz/Documents/sensoray-sdk/demo/lib826_64.a" m)
target_link_libraries(forcesensor PRIVATE  simple826 "/home/naghmehz/Documents/sensoray-sdk/demo/lib826_64.a" m)

target_link_libraries(Sensoray_demo PRIVATE  forcesensor simple826  "/home/naghmehz/Documents/sensoray-sdk/demo/lib826_64.a" m)


# target_link_libraries(SystemRun PRIVATE omnimagnet type "/usr/local/lib/libcomedi.a")

# add_executable(CameraCalibration camera_calibration.cpp)

# target_link_libraries(CameraCalibration "/usr/lib/libSpinnaker.so"  ${OpenCV_LIBS})

cmake_minimum_required(VERSION 3.2)

PROJECT(ImageProcess)

INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
#	/usr/local/include/opencv4/
#	/usr/local/include/opencv4/opencv2/
)

FIND_PACKAGE(OpenCV)
INCLUDE_DIRECTORIES(${OpenCV} REQUIRED)

#AUX_SOURCE_DIRECTORY(src DIR_SRCS)

SET(CMAKE_PATH ${CMAKE_CURRENT_SOURCE_DIR}
)

ADD_EXECUTABLE(hsv_enhancement ${CMAKE_PATH}/hsv_enhancement.cpp)
TARGET_LINK_LIBRARIES(hsv_enhancement ${OpenCV_LIBRARIES}
)

ADD_EXECUTABLE(test_cv ${CMAKE_PATH}/test.cpp)
TARGET_LINK_LIBRARIES(test_cv ${OpenCV_LIBRARIES}
#	/usr/local/lib/libopencv_core.so
#	/usr/local/lib/libopencv_highgui.so
#	/usr/local/lib/libopencv_imgproc.so
)


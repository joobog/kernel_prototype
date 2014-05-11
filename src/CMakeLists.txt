set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# add_definitions(-DNTY_PLUGINS_DIR="/usr/lib/nty-slave")
add_executable(aes_prototype main.cpp scheduler.cpp scheduler.hpp data_controller.cpp data_controller.hpp slack_task.hpp
${CMAKE_CURRENT_SOURCE_DIR}/modules/i_module.hpp
${CMAKE_CURRENT_SOURCE_DIR}/modules/i_rttask.hpp
${CMAKE_CURRENT_SOURCE_DIR}/modules/i_data_carrier.hpp
#${CMAKE_CURRENT_SOURCE_DIR}/modules/gps/gps_module.cpp
${CMAKE_CURRENT_SOURCE_DIR}/modules/demo_module/demo_module.cpp
${CMAKE_CURRENT_SOURCE_DIR}/modules/demo_module/demo_module.hpp
${CMAKE_CURRENT_SOURCE_DIR}/modules/demo_module/demo_task.cpp
${CMAKE_CURRENT_SOURCE_DIR}/modules/demo_module/demo_task.hpp
${CMAKE_CURRENT_SOURCE_DIR}/modules/demo_module/demo_data_carrier.hpp
${CMAKE_CURRENT_SOURCE_DIR}/modules/demo_module/demo_data_carrier.cpp
#${CMAKE_CURRENT_SOURCE_DIR}/modules/gps/gps_module.hpp
#${CMAKE_CURRENT_SOURCE_DIR}/modules/gps/gps_task.hpp
#${CMAKE_CURRENT_SOURCE_DIR}/modules/gps/gps_task.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# SET(ZMQ_INCLUDE ${ZMQ_INCLUDE} CACHE STRING "Location of ZeroMQ headers.")
# SET(ZMQ_LIBRARY ${ZMQ_LIBRARY} CACHE STRING "ZeroMQ libraries to link in.")

# include_directories(${ZMQ_INCLUDE})
# target_link_libraries(netanomy-slave ${ZMQ_LIBRARY})
# target_link_libraries(aes_prototype )

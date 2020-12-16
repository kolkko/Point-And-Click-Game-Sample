project(PointAndClickGame)

find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

add_executable(PointAndClickGame src/main.cpp src/housekeeping.cpp src/text.cpp src/picture.cpp src/item.cpp src/lbutton.cpp)
target_link_libraries(PointAndClickGame ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY})
install(TARGETS PointAndClickGame RUNTIME DESTINATION ${BIN_DIR})
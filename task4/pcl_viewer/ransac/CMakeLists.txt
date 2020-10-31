aux_source_directory(. DIR_RANSAC)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

include_directories(../include)

add_library(RANSAC ${DIR_RANSAC})
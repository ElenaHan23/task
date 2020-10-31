aux_source_directory(. DIR_NORMAL)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

include_directories(../include)

add_library(NORMAL ${DIR_NORMAL})
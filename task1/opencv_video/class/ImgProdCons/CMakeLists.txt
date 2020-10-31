aux_source_directory(. DIR_IMGPRODCONS)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

include_directories(../include)
include_directories(../../Armor/include)

add_library(IMGPRODCONS ${DIR_IMGPRODCONS})

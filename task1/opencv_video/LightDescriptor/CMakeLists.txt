aux_source_directory(. DIR_LIGHTDESCRIPTOR)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

include_directories(../include)

add_library(LIGHTDESCRIPTOR ${DIR_LIGHTDESCRIPTOR})

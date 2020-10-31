aux_source_directory(. DIR_ARMOR)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

include_directories(../include)
include_directories(../../LightDescriptor/include/LightDescriptor.h)


add_library(ARMOR ${DIR_ARMOR})

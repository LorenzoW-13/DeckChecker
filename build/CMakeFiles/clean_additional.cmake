# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MTGManager_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MTGManager_autogen.dir\\ParseCache.txt"
  "MTGManager_autogen"
  )
endif()

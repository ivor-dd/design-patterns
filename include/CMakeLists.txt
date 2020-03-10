#############################
# Library
#############################

# Add the executable
add_library(${TARGET_NAME_LIBRARY} INTERFACE
)

# Include the directories
target_include_directories(${TARGET_NAME_LIBRARY}
	INTERFACE "./"
)

target_compile_features(${TARGET_NAME_LIBRARY} INTERFACE cxx_std_17)
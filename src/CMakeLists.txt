#############################
# RaceTrack
#############################

# Add the executable
add_library(race-track STATIC
	"implementations/RaceTrack/RaceTrack.cpp"
	"implementations/RaceTrack/RaceTrackBuilder.cpp"
	"implementations/RaceTrack/CornerMasterBuilder.cpp"
	"implementations/RaceTrack/DragMasterBuilder.cpp"
	"implementations/RaceTrack/CreateTrack.cpp"
	"implementations/RaceTrack/RaceTrackPrototypeFactory.cpp"
)

# Include the directories
target_include_directories(race-track
	PUBLIC "./headers"
	PUBLIC "./headers/RaceTrack"
)

target_compile_features(race-track PUBLIC cxx_std_17)

#############################
# Racer
#############################

# Add the executable
add_library(racer STATIC
	"implementations/Racer/Racer.cpp"
	"implementations/Racer/Player.cpp"
	"implementations/Racer/NPC.cpp"
)

# Include the directories
target_include_directories(racer
	PUBLIC "./headers"
	PUBLIC "./headers/Racer"
)

target_compile_features(racer PUBLIC cxx_std_17)

#############################
# Car
#############################

# Add the executable
add_library(car STATIC
	"implementations/Car/Car.cpp"
	"implementations/Car/CarRefined.cpp"
	"implementations/Car/Speedster.cpp"
	"implementations/Car/Rocket.cpp"
	"implementations/Car/Classic.cpp"
	"implementations/Car/SpeedsterFactory.cpp"
	"implementations/Car/ClassicFactory.cpp"
	"implementations/Car/RocketFactory.cpp"
	"implementations/Car/FactoryProduce.cpp"
)

# Include the directories
target_include_directories(car
	PUBLIC "./headers"
	PUBLIC "./headers/Car"
)

target_link_libraries(car PUBLIC racer)
target_compile_features(car PUBLIC cxx_std_17)

#############################
# GameState
#############################

# Add the executable
add_library(game-state STATIC
	"implementations/GameState.cpp"
)

# Include the directories
target_include_directories(game-state
	PUBLIC "./headers"
)

target_link_libraries(game-state PUBLIC car)
target_link_libraries(game-state PUBLIC race-track)
target_link_libraries(game-state PUBLIC racer)
target_compile_features(game-state PUBLIC cxx_std_17)

#############################
# Executable
#############################

# Add the executable
add_executable(${TARGET_NAME_EXECUTABLE} "main.cpp")

target_link_libraries(${TARGET_NAME_EXECUTABLE} PUBLIC game-state)
target_link_libraries(${TARGET_NAME_EXECUTABLE} PUBLIC race-track)
target_link_libraries(${TARGET_NAME_EXECUTABLE} PUBLIC car)
target_link_libraries(${TARGET_NAME_EXECUTABLE} PUBLIC ${TARGET_NAME_LIBRARY})

target_compile_features(${TARGET_NAME_EXECUTABLE} PRIVATE cxx_std_17)
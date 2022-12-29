cmake_minimum_required(VERSION 3.15)
									

set(PROJECT_NAME SimpleDino)						 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 

include_directories("ext/SFML/include/")	
include_directories("inc/")
link_directories("ext/SFML/lib/")	

add_executable("${PROJECT_NAME}" Project11C++.cpp

        inc/Animation.h src/Animation.cpp
		inc/Obstacle.h src/Obstacle.cpp
		inc/StateObjects.h src/StateObjects.cpp)
											
target_link_libraries("${PROJECT_NAME}" sfml-graphics-s
						  sfml-window-s
						  sfml-system-s
						  opengl32
						  freetype
						  winmm
						  gdi32
						  sfml-audio-s
						  openal32
						  flac
						  vorbisenc
						  vorbisfile
						  vorbis
						  ogg)
						  
file(COPY "images" DESTINATION "/")
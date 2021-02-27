all: kingdomRush.cpp rsdl.cpp mainFunctions.cpp functions.cpp functions.hpp mainFunctions.hpp
	g++ kingdomRush.cpp rsdl.cpp mainFunctions.cpp functions.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -o kr.out

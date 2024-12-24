CXX = g++
CXXFLAGS = -Wall -Iinclude -g
OPT =-O3
SRC = src/cavalier.cpp src/echiquier.cpp src/fou.cpp src/pion.cpp src/reine.cpp src/roi.cpp src/tour.cpp src/vide.cpp src/piece.cpp src/jeu.cpp
OBJ = obj/cavalier.o obj/echiquier.o obj/fou.o obj/pion.o obj/reine.o obj/roi.o obj/tour.o obj/vide.o obj/piece.o obj/jeu.o
INCLUDE = include/cavalier.hpp include/echiquier.hpp include/fou.hpp include/pion.hpp include/reine.hpp include/roi.hpp include/tour.hpp include/vide.hpp include/piece.hpp include/jeu.hpp
main : obj/main.o $(OBJ)
	$(CXX) $(OPT) obj/main.o $(OBJ) -o main

obj/main.o : main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp -o obj/main.o

obj/%.o : src/%.cpp $(INCLUDE) | obj
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f obj/*.o main
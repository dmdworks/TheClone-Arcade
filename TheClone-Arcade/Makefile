CXX = clang++

CXXFLAGS = -lncurses

TheClone-Arcade: main.o GameMenu.o SnakeGame.o TetrisGame.o TetrisPiece.o
	$(CXX) $(CXXFLAGS) main.o GameMenu.o  SnakeGame.o TetrisGame.o TetrisPiece.o -o TheClone-Arcade

main.o: main.cpp GameMenu.hpp SnakeGame.hpp TetrisGame.hpp
	$(CXX) $(CXXFLAGS) main.cpp -c

GameMenu.o: GameMenu.cpp GameMenu.hpp
	$(CXX) $(CXXFLAGS) GameMenu.cpp -c

SnakeGame.o: SnakeGame.cpp SnakeGame.hpp
	$(CXX) $(CXXFLAGS) SnakeGame.cpp -c

TetrisGame.o: TetrisGame.cpp TetrisGame.hpp
	$(CXX) $(CXXFLAGS) TetrisGame.cpp -c

TetrisPiece.o: TetrisPiece.cpp TetrisPiece.hpp
	$(CXX) $(CXXFLAGS) TetrisPiece.cpp -c


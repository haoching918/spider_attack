all:
	g++ -c -std=c++17 player.cpp monster.cpp entity.cpp hero.cpp utils.cpp
	g++ -std=c++17 main.cpp *.o -o main.out
clean:
	rm -rf *.o *.out
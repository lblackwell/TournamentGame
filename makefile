all: assignment4

assignment4: assignment4.cpp Character.cpp Barbarian.cpp Reptile.cpp BlueMen.cpp Goblin.cpp Shadow.cpp
	g++ -std=c++0x assignment4.cpp Character.cpp Barbarian.cpp Reptile.cpp BlueMen.cpp Goblin.cpp Shadow.cpp -o assignment4

clean:
	rm -f *.o
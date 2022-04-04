output: main.o jeu.o tour.o disque.o
	g++ main.o jeu.o tour.o disque.o -o prog

main.o: main.cpp
	g++ -c main.cpp

main.o: jeu.cpp
	g++ -c jeu.cpp

main.o: tour.cpp
	g++ -c tour.cpp

main.o: disque.cpp
	g++ -c disque.cpp

clean: 
	rm *.o prog
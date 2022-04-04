output: main.o jeu.o tour.o disque.o
	g++ main.o jeu.o tour.o disque.o -o prog

main.o: main.cpp
	g++ -c main.cpp

jeu.o: jeu.cpp jeu.hpp
	g++ -c jeu.cpp

tour.o: tour.cpp tour.hpp
	g++ -c tour.cpp

disque.o: disque.cpp disque.hpp
	g++ -c disque.cpp

clean: 
	rm *.o prog
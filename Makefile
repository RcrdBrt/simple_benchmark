mp:
	g++ -fopenmp -std=c++11 -static-libgcc -static-libstdc++ -D MP main.cpp -o main
standard:
	g++ -fopenmp -std=c++11 -static-libgcc -static-libstdc++ main.cpp -o main

mp2:
	g++ -O2 -fopenmp -std=c++11 -static-libgcc -static-libstdc++ -D MP main.cpp -o main

mp3:
	g++ -O3 -fopenmp -std=c++11 -static-libgcc -static-libstdc++ -D MP main.cpp -o main

clean:
	rm main

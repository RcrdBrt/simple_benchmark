mp:
	g++ -fopenmp -std=c++11 -static-libgcc -static-libstdc++ -D MP main.cpp -o main
standard:
	g++ -fopenmp -std=c++11 -static-libgcc -static-libstdc++ main.cpp -o main
clean:
	[ -e main ] && rm main

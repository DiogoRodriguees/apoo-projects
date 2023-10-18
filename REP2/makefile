all:
	g++ -c ./Display/DisplayDiogo.cpp -o ./Display/DisplayDiogo.o
	g++ -c ./Console/Console.cpp -o ./Console/Console.o
	g++ -c ./CPU/CpuDiogo.cpp -o ./CPU/CpuDiogo.o
	g++ -c ./Keyboard/KeyboardDiogo.cpp -o ./Keyboard/KeyboardDiogo.o
	g++ -c ./Key/KeyDiogo.cpp -o ./Key/KeyDiogo.o
	g++ main.cpp ./CPU/CpuDiogo.o ./Console/Console.o ./Display/DisplayDiogo.o ./Key/KeyDiogo.o ./Keyboard/KeyboardDiogo.o  -o main
	./main
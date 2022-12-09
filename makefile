all:
	g++ -o main *.cpp ./System/*.cpp ./ContratoCtrl/*.cpp ./Contrato/*.cpp ./ContratoDAO/*.cpp ./Professor/*.cpp
	./main
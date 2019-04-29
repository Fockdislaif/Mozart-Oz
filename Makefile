all:
	g++ main.cpp Operaciones/*.cpp TAD-Almacen/*.cpp TAD-ValorOz/*.cpp -o project.exe
	project.exe < input.txt > salida.txt

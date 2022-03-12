test:main.o sub_int.o sub_float.o add_float.o add_int.o
	g++ -o test main.o sub_int.o sub_float.o add_float.o add_int.o
main.o:main.cpp
	g++ -c main.cpp
sub_int.o:sub_int.cpp sub.hpp
	g++ -c sub_int.cpp
sub_float.o:sub_float.cpp sub.hpp
	g++ -c sub_float.cpp
add_int.o:add_int.cpp add.hpp
	g++ -c add_int.cpp add.hpp
add_float.o:add_float.cpp add.hpp
	g++ -c add_float.cpp add.hpp
	
.PHONY:clean
clean:
	rm -rf *.o *.gch

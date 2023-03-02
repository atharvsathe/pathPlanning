general_compile_options = -Werror -Wextra -Wall 
style_compile_options = -Wparentheses -pedantic -Wunused-variable
variable_compile_options = -Wfloat-equal -Wconversion -Wunused-parameter -Wredundant-decls -Wunused-value -Wuninitialized  
func_compile_options = -Wreturn-type -Wunused-function -Wswitch-default  -Winit-self


CC 		:= g++
CFLAGS 	:= -O3 -g $(general_compile_options) #$(style_compile_options) $(variable_compile_options) $(func_compile_options)

DEPS = kdTree.cpp rrt.cpp naiveTree.cpp
OBJ = kdTree.o rrt.o naiveTree.o

all: main.o $(OBJ)
	$(CC) main.o $(OBJ) -o main

	if [ -a points.txt ]; then rm points.txt; fi;
	if [ -a path.txt ]; then rm path.txt; fi;

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: main.o $(OBJ)
	rm -rf *o

	chmod a+x main
	./main

clean:
	rm -rf *o main
	rm points.txt
	rm path.txt
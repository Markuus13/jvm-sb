CC=g++
CFLAGS=-Wall -std=c++11
CPPCHECK=cppcheck
GCOV=--coverage
C_SRCS := $(wildcard *.cpp)

DIR_SRC=src/
DIR_OBJ=build/

_OBJ= main.o Frame.o Interpreter.o ClassFileReader.o ClassFilePrinter.o CpInfo.o FieldInfo.o MethodInfo.o AttributeInfo.o ReadBytes.o InterfaceInfo.o Instruction.o ClassLoader.o MethodsArea.o InstructionsFunc.o
OBJ = $(patsubst %,$(DIR_OBJ)%,$(_OBJ))

all : clean cppcheck compile gcov exec

gcov :
	@echo "Checking coverage..."
	@gcov build/ClassFileReader build/ClassFilePrinter build/CpInfo build/FieldInfo build/MethodInfo build/AttributeInfo build/ReadBytes build/Instruction buiild/InterfaceInfo build/MethodsArea build/ClassLoader build/InstructionsFunc build/main
	@echo "Done checking!"

exec :
	@echo "Running main..."
	@echo "\n\n\n"
	@build/./main
	@echo "\n\n\n"
	@echo "Done running!"

$(DIR_OBJ)%.o: $(DIR_SRC)%.cpp
	@$(CC) $(CFLAGS) -c -o $@ $< -Iincludes $(GCOV)

compile: $(OBJ)
	@echo "Building objects..."
	@$(CC) $(CFLAGS) -o build/main $^ -Iincludes $(GCOV)
	@echo "Done building!"

cppcheck :
	@echo "Static code analysis..."
	@$(CPPCHECK) src/ClassFileReader.cpp src/ClassFilePrinter.cpp src/CpInfo.cpp src/MethodInfo.cpp src/FieldInfo.cpp src/AttributeInfo.cpp src/Instruction.cpp src/ReadBytes.cpp src/InterfaceInfo src/MethodsArea src/ClassLoader src/InstructionsFunc.cpp src/main.cpp
	@echo "Done static analysis!"

clean :
	@echo "Cleaning..."
	@rm -rf build
	@mkdir build
	@echo "Done cleaning!"

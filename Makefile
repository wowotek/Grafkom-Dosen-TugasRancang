CC 		= clang++
CFLAGS 	= -W -pedantic -Wall -Wextra -Werror
CDEPS	= -lGL -lGLU -lGLUT

EXEC	= dosenTR.app

OBJ		= build/o
BIN		= build/bin

OREQ	= main.o

all: build run

run:
	@cd build/bin/ && ./$(EXEC)

build: clean create buildnotice $(EXEC)
	@echo "[MAKE] project built successfuly !"
	@echo ""

buildnotice:
	@echo "[MAKE] building projects..."

create:
	@echo "[MAKE] creating build folder..."
	@echo "[MAKE]    | creating build/bin/"
	@mkdir -p build/bin/
	@echo "[MAKE]    | creating build/o/"
	@mkdir -p build/o/
	@echo ""

clean:
	@echo "[MAKE] cleaning build folder..."
	@rm -rf build/
	@echo ""

main.o: src/main.cc
	@echo "[MAKE]    | compiling main.o"
	@$(CC) $(CFLAGS) -c src/main.cc -o $(OBJ)/main.o

$(EXEC): $(OREQ)
	@echo "[MAKE]    | building executables [$(OREQ)]"
	@$(CC) $(CFLAGS) $(OBJ)/main.o $(CDEPS) -o $(BIN)/$(EXEC)

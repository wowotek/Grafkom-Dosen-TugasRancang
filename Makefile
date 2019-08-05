CC 		= clang++
CCOMP	= -O3
CFLAGS 	= -Ilib/Box2D/ #-W -pedantic -Wall -Wextra -Werror 
CDEPS	= -lGL -lGLU -lglut

EXEC	= dosenTR.app

OBJ		= build/o
BIN		= build/bin

OREQ	= shape.o entity.o control.o texture.o joint.o main.o

all: build run

run:
	@echo ""
	@echo "[MAKE] running $(EXEC)"
	@echo ""
	@cd build/bin/ && ./$(EXEC)

build: preparation buildnotice $(EXEC)
	@echo "[MAKE] project built successfuly !"
	@echo ""

buildnotice:
	@echo "[MAKE] building projects..."

preparation: clean create cpdata cpbox2d 

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

cpdata:
	@echo "[MAKE] copying data folder..."
	@cp -r data/ build/bin/data/
	@echo ""
# BOX2D RELATED

dlbox2d:
	@echo "[MAKE] cloning Box2D"
	@echo "[MAKE]    | checking if Box2D has been cloned..."
ifeq (,$(wildcard ./lib/Box2D/Box2D/Box2D.h))
	@echo "[MAKE]    | Box2D is not cloned. Cloning..."
	@cd lib/ && git clone https://github.com/wowotek/Box2D
else
	@echo "[MAKE]    | Box2D is cloned. Skipping..."
endif
	@echo ""

makebox2d: dlbox2d
	@echo "[MAKE] building Box2D Static Library..."
	@echo "[MAKE]    | checking compiled static library : ./lib/Box2D/Build/bin/x86_64/Debug/libBox2D.a"
ifeq (,$(wildcard ./lib/Box2D/Build/bin/x86_64/Debug/libBox2D.a))
	@echo "[MAKE]    | static library is not built yet, Compiling..."
	@make -C lib/Box2D/Build -s
else
	@echo "[MAKE]    | static library has been compiled! skipping...."
endif
	@echo ""

cpbox2d: makebox2d
	@echo "[MAKE] copying Box2D Static Library..."
	@echo "[MAKE]    | checking static library at : lib/Box2D/Build/bin/x86_64/Debug/libBox2D.a"
ifeq (,$(wildcard ./lib/libBox2D.a))
	@echo "[MAKE]    | static library doesn't Exist, copying from Box2D build folder to lib/libBox2D.a"
	@cp lib/Box2D/Build/bin/x86_64/Debug/libBox2D.a lib/
else
	@echo "[MAKE]    | Box2D static library exist! skipping..."
endif
	@echo ""

# -------------

shape.o: src/shape.cc src/shape.hh
	@echo "[MAKE]    | compiling shape.o"
	@$(CC) $(CFLAGS) -c src/shape.cc -o $(OBJ)/shape.o

entity.o: src/entity.cc src/entity.hh
	@echo "[MAKE]    | compiling entity.o"
	@$(CC) $(CFLAGS) -c src/entity.cc -o $(OBJ)/entity.o

control.o: src/control.cc src/control.hh
	@echo "[MAKE]    | compiling control.o"
	@$(CC) $(CFLAGS) -c src/control.cc -o $(OBJ)/control.o

texture.o: src/texture.cc src/texture.hh
	@echo "[MAKE]    | compiling texture.o"
	@$(CC) $(CFLAGS) -c src/texture.cc -o $(OBJ)/texture.o

joint.o: src/joint.cc src/joint.hh
	@echo "[MAKE]    | compiling joint.o"
	@$(CC) $(CFLAGS) -c src/joint.cc -o $(OBJ)/joint.o

main.o: src/main.cc
	@echo "[MAKE]    | compiling main.o"
	@$(CC) $(CFLAGS) -c src/main.cc -o $(OBJ)/main.o

$(EXEC): $(OREQ)
	@echo "[MAKE]    | building executables [$(OREQ)]"
	@$(CC) $(CFLAGS) $(OBJ)/texture.o $(OBJ)/shape.o $(OBJ)/entity.o $(OBJ)/control.o $(OBJ)/joint.o $(OBJ)/main.o lib/libBox2D.a $(CDEPS) $(CCOMP) -o $(BIN)/$(EXEC)

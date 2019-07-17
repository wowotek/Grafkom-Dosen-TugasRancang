CC		= g++
CFLAGS	= -W -Wall -Wextra
CDEPS	= -lGL -lGLU -lglut

binf	= build/bin
of		= build/o

EXEC	= TR.exec

# Prerequisite for project build folder

all: cleanfolder createfolder ${EXEC}

cleanfolder:
	@rm -rf build/

createfolder:
	@mkdir -p build/bin/
	@mkdir -p build/o/


# Compiling Related

control.o: src/control.cpp src/control.hpp
	${CC} ${CFLAGS} -c src/control.cpp -o ${of}/control.o

render.o: src/render.cpp src/render.hpp
	${CC} ${CFLAGS} -c src/render.cpp -o ${of}/render.o

main.o: src/main.cpp
	${CC} ${CFLAGS} -c src/main.cpp -o ${of}/main.o

${EXEC}: control.o render.o main.o
	${CC} ${CFLAGS} control.o render.o main.o ${CDEPS} -o ${binf}/${EXEC}
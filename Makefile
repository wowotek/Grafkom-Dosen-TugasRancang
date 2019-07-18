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

control.o: src/control.cc src/control.hh
	${CC} ${CFLAGS} -c src/control.cc -o ${of}/control.o

render.o: src/render.cc src/render.hh
	${CC} ${CFLAGS} -c src/render.cc -o ${of}/render.o

entity.o: src/entity.cc src/entity.hh
	${CC} ${CFLAGS} -c src/entity.cc -o ${of}/entity.o

game.o: src/game.cc src/game.hh
	${CC} ${CFLAGS} -c src/game.cc -o ${of}/game.o


main.o: src/main.cc
	${CC} ${CFLAGS} -c src/main.cc -o ${of}/main.o

${EXEC}: control.o render.o entity.o game.o main.o
	${CC} ${CFLAGS} ${of}/control.o ${of}/render.o ${of}/entity.o ${of}/game.o ${of}/main.o ${CDEPS} -o ${binf}/${EXEC}
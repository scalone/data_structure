compile: ex1 program

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

runner: runner.o ex1.o
	@echo CC -o $@
	@${CC} -o $@ runner.o ex1.o

program: program.o ex1.o
	@echo CC -c -o $@
	@${CC} -o $@ program.o ex1.o

ex1: ${OBJ}
	@echo CC -o $@
	@${CC} -c -o $@ ${OBJ} ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f runner program *.o *.core ex1

test:
	./runner
compile: ex3.o ex2.o ex1.o program

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

runner: runner.o ex3.o ex1.o ex2.o
	@echo CC -o $@
	@${CC} -o $@ runner.o ex3.o ex1.o ex2.o

program: program.o ex3.o ex1.o ex2.o menu.o
	@echo CC -o $@
	@${CC} -o $@ program.o ex3.o ex1.o ex2.o menu.o

clean:
	@echo cleaning
	@rm -f runner program *.o *.core

test:
	./runner
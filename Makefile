# defining makefile varriables:
CC             = g++
CFLAGS         = -c
TARGET         = farid-ghafoori-CA2-810194465
headers        = load_balancer.h
objects        = main.o load_balancer.o
CPP_Files      = main.cpp load_balancer.cpp

all: out

out: $(objects) $(headers)
	$(CC) $(CCFLAGS) $(objects) -o out

main.o: main.cpp $(headers)
	$(CC) $(CFLAGS) main.cpp

load_balancer.o: load_balancer.cpp $(headers)
	$(CC) $(CFLAGS) load_balancer.cpp

clean:
	rm *.o
	rm out
	rm *.zip

zip:
	zip -r $(TARGET).zip $(headers) $(CPP_Files) Makefile \
OBJS = item.o creature.o magic_creature.o main.o

all: main

%.o: %.cpp %.h
	g++ -c $<

main: $(OBJS)
	g++ $(OBJS) -o main

clean:
	rm *.o


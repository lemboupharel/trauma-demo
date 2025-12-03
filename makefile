build:
	g++ ./src/*.cpp -o ./bin/prog \
	-I/usr/include/SDL3/ \
	-I/usr/include/SDL3_image/ \
	-L/usr/lib/ \
	-lSDL3 -lSDL3_image

run:
	./bin/prog

clean:
	rm ./bin/prog

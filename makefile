compile:
	g++ ./src/*.cpp -o ./build/trauma \
	-I/usr/include/SDL3/ \
	-I/usr/include/SDL3_image/ \
	-L/usr/lib/ \
	-lSDL3 -lSDL3_image

run:
	./build/trauma

clean:
	rm ./build/trauma

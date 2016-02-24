#Make!

objs = src/main.cpp src/player.cpp src/item.cpp
cc = clang++
output = build/rpg
compiler_flags = -std=c++11 -o $(output)

all:
	mkdir -p build
	$(cc) $(objs) $(compiler_flags)

g++:
	mkdir -p build
	g++ $(objs) $(compiler_flags)

run:
	$(output)

clean:
	rm -R build

# AWFULLY WRITTEN MAKEFILE

LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all:
	@echo "*** Building the game"

	g++ -c "src/Tilemap.cpp"    -o "build/Tilemap.o"
	g++ -c "src/State.cpp"      -o "build/State.o"
	g++ -c "src/TitleState.cpp" -o "build/TitleState.o"
	g++ -c "src/PlayState.cpp"  -o "build/PlayState.o"
	g++ -c "src/Game.cpp"       -o "build/Game.o"
	g++ -c "src/Player.cpp"     -o "build/Player.o"
	g++ -o 2dplatformer build/Tilemap.o build/Game.o build/State.o build/Player.o build/TitleState.o build/PlayState.o $(LIBS)

map_editor:
	@echo "*** Building the level editor"

	g++ -c "src/Tilemap.cpp"   -o "build/Tilemap.o"
	g++ -c "src/Editor.cpp" -o "build/Editor.o"

	g++ -o editor build/Tilemap.o build/Editor.o $(LIBS)

clean:
	@echo "*** Removing object files and executable..."

	rm -rf build/*
	rm -f 2dplatformer

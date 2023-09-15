
GCC=g++
VS=-std=c++11

SDL_DIR=dependencies/SDL2
AUPLAY_DIR=dependencies/vendor/auplay
BUILD_FLAGS=-O2 -c

SRC=src
BUILD=build/objectFiles

ifeq ($(OS),Windows_NT)
	RM=del
	INC=-I $(SDL_DIR)/WIN/include
	LIB=-L $(SDL_DIR)/WIN/lib
	DEP=-lmingw32 -lSDL2main -lSDL2
	PROGRAM_FILE=build/program.exe
else
	RM=rm
	INC=-I $(SDL_DIR)/MAC/include
	LIB=-L $(SDL_DIR)/MAC/lib
	DEP=-lSDL2-2.0.0 -Qunused-arguments
	PROGRAM_FILE=build/program
	AP_FLAGS+=-framework CoreFoundation -framework AudioToolbox
endif


all: $(PROGRAM_FILE)

$(PROGRAM_FILE): $(BUILD)/Main.o $(BUILD)/Application.o $(BUILD)/Debug.o $(BUILD)/Grid.o $(BUILD)/Cell.o $(BUILD)/Music.o $(BUILD)/AudioPlayer.o
	$(GCC) $(INC) $(LIB) $(VS) $(AP_FLAGS) -o $(PROGRAM_FILE) $(BUILD)/Main.o $(BUILD)/Application.o $(BUILD)/Debug.o $(BUILD)/Grid.o $(BUILD)/Cell.o $(BUILD)/Music.o $(BUILD)/AudioPlayer.o $(DEP)

$(BUILD)/Main.o: $(SRC)/Main.cpp $(SRC)/Application.h
	$(GCC) $(INC) $(LIB) $(VS) -o $@ $(BUILD_FLAGS) $< $(DEP)

$(BUILD)/Application.o: $(SRC)/Application.cpp $(SRC)/Application.h $(SRC)/Debug.h
	$(GCC) $(INC) $(LIB) $(VS) -o $@ $(BUILD_FLAGS) $< $(DEP)

$(BUILD)/Debug.o: $(SRC)/Debug.cpp $(SRC)/Debug.h
	$(GCC) $(INC) $(LIB) $(VS) -o $@ $(BUILD_FLAGS) $< $(DEP)

$(BUILD)/Grid.o: $(SRC)/Grid.cpp $(SRC)/Grid.h $(SRC)/Cell.h
	$(GCC) $(INC) $(LIB) $(VS) -o $@ $(BUILD_FLAGS) $< $(DEP)

$(BUILD)/Cell.o: $(SRC)/Cell.cpp $(SRC)/Cell.h
	$(GCC) $(INC) $(LIB) $(VS) -o $@ $(BUILD_FLAGS) $< $(DEP)

$(BUILD)/Music.o: $(SRC)/Music.cpp $(SRC)/Music.h $(AUPLAY_DIR)/AudioPlayer.h
	$(GCC) $(VS) $(AP_FLAGS) -o $@ $(BUILD_FLAGS) $< 

$(BUILD)/AudioPlayer.o: $(AUPLAY_DIR)/AudioPlayer.cpp $(AUPLAY_DIR)/AudioPlayer.h 
	$(GCC) $(VS) $(AP_FLAGS) -o $@ $(BUILD_FLAGS) $< 

run:
	./$(PROGRAM_FILE)

clean:
	$(RM) $(BUILD)/*.o
	$(RM) $(PROGRAM_FILE)
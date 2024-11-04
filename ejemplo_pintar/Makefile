CPPC=g++
SRC=hello.cpp
TARGET=puntos
LIBS= -lsfml-graphics -lsfml-window -lsfml-system

#DEFAULT
all: $(TARGET)

#COMPILE
$(TARGET): $(SRC)
	$(CPPC) -o $(TARGET) $(SRC) $(LIBS)

clean: 
	rm -rf $(TARGET)

# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -g -std=c++17

# Nome do executável
TARGET = programa

# Arquivos fonte
SRC = main.cpp ArvoreRB.cpp Nodo.cpp Produto.cpp

# Arquivos objeto (gerados automaticamente a partir do SRC)
OBJ = $(SRC:.cpp=.o)

# Regra padrão: compilar o programa
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regra para compilar os arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar os arquivos gerados (.o e executável)
clean:
	rm -f $(OBJ) $(TARGET)

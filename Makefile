COMP=clang++
W=-Wall
BUILD='./build'
APP='nb'
THISDIR='./'
INCLU='./include'
APINCLU='./nebinAPI/include'

# essa é uma var para guardar o comando de find para os arquivos .cpp
# ele basicamente pega todos os arquivos que ele encontra e retorna no
# lugar onde ele foi chamado

CPPLIST:=$(shell find . -type f -name "*.cpp")

# nessa parte, acontec isso:
# 	-> o objlist faz um patsubst, que é um curinga para
# 	-> modificar os arquivos e mudar eles de lugar com a dependência
# 	-> de uma lista, no caso o CPPLIST

OBJLIST:=$(patsubst ./%.cpp, $(BUILD)/%.o, $(CPPLIST))

# contudo, esse obj dir eu sinceramente n sei o que ele faz
# eu só sei que ele simplemente organiza os diretórios

OBJ_DIR:= $(sort $(dir $(CPPLIST)))
# aqui eu também n entendi nenhuma linha dessa regra exceto a
# linha de compilação

$(BUILD)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "acertando os diretórios para procura..."
	@$(COMP) -Wall -I$(THISDIR) -I/usr/include/mariadb -c $< -o $@
	@echo "compilando pré-binários"
$(APP): $(OBJLIST)
	@echo "\033[H\033[2J"
	@echo "NEBIN 1 INICIANDO..."
	@$(COMP) -Wall -o $@ $^ -lmariadb 
	@./nb
clean:
	@echo "apagando arquivos objeto..."
	@rm -rf ./build/*
	@echo "pronto."

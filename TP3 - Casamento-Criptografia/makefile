#---------------------------Variáveis da Tarefa A---------------------------------
CC = gcc
BUILD_TAREFA_A = TarefaA/Src/Algoritmos.c Geral/Src/leitura.c

MAIN_TAREFA_A =  TarefaA/Src/teste_TarefaA.c $(BUILD_TAREFA_A)
MAIN_OUT_TAREFA_A = Out/exe_tarefa_a
EXEC_MAIN_TAREFA_A = ./$(MAIN_OUT_TAREFA_A)



#---------------------------Variáveis da Tarefa B---------------------------------
CC = gcc
BUILD_TAREFA_B = TarefaB/Src/cifra.c  Geral/Src/leitura.c

MAIN_TAREFA_B = TarefaB/Src/teste_TarefaB.c  $(BUILD_TAREFA_B)
MAIN_OUT_TAREFA_B = Out/exe_tarefa_b
EXEC_MAIN_TAREFA_B = ./$(MAIN_OUT_TAREFA_B)



#---------------------------Variáveis da Main------------------------------------
CC = gcc
BUILD_MAIN = Geral/Src/leitura.c TarefaB/Src/cifra.c TarefaA/Src/Algoritmos.c Geral/Src/menu.c  

MAIN_SRC = Geral/Src/main.c $(BUILD_MAIN)
MAIN_OUT = Out/exe
EXEC_MAIN = ./$(MAIN_OUT)


#----------------------------Regras Auxiliares-----------------------------------
#vai criar a pasta Out caso ela não exista
create_out_dir:
	mkdir -p Out

#----------------------------Regras de testes------------------------------------

runA:create_out_dir
	$(CC) $(MAIN_TAREFA_A) -o $(MAIN_OUT_TAREFA_A)
	$(EXEC_MAIN_TAREFA_A)

runB:create_out_dir
	$(CC) $(MAIN_TAREFA_B) -o $(MAIN_OUT_TAREFA_B)
	$(EXEC_MAIN_TAREFA_B)


#------------------------------Rules Principais----------------------------------
compile: create_out_dir
	$(CC) $(MAIN_SRC) -o $(MAIN_OUT)

run: 
	$(EXEC_MAIN)

all: compile run

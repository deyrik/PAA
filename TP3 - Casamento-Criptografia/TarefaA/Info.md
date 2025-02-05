# Algoritmos utilizados no trabalho:

## 1. Força Bruta: 
    Esse é o algoritmo mais simples. 
    Ele compara o padrão com cada possível posição no texto de entrada, um caractere por vez, 
    até encontrar uma correspondência ou esgotar as possibilidades.

## 2. Shift-And:
    O Shift-And utiliza operações de bits para verificar padrões em textos. 
    Ele pré-processa o padrão para criar uma "máscara de bits" para cada caractere, 
    onde cada bit indica se o caractere faz parte do padrão até uma determinada posição. 
    Durante o casamento, o texto é processado caractere por caractere, 
    e uma variável de estado (um "registro de bits") mantém as posições válidas.
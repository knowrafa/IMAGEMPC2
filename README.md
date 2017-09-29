# Desenhar uma imagem seguindo os padrões para PPM ou PGM.
Trabalho de PC2

Como executar:
1- Extraia os arquivos;
2- Execute no terminal, na pasta extraída, o comando "gcc main.c Img.c";
3- Posteriormente execute ./a.out.
4- Divirta-se!

==============================================================================================================================
Como funciona o Padrão do arquivo?:

Código para executar-> IPC2 //Não executa com outro código.
Quantidade de pixels-> Linhas | Colunas
Cor do fundo->         Cor R | Cor G | Cor b
Código da figura->{
        1 - Ponto; [Posição em x] [Posição em y] [Cor R] [Cor G] [Cor B]
        Ex: 1 10 10 255 255 255

        2 - Reta;  [Posição em x1] [Posição em y1] [Posição em x2] [Posição em y2] [Cor R] [Cor G] [Cor B]
        Ex: 2 250 250 750 750 0 255 0

        3 - Quadrado Preenchido com borda; [Posição em x1] [Posição em y1] [Posição em x2] [Posição em y2] [Cor R] [Cor G] [Cor B] [Cor R borda] [Cor G borda] [Cor B borda]
        Ex: 3 250 250 750 750 240 0 255 0 255 0

        4 - Círculo com borda; [Posição do Centro em x] [Posição do Centro em y] [Cor R, G e B da borda] [Cor R, G e B do meio]
        Ex: 4 500 500 240 0 255 0 255 0 0

}
Exemplos de arquivo:

//Desenha um quadrado com uma reta no meio.
ICP2
1000 1000
0 0 0
3 250 250 750 750 240 0 255 0 0 255
2 250 250 750 750 0 255 0

//Desenha um círculo.
ICP2
1000 1000
0 0 0
4 500 500 240 0 255 0 255 0 0

at.te Rafael Alessandro e Arnold Lima

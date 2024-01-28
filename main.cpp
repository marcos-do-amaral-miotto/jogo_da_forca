// 23004163 - Tiago Morais Neto
// 23004827 - Marcos do Amaral Miotto
#include <iostream>
#include <time.h>
#include <string.h>

using namespace std;

int boas_vindas(){
    int x;
    cout << "Ol\240, seja bem vindo a forca digital :)" << endl;
    while(x < 1 || x > 3){
        cout << "Escolha o tema que deseja jogar!" << endl;
        cout << "< 1 - Marcas de Carro | 2 - Pa\641ses | 3 - Comidas >: ";
        cin >> x;
        if (x < 1 || x > 3){
            cout << "Valor incongruente, por favor digite novamente!" << endl;
        }
    }
    return x;
}

void desenha_forca(int k, int numer_letras, char Vet_erros[20], char Vet_acertos[20]){
    cout << "---------------------------------|" << endl;
    if (k == 7){
        char linha[31] = {"|                             "};
        cout << linha << endl;
        cout << linha << "       -----" << endl;
        cout << linha << "      | O O |" << endl;
        cout << linha << "      | -_- |" << endl;
        cout << linha << "       -----" << endl;
        cout << linha << "         |" << endl;
        cout << linha << "        /|\\" << endl;
        cout << linha << "       / | \\" << endl;
        cout << linha << "      /  |  \\" << endl;
        cout << linha << "        / \\" << endl;
        cout << linha << "       /   \\" << endl;
        cout << linha << "      /     \\" << endl;
    }else
    if (k == 6){
        char linha[31] = {"|                             "};
        cout << linha << " -----" << endl;
        cout << linha << "| X X |" << endl;
        cout << linha << "| ___ |" << endl;
        cout << linha << " -----" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "  /|\\" << endl;
        cout << linha << " / | \\" << endl;
        cout << linha << "/  |  \\" << endl;
        cout << linha << "  / \\" << endl;
        cout << linha << " /   \\" << endl;
        cout << linha << "/     \\" << endl;
        cout << linha << endl;
    }else
    if (k == 5){
        char linha[31] = {"|                             "};
        cout << linha << " -----" << endl;
        cout << linha << "| O O |" << endl;
        cout << linha << "| ___ |" << endl;
        cout << linha << " -----" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "   |\\" << endl;
        cout << linha << "   | \\" << endl;
        cout << linha << "   |  \\" << endl;
        cout << linha << "  / \\" << endl;
        cout << linha << " /   \\" << endl;
        cout << linha << "/     \\" << endl;
        cout << linha << endl;
    }else
    if (k == 4){
        char linha[31] = {"|                             "};
        cout << linha << " -----" << endl;
        cout << linha << "| O O |" << endl;
        cout << linha << "| ___ |" << endl;
        cout << linha << " -----" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "  / \\" << endl;
        cout << linha << " /   \\" << endl;
        cout << linha << "/     \\" << endl;
        cout << linha << endl;
    }else
    if (k == 3){
        char linha[31] = {"|                             "};
        cout << linha << " -----" << endl;
        cout << linha << "| O O |" << endl;
        cout << linha << "| ___ |" << endl;
        cout << linha << " -----" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "    \\" << endl;
        cout << linha << "     \\" << endl;
        cout << linha << "      \\" << endl;
        cout << linha << endl;
    }else
    if (k == 2){
        char linha[31] = {"|                             "};
        cout << linha << " -----" << endl;
        cout << linha << "| O O |" << endl;
        cout << linha << "| ___ |" << endl;
        cout << linha << " -----" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "   |" << endl;
        cout << linha << "   |" << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
    }else
    if (k == 1){
        char linha[31] = {"|                             "};
        cout << linha << " -----" << endl;
        cout << linha << "| O O |" << endl;
        cout << linha << "| ___ |" << endl;
        cout << linha << " -----" << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
    }else{
        char linha[31] = {"|                             "};
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
        cout << linha << endl;
    }
    cout << "------------" << endl;
    for(int i=0;i<numer_letras;i++){
        cout << " " << Vet_acertos[i] << " ";
    }
    cout << endl;
    cout << "Erros: ";
    for(int i=0;i<=6;i++){
        cout << " "<< Vet_erros[i] << " ";
    }
    cout << endl;
}

int jogada(char Palavra[], char Vet_acertos[], char Vet_erros[], int *erros, int *acertos){
    char letra;
    int val = 0;
    cout << "Digite a letra (ou digite * para sair): ";
    cin >> letra;
    letra = toupper(letra);
    if (letra == '*'){
        return 0;
    }
    for(int i=0;Palavra[i] != '\0';i++){
        if (letra == Palavra[i]){
            Vet_acertos[i] = letra;
            *acertos += 1;
            val = 1;
        }
    }
    for(int i = 0;i <= *erros;i++){
        if (letra == Vet_erros[i]){
            return 2;
        }
    }
    if(val == 0){
        Vet_erros[*erros] = letra;
        *erros+=1;
    }
    return 1;
}

int main(){
    char marcas[10][21]={"FORD", "VOLKSWAGEN", "TOYOTA", "PORSCHE", "FERRARI", "LAMBORGHINI", "CHEVROLET", "BMW", "MERCEDES", "JEEP"};
    char paises[10][21]={"URUGUAI", "ESPANHA", "TURQUIA", "NIGERIA", "HOLANDA", "NORUEGA", "HUNGRIA", "EQUADOR", "ESTONIA", "BELGICA"};
    char comidas[10][21]={"MACARRAO", "ABACAXI", "ARROZ", "FRANGO", "LASANHA", "FEIJAO", "ESTROGONOFE", "PASTEL", "COXINHA", "PIZZA"};
    int nojogo = 1;
    while(nojogo == 1){
        int jog, tema, sorter, numletras = 0, erros = 0, acertos = 0;
        char palavra[21];
        tema = boas_vindas();
        srand(time(0));
        sorter = rand();
        sorter = sorter % 10;
        if (tema == 1){
            switch (sorter){
                case 0: strcpy(palavra, marcas[0]) ;break;
                case 1: strcpy(palavra, marcas[1]) ;break;
                case 2: strcpy(palavra, marcas[2]) ;break;
                case 3: strcpy(palavra, marcas[3]) ;break;
                case 4: strcpy(palavra, marcas[4]) ;break;
                case 5: strcpy(palavra, marcas[5]) ;break;
                case 6: strcpy(palavra, marcas[6]) ;break;
                case 7: strcpy(palavra, marcas[7]) ;break;
                case 8: strcpy(palavra, marcas[8]) ;break;
                case 9: strcpy(palavra, marcas[9]) ;break;
            }
        }else
        if (tema == 2){
            switch (sorter){
                case 0: strcpy(palavra, paises[0]) ;break;
                case 1: strcpy(palavra, paises[1]) ;break;
                case 2: strcpy(palavra, paises[2]) ;break;
                case 3: strcpy(palavra, paises[3]) ;break;
                case 4: strcpy(palavra, paises[4]) ;break;
                case 5: strcpy(palavra, paises[5]) ;break;
                case 6: strcpy(palavra, paises[6]) ;break;
                case 7: strcpy(palavra, paises[7]) ;break;
                case 8: strcpy(palavra, paises[8]) ;break;
                case 9: strcpy(palavra, paises[9]) ;break;
            }
        }
        else{
            switch (sorter){
                case 0: strcpy(palavra, comidas[0]) ;break;
                case 1: strcpy(palavra, comidas[1]) ;break;
                case 2: strcpy(palavra, comidas[2]) ;break;
                case 3: strcpy(palavra, comidas[3]) ;break;
                case 4: strcpy(palavra, comidas[4]) ;break;
                case 5: strcpy(palavra, comidas[5]) ;break;
                case 6: strcpy(palavra, comidas[6]) ;break;
                case 7: strcpy(palavra, comidas[7]) ;break;
                case 8: strcpy(palavra, comidas[8]) ;break;
                case 9: strcpy(palavra, comidas[9]) ;break;
            }
        }
        for(int i=0;palavra[i]!='\0';i++){
            numletras ++;
        }
        char vetor_acertos[numletras];
        for(int i=0;i<numletras;i++){
            vetor_acertos[i] = '_';
        }
        char vetor_erros[7] = {' '};
        while (erros < 7){
            desenha_forca(erros, numletras, vetor_erros, vetor_acertos);
            if (jog == 2){
                cout << "Essa letra j\240 foi escolhida, tente outra ;)" << endl;
            }
            if (erros==6){
                cout << "Fim de jogo, voc\210 perdeu :/" << endl;
                jog = 0;
            }
            else{
                jog = jogada(palavra, vetor_acertos, vetor_erros, &erros, &acertos);
            }
            if(acertos == numletras){
                desenha_forca(7, numletras, vetor_erros, vetor_acertos);
                cout << "Voc\210 ganhou :)" << endl;
                jog = 0;
            }
            if(jog == 0){
                erros = 7;
                cout << "Deseja continuar jogando (1 - Sim / 0 - N\706o): ";
                cin >> nojogo;
            }
        }
    }
}
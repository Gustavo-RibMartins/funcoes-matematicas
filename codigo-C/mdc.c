#include <stdio.h>

int MaxDivComum (int NumInteiros, int *VetInteiros){
    int MaiorInteiro = 1;
    int MDC = 1;
    //Identifica o maior inteiro do vetor
    for(int i = 0; i < NumInteiros; i++){
        if(MaiorInteiro < VetInteiros[i]){
            MaiorInteiro = VetInteiros[i];
        }
    }
    //Calcula o MDC tal que 1 <= MDC <= MaiorInteiro
    for(int auxMDC = 1; auxMDC <= MaiorInteiro; auxMDC++){
        //percorre todo o vetor
        for(int i = 0; i < NumInteiros; i++){
            //se qualquer um dos elementos nao for divisivel por auxMDC, incrementa-lo
            if(VetInteiros[i] % auxMDC != 0){
                i = NumInteiros + 1;
            }
            //se todo o vetor for percorrido, auxMDC eh divisor de todos os elementos
            if(i == NumInteiros - 1){
                MDC = auxMDC;
            }
        }
    }
    return MDC;
}

int main() {
    //Declaracao e atribuicao da quantidade de inteiros
    int NumInteiros, MDC;
    printf("Digite a quantidade de inteiros envolvida no calculo: ");
    scanf("%d", &NumInteiros);

    //Valida se a qtde de inteiros eh valida
    if(NumInteiros < 1){
        printf("Valor invalido! Digite um valor inteiro maior que 0.\n");
        return -1;
    }

    //Declaracao e atribuicao do vetor de inteiros
    int *VetInteiros = malloc(sizeof(int) * NumInteiros);
    printf("Digite os valores de cada um dos inteiros: ");
    for(int i=0; i<NumInteiros; i++){
        scanf("%d", &VetInteiros[i]);
        // Valida se foi inserido um elemento < 1 no vetor
        if(VetInteiros[i] < 1){
            printf("Valor invalido! Digite apenas valores inteiros maiores que 0.\n");
            return -1;
        }
    }

    //Calcula MDC
    MDC = MaxDivComum(NumInteiros, VetInteiros);
    free(VetInteiros);

    printf("MDC = %d\n", MDC);

    return 0;
}

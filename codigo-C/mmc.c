#include <stdio.h>

int MinMultComum (int NumInteiros, int *VetInteiros){
    int MaiorInteiro = 1;
    int maxMMC = 1;
    int MMC = 1;
    if(NumInteiros == 1){
        return VetInteiros[0];
    }
    //Identifica o maior inteiro do vetor
    for(int i = 0; i < NumInteiros; i++){
        if(MaiorInteiro < VetInteiros[i]){
            MaiorInteiro = VetInteiros[i];
        }
    }
    //Calcula o valor maximo possivel de MMC
    for(int i = 0; i < NumInteiros; i++){
        maxMMC = maxMMC * VetInteiros[i];
    }
    MMC = maxMMC;
    //Otimizacao do MMC para o menor valor possivel
    for(int auxMMC = MaiorInteiro; auxMMC <= maxMMC; auxMMC++){
        //percorre todo o vetor
        for(int i = 0; i < NumInteiros; i++){
            //se qualquer um dos elementos nao for divisivel por auxMMC, incrementa-lo
            if(auxMMC % VetInteiros[i] != 0){
                i = NumInteiros + 1;
            }
            //se todo o vetor for percorrido, auxMDC eh divisor de todos os elementos
            if(i == NumInteiros - 1){
                MMC = auxMMC;
                auxMMC = maxMMC + 1;
            }
        }
    }
    return MMC;
}

int main() {
    //Declaracao e atribuicao da quantidade de inteiros
    int NumInteiros, MMC;
    printf("Digite a quantidade de inteiros envolvida no calculo: ");
    scanf("%d", &NumInteiros);

    //Valida se a qtde de inteiros eh valida
    if(NumInteiros < 1){
        printf("Valor invalido! Digite um valor inteiro maior que 0.\n");
        return -1;
    }

    //Declaracao e atribuicao do vetor de inteiros
    long int *VetInteiros = malloc(sizeof(long int) * NumInteiros);
    printf("Digite os valores de cada um dos inteiros: ");
    for(int i = 0; i < NumInteiros; i++){
        scanf("%d", &VetInteiros[i]);
        // Valida se foi inserido um elemento < 1 no vetor
        if(VetInteiros[i] < 1){
            printf("Valor invalido! Digite apenas valores inteiros maiores que 0.\n");
            return -1;
        }
    }

    //Calcula MMC
    MMC = MinMultComum(NumInteiros, VetInteiros);
    free(VetInteiros);
    
    printf("MMC = %d\n", MMC);
    
    return 0;
}

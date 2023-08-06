//GABRIEL ROSA - 25/06/2023 - ADS - PROF. SÉRGIO H.
//PROGRAMA QUE SIMULA OPERAÇÕES BANCÁRIAS
//DADOS DA CONTA -> CONTA CONJUNTA = 9045 ; senha_chaves >> 3042 ; senha_chiquinha >> 2071
//CONTA DE TRANSFERÊNCIA >>> 5600 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


void saque(float *Saldo01)   //FUNÇAO PARA OPERACAO DE SAQUE
{
    float valor;
   
    printf("Digite o valor do saque R$ ");
    scanf("%f", &valor);
   
    if(valor>1500) {
    printf("Valor invalido! O valor maximo de saque e R$1500 \n");
    }
   
        else if(*Saldo01<valor) {
        printf("Saldo insuficiente! Seu saldo atual e R$ %f \n", *Saldo01);
        }
       
    else {
    *Saldo01 = *Saldo01 - valor;
    printf("Saque realizado com sucesso! Seu novo saldo e de R$ %f \n", *Saldo01);
    }
       
}


void transferencia(float *Saldo01) //FUNÇÃO PARA OPERAÇÃO DE TRANSFERÊNCIA
{
    float valor;
    int conta;
   
    printf("Digite o valor da transferencia R$ ");
    scanf("%f", &valor);
   
    if(valor<0) {
    printf("Atencao! Valor invalido\n");
    }  
           
        else if(*Saldo01<valor) {
        printf("Saldo insuficiente! Seu saldo atual e R$ %f \n", *Saldo01);
        }
                   
            else {
            printf("Digite a conta de destino: ");
            scanf("%d", &conta);
           
        if (conta==5600) {
        *Saldo01 = *Saldo01 - valor;
        printf("Transferencia realizada com sucesso! Seu novo saldo e de R$ %f \n", *Saldo01);
        }
       
       
    else {
    printf("Conta invalida!");
    exit(0); }
           
    }
}  

void pagamento(float *Saldo01) //FUNÇÃO PARA OPERAÇÃO DE PAGAMENTO
{
    float valor;
   
    printf("Digite o valor do pagamento: R$ ");
    scanf("%f", &valor);
   
    if(valor > 10000) {
        printf("Atencao >>> Valor Excedido! O valor maximo de pagamento e R$10000 \n");
        }
       
        else if(*Saldo01<valor) {
        printf("Saldo insuficiente !");
        }
           
    else {
    *Saldo01 = *Saldo01 - valor;
    printf("Pagamento realizado com sucesso! Saldo atualizado ... R$ %2f \n", *Saldo01);
    }
}


int main()
{

int conta, senha, user, operacao, deposito;           // VARIAVEIS OPERACIONAIS
int  tent_conta, outra_op;                           // VARIAVEIS  USADOS COM "DO-WHILE"
float Saldo01=7000;                                 // DEFINIÇÃO DE SALDO INICIAL
int Password_chaves=3042, Password_chiquinha=2071; // VARIAVEIS PARA ATRIBUIR SENHA

printf(" --- Bem vindo ao Banco Do Brasil --- \n\n Digite o numero da conta: ");
scanf("%d", &conta);

if (conta==9045) {

printf("\n Detectamos que sua conta e conjunta ... Qual usuario ira acessar? 1 - CHAVES // 2 - CHIQUINHA >>>  "); // 2 USUARIOS COM SENHA PRE-DEFINIDAS
scanf("%d", &user);

do
{  // INICIO DO LACO QUE VALIDA A SENHA E USUARIO

if (user == 1 || user == 2) {
printf(" Digite a senha: ");
scanf("%d", &senha);
}

else {
printf(" Usuario invalido! Encerrando o programa por questoes de seguranca...");
exit(0);
}

    if(user == 1 && senha == Password_chaves || user == 2 && senha == Password_chiquinha)
    printf("\n ***Acesso permitido***");
   
    else{
    printf(" Acesso negado! Tentar novamente? 1-sim ou 2-nao >>> ");
    scanf("%d", &tent_conta);
    }

}while(tent_conta==1); // FIM DO LACO QUE VALIDA A SENHA E USUARIO

if (tent_conta==2) {   // LAÇO PARA FECHAR O PROGRAMA EM CASO DE DESISTENCIA POR ERRO DE SENHA
printf("Obrigado por utilizar nossos serviços! ");
exit(0);
}

else {

do
{
    printf("\n\nQual operacao deseja realizar ?");
    printf("\n1) Saque");
    printf("\n2) Saldo");
    printf("\n3) Transferencia");
    printf("\n4) Deposito");
    printf("\n5) Pagamento");
    printf("\n6) Ajuda");
    printf("\n7) Creditos da empresa");
    printf("\n8) Sair");
    printf("\n9) ??? ");
    printf("\n\nOpcao: ");
    scanf("%d", &operacao);

switch(operacao) // MENU DE OPCOES CONFORME SOLICITADO NO T2K
{
case 1: // OPERACAO DE SAQUE
    saque(&Saldo01);
    getch();
            break;

case 2: // OPERACAO PARA VER SALDO
printf("Saldo total = R$ %f", Saldo01);
break;

case 3: // OPERACAO PARA REALIZAR TRANSFERÊNCIA  
   transferencia(&Saldo01);
   getch();
            break;

case 4: // OPERACAO DE DEPOSITO
printf("Digite o valor do deposito >>> R$ ");
scanf("%d", &deposito);
Saldo01 = Saldo01 + deposito;
printf("Saldo atual = R$ %f ", Saldo01);
break;

case 5: // OPERACAO DE PAGAMENTO
   pagamento(&Saldo01);
            getch();
            break;

case 6: // MENU DE AJUDA COM DADOS REAIS
printf("\nSAC 0800 729 0722 \nOUVIDORIA BB 0800 729 0088 \nDEFICIENTE AUDITIVO OU DE FALA 0800 729 0088 \nWHATS APP (51) 4004 0001 \nFIXO 4004 0001");
break;

/*case 7: // CREDITOS DA EMPRESA
printf(" \nBanco do Brasil (BB) é um banco brasileiro, constituído na forma de sociedade de economia mista, com participação do Governo Federal do Brasil em 50% das ações");
printf(" \nSede: Braslia");
printf(" \nFundador(es): Joao VI de Portugal");
printf(" \nEmpregados: 84.597");
printf(" \nPreco das açoes: BBAS3.SA (Sao Paulo) R$50,20 -0,94 (-1,84%)");
break;*/

case 8: // MENU DE SAIDA
printf("Obrigado por usar nossos servicos!");
break;

case 9: // EASTER EGG
printf("* Salmos 121 *");
printf("\n 1. Elevo os meus olhos para os montes: de onde me vira o socorro?");
printf("\n  2. O meu socorro vem do Senhor, que fez o ceu e a terra. ");
printf("\n   3. Não deixara vacilar o teu pe: aquele que te guarda não tosquenejara. ");
printf("\n    4. Eis que nao tosquenejara nem dormira o guarda de Israel. ");
printf("\n     5. O Senhor e quem te guarda: o Senhor e a tua sombra a tua direita. ");
printf("\n   6. O sol nao te molestara de dia nem a lua de noite. ");
printf("\n   7. O Senhor te guardara de todo o mal: ele gurdara a tua alma. ");
printf("\n    8. O Senhor guardara a tua entrada e a tua saida, desde agora e para sempre. ");
printf("\n\n  DEUS ABENCOE SUA VIDA! ");
break;

}
printf("\n\n\tDeseja realizar outra operacao?  1 - SIM  //  2 - NAO >>> "); // OPCAO PARA O USUARIO REALIZAR OUTRA OPERACAO SEM TER QUE EXECUTAR O PROGRAMA VARIAS VEZES
scanf("%d", &outra_op);

}while(outra_op==1);

printf("\n Obrigado por usar os nossos servicos... Deslogando\n");
        FILE *arquivo = fopen("Saldo.txt", "w");
       
        if (arquivo != NULL) {
        fprintf(arquivo, "%f", Saldo01);
        fclose(arquivo);
        }
        exit(0);

return 0;
}
}
   else {
   printf("Conta invalida! Encerrando o programa por questoes de seguranca...");
   exit(0);
   }
       
}

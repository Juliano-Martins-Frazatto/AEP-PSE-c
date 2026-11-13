#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

typedef struct{
	int codigo, qntdPrevista, qntdParticipantes;
	char escola[50], tema[50], dataPrevista[50], publicoAlvo[50], responsavel[50], situacao[50];	
}cadastroAcao;

int contagem = 0;

cadastroAcao acao[100];

int menu(void){
	int escolha;
	do{
		system("cls");
		printf(" ------------------------------PSE em Acao-----------------------------\n");
		printf("|                                                                      |\n");
		printf(" ------------------------------Integra PSE-----------------------------\n\n");
		
		printf(" ========= Sistema de Planejamento e Acompanhamento de Acoes =========\n");
		printf("|  [1] - Cadastrar Acoes                                               |\n");
		printf("|  [2] - Listar Acoes                                                  |\n");
		printf("|  [3] - Pesquisar Acoes                                               |\n");
		printf("|  [4] - Atualizar situacao de Acoes                                   |\n");
		printf("|  [5] - Registrar quantidade de participantes                         |\n");
		printf("|  [6] - Gerar Resumo Geral                                            |\n");
		printf("|  [7] - Sair                                                          |\n");
		printf(" =====================================================================\n\n");
		printf("--> Digite uma opcao: ");
		scanf("%i", &escolha);
		getchar();
		
		if (escolha == 7){
			printf("Saindo...");
		}
		
	}while(escolha<1 || escolha >7);
	
	return escolha;
}

bool validaEntradaSomenteLetras(char texto[50]){
	bool temNumero = false;
	for (int i=0; i<50; i++){
		switch(texto[i]){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':	
			case '9':
				temNumero = true;
				break;
		}
	}
	return temNumero;
}

void cadastroDeAcoes(void){
	int escolha, escolhaTema, novoCodigo;
	char continua;
	bool codigoValido;
			 
	for (int i = contagem; i < 100; i++){
		printf("\n ----------------------------------------------------------------------\n");
		printf("|                            Cadastro de Acoes                         |\n");
		printf(" ----------------------------------------------------------------------\n\n");
		
		do {
			codigoValido = true;
			printf("Codigo: ");
			scanf("%i", &novoCodigo);
			getchar();
			
			for (int j = 0; j < i; j++) {
				if (acao[j].codigo == novoCodigo) {
					printf("Codigo ja cadastrado, informe outro.\n");
					codigoValido = false;
					break;
				}
			}
		} while (!codigoValido);
		acao[i].codigo = novoCodigo;
		
		while(true){
			printf("\nEscola (Use apenas letras): ");
			fgets(acao[i].escola, 50, stdin);
			acao[i].escola[strcspn(acao[i].escola, "\n")] = '\0';
			
			if (strlen(acao[i].escola) == 0) {
				printf("Preencha o campo obrigatorio.\n");
				continue;
			}
			if (validaEntradaSomenteLetras(acao[i].escola) == true){
				printf("Digite apenas letras.\n");
				continue;
			}else{
				break;
			}
		}					
		
		while (true){
			printf("\n===Temas disponiveis:\n");
			printf("1.Saude Ambiental\n");
			printf("2.Promocao da atividade fisica\n");
			printf("3.Alimentacao saudavel e prevencao da obesidade\n");
			printf("4.Promocao da cultura de paz e direitos humanos\n");
			printf("5.Prevencao das violencias e dos acidentes\n");
			printf("6.Prevencao de doencas negligenciadas\n");
			printf("7.Verificacao da situacao vacinal\n");
			printf("8.Saude sexual e reprodutiva e prevencao do HIV/IST\n");
			printf("9.Prevencao ao uso de alcool, tabaco, e outras drogas\n");
			printf("10.Saude bucal\n");
			printf("11.Saude auditiva\n");
			printf("12.Saude ocular\n");
			printf("13.Prevencao a Covid19\n");
			printf("14.Promocao da Saude Mental\n\n");
			printf("Digite o numero referente a opcao desejada: ");
			scanf("%i", &escolhaTema);	
			getchar();
			
			if(escolhaTema <= 0 || escolhaTema > 14){
				printf("\n******Digite uma opcao valida (1 a  14)******\n");
				printf("Tente novamente.\n");
				Sleep(3000);
				system("cls");
				continue;
			}else{
				break;
			}
		}
			
		switch(escolhaTema){
			case 1: strcpy(acao[i].tema, "Saude Ambiental"); break;
			case 2: strcpy(acao[i].tema, "Promocao da atividade fisica"); break;
			case 3: strcpy(acao[i].tema, "Alimentacao saudavel e prevencao da obesidade"); break;
			case 4: strcpy(acao[i].tema, "Promocao da cultura de paz e direitos humanos"); break;
			case 5: strcpy(acao[i].tema, "Prevencao das violencias e dos acidentes"); break;
			case 6: strcpy(acao[i].tema, "Prevencao de doencas negligenciadas"); break;
			case 7: strcpy(acao[i].tema, "Verificacao da situacao vacinal"); break;
			case 8: strcpy(acao[i].tema, "Saude sexual e reprodutiva e prevencao do HIV/IST"); break;
			case 9: strcpy(acao[i].tema, "Prevencao ao uso de alcool, tabaco, e outras drogas"); break;
			case 10: strcpy(acao[i].tema, "Saude bucal"); break;
			case 11: strcpy(acao[i].tema, "Saude auditiva"); break;
			case 12: strcpy(acao[i].tema, "Saude ocular"); break;
			case 13: strcpy(acao[i].tema, "Prevencao a Covid19"); break;
			case 14: strcpy(acao[i].tema, "Promocao da Saude Mental"); break;					
		}
		
		do {
			printf("Data Prevista: ");
			fgets(acao[i].dataPrevista, 50, stdin);
			acao[i].dataPrevista[strcspn(acao[i].dataPrevista, "\n")] = '\0';
			if (strlen(acao[i].dataPrevista) == 0) printf("Preencha o campo obrigatorio.\n");
		} while(strlen(acao[i].dataPrevista) == 0);
		
		do {
			printf("Publico-alvo: ");
			fgets(acao[i].publicoAlvo, 50, stdin);
			acao[i].publicoAlvo[strcspn(acao[i].publicoAlvo, "\n")] = '\0';
			if (strlen(acao[i].publicoAlvo) == 0) printf("Preencha o campo obrigatorio.\n");
		} while(strlen(acao[i].publicoAlvo) == 0);
		
		do {
			printf("Responsavel: ");
			fgets(acao[i].responsavel, 50, stdin);
			acao[i].responsavel[strcspn(acao[i].responsavel, "\n")] = '\0';
			if (strlen(acao[i].responsavel) == 0) printf("Preencha o campo obrigatorio.\n");
		} while (strlen(acao[i].responsavel) == 0);
		
		do{
			printf("Quantidade prevista: ");
			scanf("%i", &acao[i].qntdPrevista);	
			getchar();
			if(acao[i].qntdPrevista < 0) {
				printf("Quantidade invalida, informe novo valor.\n");
			}
		} while(acao[i].qntdPrevista < 0 || acao[i].qntdPrevista > 100000);
		
		do {
			printf("===Situacao inicial: \n");
			printf("1. Planejada\n");
			printf("2. Realizada\n");
			printf("3. Cancelada\n\n");
			printf("Digite o numero referente a opcao desejada: ");
			scanf("%i", &escolha);
			getchar();
			if(escolha < 1 || escolha > 3){
			    printf("Opcao invalida. Informe 1, 2 ou 3.\n");
			}
		} while(escolha < 1 || escolha > 3);
		
		switch(escolha){
			case 1: strcpy(acao[i].situacao, "planejada"); break;
			case 2: strcpy(acao[i].situacao, "realizada"); break;
			case 3: strcpy(acao[i].situacao, "cancelada"); break;
		}	
		
		acao[i].qntdParticipantes = 0;
		
		printf(" --------------------------------------------\n");
		printf("|           Informacoes Registradas:         |\n");
		printf(" --------------------------------------------\n");
		printf("+ Acao: %i\n", acao[i].codigo);
		printf("+ Escola: %s\n", acao[i].escola);
		printf("+ Tema: %s\n", acao[i].tema);
		printf("+ Data Prevista: %s\n ", acao[i].dataPrevista);
		printf("+ Publico Alvo: %s\n", acao[i].publicoAlvo);
		printf("+ Responsavel: %s\n", acao[i].responsavel);
		printf("+ Quantidade Prevista: %i\n", acao[i].qntdPrevista);
		printf("+ Situacao: %s\n", acao[i].situacao);
		printf(" --------------------------------------------\n\n");
			
		contagem = contagem + 1;
		
		printf("----------------------------------------------------------------------\n\n\n");
		if (contagem == 100){
			printf("Limite de cadastros atingidos!\n");
			printf("Retornando ao menu...\n");
			Sleep(2000);
			break;
		}else{
			printf("Deseja cadastrar outra acao? [s-->Sim | n-->Nao]\n");
			printf("Escolha uma opcao (s / n ): \n");
			scanf(" %c", &continua);
			getchar();
			if (continua == 's'){
				printf("Continuando...\n");
				continue;
			} else if (continua == 'n'){
				printf("Voltando ao menu...");
				Sleep(1000);
				break;			 
			}
		}	
	}
}

void listagemAcoes(void){
	int voltarMenu;
	do{
		printf("\n ----------------------------------------------------------------------\n");
		printf("|                            Listagem de Acoes                         |\n");
		printf(" ----------------------------------------------------------------------\n\n");	
		
		if (contagem == 0){
			printf("Nao ha acoes para listar.\n");
		}else{
			for (int i = 0; i<contagem; i++){
				printf(" --------------------------------------------\n");
				printf("|                  Acao %i                   |\n", acao[i].codigo);
				printf(" --------------------------------------------\n");
				printf(" Acao: %i\n", acao[i].codigo);
				printf(" Escola: %s\n", acao[i].escola);
				printf(" Tema: %s\n", acao[i].tema);
				printf(" Data Prevista: %s\n", acao[i].dataPrevista);
				printf(" Publico Alvo: %s\n", acao[i].publicoAlvo);
				printf(" Responsavel: %s\n", acao[i].responsavel);
				printf(" Quantidade Prevista: %i\n", acao[i].qntdPrevista);
				printf(" Quantidade Participantes: %i\n", acao[i].qntdParticipantes);
				printf(" Situacao: %s\n", acao[i].situacao);
				printf(" --------------------------------------------\n\n");	
			}
		}
		
		printf("Digite 0 para voltar ao menu: \n");
		scanf("%i", &voltarMenu);
		getchar();
	}while(voltarMenu != 0);
}

void pesquisaAcoes(void){
	int pesquisaCodigo, escolha;
	char continua;
	if(contagem == 0){
		printf("Nao ha acoes para pesquisar. Voltando ao Menu.");
		Sleep(2000);
	}else{
		while(true){
			do{
				printf("\n ----------------------------------------------------------------------\n");
				printf("|                           Pesquisa de Acoes                          |\n");
				printf(" ----------------------------------------------------------------------\n\n");
				printf(" =====================================================================\n");
				printf("|  [1] - Pesquisar por codigo                                          |\n");
				printf("|  [2] - Pesquisar por escola                                          |\n");
				printf("|  [3] - Pesquisar por tema                                            |\n");
				printf("|  [4] - Voltar ao menu inicial                                        |\n");
				printf(" =====================================================================\n\n");
				printf("--> Digite uma opcao: ");
				scanf("%i", &escolha);
				getchar();
			}while(escolha < 1 || escolha > 4);
			
			if (escolha == 4){
				printf("Saindo...\n");
				Sleep(1000);
				break;
			} else {
				switch(escolha){
					case 1:
						while(true){
							printf("Digite o codigo da acao que deseja pesquisar: ");
							scanf("%i", &pesquisaCodigo);
							getchar();
							
							int indiceEncontrado = -1;
							for(int j = 0; j < contagem; j++){
								if(acao[j].codigo == pesquisaCodigo){
									indiceEncontrado = j;
									break;
								}
							}
							
							if(indiceEncontrado != -1){
								printf(" --------------------------------------------\n");
								printf("|                  Acao %i                   |\n", pesquisaCodigo);
								printf(" --------------------------------------------\n");
								printf(" Acao: %i\n", acao[indiceEncontrado].codigo);
								printf(" Escola: %s\n", acao[indiceEncontrado].escola);
								printf(" Tema: %s\n", acao[indiceEncontrado].tema);
								printf(" Data Prevista: %s\n", acao[indiceEncontrado].dataPrevista);
								printf(" Publico Alvo: %s\n", acao[indiceEncontrado].publicoAlvo);
								printf(" Responsavel: %s\n", acao[indiceEncontrado].responsavel);
								printf(" Quantidade Prevista: %i\n", acao[indiceEncontrado].qntdPrevista);
								printf(" Situacao: %s\n", acao[indiceEncontrado].situacao);
								printf(" --------------------------------------------\n\n");
							}else{
								printf("\n******Acao nao encontrada!******\n");
							}
							
							printf("Deseja fazer outra pesquisa? s (Sim) n (Nao - volta p/ menu): ");
							scanf("%c", &continua);
							getchar();
							if(continua == 's'){
								continue;
							}else if (continua == 'n'){
								printf("Saindo...\n");
								Sleep(1000);
								break;
							}
						}
						break;
						
					case 2: {
						char escolaEscolhida[50];
						printf("Escolas cadastradas: \n");
						
						for (int i=0; i<contagem; i++){
							int repete = 0;
							for(int j=0; j<i; j++){
								if(strcmp(acao[i].escola, acao[j].escola) == 0){
									repete = 1;
									break;
								} 		
							}
							if(repete == 0){
								printf("-%s\n", acao[i].escola);
							}
						}
					
						while(true){
							printf("Digite o nome referente a escola escolhida: \n");
							fgets(escolaEscolhida, 50, stdin);
							escolaEscolhida[strcspn(escolaEscolhida, "\n")] = '\0'; 
							
							bool encontrou = false;
							for (int i=0; i<contagem; i++){
								if (strcmp(escolaEscolhida, acao[i].escola) == 0){
									encontrou = true;
									printf(" -----------------------------------------------\n");
									printf(" Acao: %i\n", acao[i].codigo);
									printf(" Escola: %s\n", acao[i].escola);
									printf(" Tema: %s\n", acao[i].tema);
									printf(" Data Prevista: %s\n", acao[i].dataPrevista);
									printf(" Publico Alvo: %s\n", acao[i].publicoAlvo);
									printf(" Responsavel: %s\n", acao[i].responsavel);
									printf(" Quantidade Prevista: %i\n", acao[i].qntdPrevista);
									printf(" Situacao: %s\n", acao[i].situacao);
									printf(" --------------------------------------------\n\n");
								}
							}
							if(!encontrou){
								printf("Escola nao encontrada. Verifique se digitou o nome corretamente.\n");
							}
							
							printf("Deseja fazer outra pesquisa? s (Sim) n (Nao - volta p/ menu): ");
							scanf("%c", &continua);
							getchar();
							
							if(continua == 's'){
								continue;
							}else if (continua == 'n'){
								printf("Saindo...\n");
								Sleep(1000);
								break;
							}	
						}
						break;
					}
						
					case 3:
						char temaEscolhido[50];
						printf("Temas cadastrados: \n");
						
						for (int i=0; i<contagem; i++){
							int repete = 0;
							for(int j=0; j<i; j++){
								if(strcmp(acao[i].tema, acao[j].tema) == 0){
									repete = 1;
									break;
								} 		
							}
							if(repete == 0){
								printf("-%s\n", acao[i].tema);
							}
						}
					
						while(true){
							printf("Digite o nome referente ao tema escolhido: \n");
							fgets(temaEscolhido, 50, stdin);
							temaEscolhido[strcspn(temaEscolhido, "\n")] = '\0'; 
							
							bool encontrou = false;
							for (int i=0; i<contagem; i++){
								if (strcmp(temaEscolhido, acao[i].tema) == 0){
									encontrou = true;
									printf(" -----------------------------------------------\n");
									printf(" Acao: %i\n", acao[i].codigo);
									printf(" Escola: %s\n", acao[i].escola);
									printf(" Tema: %s\n", acao[i].tema);
									printf(" Data Prevista: %s\n", acao[i].dataPrevista);
									printf(" Publico Alvo: %s\n", acao[i].publicoAlvo);
									printf(" Responsavel: %s\n", acao[i].responsavel);
									printf(" Quantidade Prevista: %i\n", acao[i].qntdPrevista);
									printf(" Situacao: %s\n", acao[i].situacao);
									printf(" --------------------------------------------\n\n");
								}
							}
							if(!encontrou){
								printf("Tema nao encontrado. Verifique se digitou corretamente.\n");
							}
							
							printf("Deseja fazer outra pesquisa? s (Sim) | n (Nao - volta p/ menu): ");
							scanf("%c", &continua);
							getchar();
							
							if(continua == 's'){
								continue;
							}else if (continua == 'n'){
								printf("Saindo...\n");
								Sleep(1000);
								break;
							}
						}
				}
			}
		}
	}
}

void atualizarSituacaoAcao(void){
	int codigoAcao, qntdEfetiva, escolha;
	char continua, novaSituacao[50];
	if(contagem == 0){
		printf("Nao ha acoes cadastradas. Cadastre ao menos uma acao para poder atualizar a situacao da mesma.\n\n");
		printf("Voltando para o Menu...");
		Sleep(3000);
	}else{
		printf("Opcao escolhida --> Atualizar situacao de Acoes\n");
		printf("\n ----------------------------------------------------------------------\n");
		printf("|                      Atualizar situacao de Acoes                     |\n");
		printf(" ----------------------------------------------------------------------\n\n");
		
		while(true){
			printf("Digite o codigo da acao: ");
			scanf("%i", &codigoAcao);
			getchar();
			
			int indice = -1;
			for(int j = 0; j < contagem; j++){
				if(acao[j].codigo == codigoAcao){
					indice = j;
					break;
				}
			}
			
			if(indice == -1){
				printf("Acao nao encontrada!\n");
			} else {
				printf(" -----------------------------------------------\n");
				printf(" Acao: %i\n", acao[indice].codigo);
				printf(" Escola: %s\n", acao[indice].escola);
				printf(" Tema: %s\n", acao[indice].tema);
				printf(" Data Prevista: %s\n", acao[indice].dataPrevista);
				printf(" Publico Alvo: %s\n", acao[indice].publicoAlvo);
				printf(" Responsavel: %s\n", acao[indice].responsavel);
				printf(" Quantidade Prevista: %i\n", acao[indice].qntdPrevista);
				printf(" Situacao: %s\n", acao[indice].situacao);
				printf(" --------------------------------------------\n\n");
				
				do {
					printf("Digite qual a nova situacao: \n");
					printf("1. Planejada\n");
					printf("2. Realizada\n");
					printf("3. Cancelada\n");
					printf("Digite o numero referente a opcao desejada: ");
					scanf("%i", &escolha);
					getchar();
					if(escolha < 1 || escolha > 3){
					    printf("Opcao invalida. Informe 1, 2 ou 3.\n");
					}
				} while (escolha < 1 || escolha > 3);
				
				switch(escolha){
					case 1: strcpy(novaSituacao, "planejada"); strcpy(acao[indice].situacao, novaSituacao); break;
					case 2: strcpy(novaSituacao, "realizada"); strcpy(acao[indice].situacao, novaSituacao); break;
					case 3: strcpy(novaSituacao, "cancelada"); strcpy(acao[indice].situacao, novaSituacao); break;
				}	
				
				if (strcmp(novaSituacao, "realizada") == 0){
					do {
						printf("Para registrar a situacao como realizada e necessario informar a quantidade de participantes efetivos: ");
						scanf("%i", &qntdEfetiva);
						getchar();
						if(qntdEfetiva < 0) printf("Quantidade invalida, informe um valor positivo.\n");
					} while (qntdEfetiva < 0);
					acao[indice].qntdParticipantes = qntdEfetiva;
					printf("Alteracao realizada com sucesso!\n");
				} else {
					printf("Alteracao realizada com sucesso!\n");
				}
				
				printf(" -----------------------------------------------\n");
				printf(" Acao: %i\n", acao[indice].codigo);
				printf(" Escola: %s\n", acao[indice].escola);
				printf(" Tema: %s\n", acao[indice].tema);
				printf(" Data Prevista: %s\n", acao[indice].dataPrevista);
				printf(" Publico Alvo: %s\n", acao[indice].publicoAlvo);
				printf(" Responsavel: %s\n", acao[indice].responsavel);
				printf(" Quantidade Prevista: %i\n", acao[indice].qntdPrevista);
				printf(" Quantidade Participantes: %i\n", acao[indice].qntdParticipantes);
				printf(" Situacao: %s\n", acao[indice].situacao);
				printf(" --------------------------------------------\n\n");
			}
			
			printf("Deseja fazer outra alteracao? s (Sim) | n (Nao - volta p/ menu): ");
			scanf("%c", &continua);
			getchar();
			
			if(continua == 's'){
				continue;
			}else if (continua == 'n'){
				printf("Saindo...\n");
				Sleep(1000);
				break;
			}
		}
	}
}

void registrarQntdParticipantes(void){
	char continua;
	int codigoAcao, participantes;
	if(contagem == 0){
		printf("Nao ha acoes cadastradas. Cadastre ao menos uma acao para poder registrar a quantidade de participantes.\n\n");
		printf("Voltando para o Menu...");
		Sleep(3000);
	}else{
		while(true){
			printf("\n ----------------------------------------------------------------------\n");
			printf("|                 Resgistrar Quantidade de Participantes               |\n");
			printf(" ----------------------------------------------------------------------\n\n");
			
			printf("Digite o codigo da acao em que deseja registrar a quantidade de participantes: ");
			scanf("%i", &codigoAcao);
			getchar();
	
			bool encontrou = false;
			for (int i=0; i<contagem; i++){
				if(codigoAcao == acao[i].codigo){
					encontrou = true;
					printf("#Codigo: %i\n", acao[i].codigo);
					do {
						printf("Digite a quantidade de participantes: ");
						scanf("%i", &participantes);
						getchar();
						if (participantes < 0) printf("Quantidade invalida, insira valor positivo.\n");
					} while (participantes < 0);
					acao[i].qntdParticipantes = participantes;
					
					printf(" --------------------------------------------\n");
					printf("|           Informacoes Registradas:         |\n");
					printf(" --------------------------------------------\n");
					printf("+ Quantidade Participantes: %i\n", acao[i].qntdParticipantes);
					printf(" --------------------------------------------\n\n");
					break;
				}
			}
			if(!encontrou){
				printf("Acao nao encontrada!\n");
			}
			
			printf("Deseja continuar a cadastrar participantes em outra acao? [s-->Sim | n-->Nao]\n");
			printf("Escolha uma opcao (s / n ): \n");
			scanf(" %c", &continua);
			getchar();
			if (continua == 's'){
				printf("Continuando...\n");
				continue;
			} else if (continua == 'n'){
				printf("Voltando ao menu...");
				Sleep(1000);
				break;
			}
		}
	}
}

void gerarResumoGeral(void){
	int contadorPlanejada, contadorRealizada, contadorCancelada, voltarMenu;
	float somaPrevisaoParticipantes, percentualParticipantes, somaParticipantes;
	
	if(contagem == 0){
		printf("Nao ha acoes cadastradas. Cadastre ao menos uma acao para poder gerar o resumo geral.\n\n");
		printf("Voltando para o Menu...");
		Sleep(3000);
	}else{
		contadorPlanejada = 0;
		contadorRealizada = 0;
		contadorCancelada = 0;
		somaParticipantes = 0;
		somaPrevisaoParticipantes = 0;
		
		printf("\n ----------------------------------------------------------------------\n");
		printf("|                            Resumo Geral                              |\n");
		printf(" ----------------------------------------------------------------------\n");
		
		for (int i=0; i<contagem; i++){
			if (strcmp(acao[i].situacao, "planejada") == 0){
				contadorPlanejada = contadorPlanejada + 1;
			}
			if (strcmp(acao[i].situacao, "realizada") == 0){
				contadorRealizada = contadorRealizada + 1;
			}
			if (strcmp(acao[i].situacao, "cancelada") == 0){
				contadorCancelada = contadorCancelada + 1;
			}
			somaParticipantes = somaParticipantes + acao[i].qntdParticipantes; 
			somaPrevisaoParticipantes = somaPrevisaoParticipantes + acao[i].qntdPrevista; 
		}
		
		if (somaPrevisaoParticipantes == 0 ){ 
			percentualParticipantes = 0;
		}else{
			percentualParticipantes = (somaParticipantes / somaPrevisaoParticipantes) * 100;
		}
		
		printf(" Acoes Planejadas: %i\n", contadorPlanejada);
		printf(" Acoes Realizadas: %i\n", contadorRealizada);
		printf(" Acoes Canceladas: %i\n", contadorCancelada); 
		printf("Total de participantes: %.0f\n", somaParticipantes);
		printf("Participantes previstos: %.0f\n", somaPrevisaoParticipantes);
		printf("Percentual de participantes em relacao ao previsto: %.2f%%\n", percentualParticipantes);
		printf(" ----------------------------------------------------------------------\n\n");
		
		do{
			printf("\nDigite 0 para voltar ao menu: \n");
			scanf("%i", &voltarMenu);
			
			if (voltarMenu == 0){
				continue;
			}
		}while(voltarMenu != 0);
	}
}

int main(){
    setlocale(LC_ALL, "Portuguese");
	int escolhaMenu;
	escolhaMenu = menu(); 
	
	while(escolhaMenu != 7){
		switch (escolhaMenu){
			case 1: cadastroDeAcoes(); break;
			case 2: listagemAcoes(); break;
			case 3: pesquisaAcoes(); break;
			case 4: atualizarSituacaoAcao(); break;
			case 5: registrarQntdParticipantes(); break;
			case 6: gerarResumoGeral(); break;
		}
		escolhaMenu = menu();
	}
	return 0;
}

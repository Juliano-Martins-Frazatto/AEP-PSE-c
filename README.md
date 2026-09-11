#  PSE em Ação — Sistema de Gestão Intersetorial (PSE)

> Sistema em C para planejar, registrar e acompanhar as ações coletivas do Programa Saúde na Escola (PSE).

---

## 📌 Sobre o Projeto

O **PSE em Ação** é um projeto criado para a nossa Atividade Estruturada Prática (AEP). O objetivo é gerenciar as ações de saúde e educação promovidas pelo **Programa Saúde na Escola (PSE)** do município.

A ideia é ajudar a equipe gestora (**IntegraPSE**) a sair dos controles manuais e papéis dispersos, unificando tudo em um sistema via terminal. Com o software, fica mais fácil acompanhar as atividades nas escolas públicas e gerar métricas (como total de alunos atendidos), focando em ser prático no dia a dia e respeitando totalmente a privacidade dos estudantes.

---

## 👥 Integrantes

* **Arthur**
* **Juliano**
* **Luiz**

---

## 🚀 Funcionalidades (Requisitos)

- [x] **UC01 / RF01 — Cadastrar Ação:** Salva as atividades com um código único, tema do PSE, escola, data, público-alvo e estimativa de participantes.
- [x] **UC02 / RF02 — Listar Ações:** Mostra na tela todas as atividades cadastradas.
- [x] **UC03 / RF03 — Pesquisar e Filtrar:** Busca rápida de ações por código, nome da escola ou tema.
- [x] **UC04 / RF04 — Atualizar Status:** Muda a situação de uma ação (Planejada, Em Andamento, Concluída, Cancelada).
- [x] **UC05 / RF05 — Remover Ação:** Apaga registros do sistema (com aviso de confirmação).
- [x] **UC06 / RF06 — Resumo e Métricas:** Mostra os números finais de escolas e alunos atendidos, além de um balanço dos status das ações.

---

## 🛠️ Tecnologias e Conceitos Aplicados

* **Linguagem C:** Programação estruturada, alocação de memória, modularização (funções) e uso de `structs` e vetores.
* **Engenharia de Software:** Levantamento de Requisitos (RF/RNF), Casos de Uso, Fluxogramas e organização ágil (Sprints/Kanban).
* **Git & GitHub:** Versionamento de código e desenvolvimento em equipe.

---

## 📁 Estrutura do Repositório

```text
├── documentacao/
│   └── AEP_Etapa1_Documento_Escrito.pdf   # Documento técnico e teórico da 1ª Entrega
├── src/                                   # Código-fonte em C (Etapa 2)
│   └── main.c
└── README.md                              # Apresentação e documentação do repositório

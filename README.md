#  PSE em Ação — Sistema de Gestão Intersetorial (PSE)

> Sistema em C para planejar, registrar e acompanhar as ações coletivas do Programa Saúde na Escola (PSE).

---

## 📌 Sobre o Projeto

O **PSE em Ação** é um projeto criado para a nossa Atividade Estruturada Prática (AEP) - 2º Semestre. O objetivo é gerenciar as ações de saúde e educação promovidas pelo **Programa Saúde na Escola (PSE)** do município.

A ideia é ajudar a equipe gestora (**IntegraPSE**) a sair dos controles manuais e papéis dispersos, unificando tudo em um sistema via terminal. Com o software, fica mais fácil acompanhar as atividades nas escolas públicas e gerar métricas de participação, focando em ser prático no dia a dia, utilizando dados fictícios coletivos e respeitando totalmente a privacidade dos estudantes.

---

## 👥 Integrantes

* **Juliano Martins Frazatto Filho**
* **Arthur Pedreira Perussulo**

---

## 🚀 Funcionalidades (Casos de Uso)

- [x] **UC01 / RF01 — Cadastrar Ação:** Salva as atividades com um código único, tema do PSE (entre 14 opções), escola, data, público-alvo, responsável e estimativa de participantes.
- [x] **UC02 / RF02 — Listar Ações:** Mostra na tela todas as atividades cadastradas.
- [x] **UC03 / RF03 — Pesquisar Ação:** Busca rápida de ações por código, ou seleção a partir de nomes de escolas e temas já cadastrados.
- [x] **UC04 / RF04 — Atualizar Situação:** Muda o status inicial de uma ação (Planejada, Realizada ou Cancelada).
- [x] **UC05 / RF05 — Registrar Participantes:** Adiciona a quantidade efetiva de participantes quando uma ação é marcada como "Realizada".
- [x] **UC06 / RF06 — Resumo e Métricas:** Gera um balanço consolidado de ações por situação, total de participantes e o percentual de engajamento em relação ao previsto inicial.

---

## 🛠️ Tecnologias e Conceitos Aplicados

* **Linguagem C:** Programação estruturada, laços de repetição, validações de entrada, modularização (funções) e uso de `structs` e vetores armazenados em memória.
* **Engenharia de Software:** Levantamento de Requisitos (RF/RNF), Diagrama e Descrição de Casos de Uso, Fluxogramas, Casos de Teste e organização ágil.
* **Git & GitHub:** Versionamento de código e desenvolvimento em equipe.

---

## 📁 Estrutura do Repositório

```text
├── documentacao/
│   ├── AEP_Etapa1_Planejamento.pdf          # Documento de levantamento, requisitos e fluxogramas da 1ª Entrega
│   └── AEP_Etapa2_Documentacao_Final.pdf    # Documento técnico final com Casos de Uso, Testes e Manual do Usuário
├── src/                                     
│   └── main.c                               # Código-fonte funcional em C (Etapa 2)
└── README.md                                # Apresentação e documentação do repositório
```

---

## 🎥 Apresentação do Projeto

* **Vídeo Demonstrativo:** [] - Duração de até 7 minutos detalhando a lógica do sistema e o projeto rodando no terminal.

## ✈️ Sistema de Gerenciamento de Aeronaves e Rotas

## 📌 Descrição

Sistema desenvolvido em **linguagem C** para gerenciamento de aeronaves e rotas aéreas, utilizando **listas encadeadas dinâmicas** como estrutura de dados principal e **persistência em arquivos binários**.

O projeto foi desenvolvido como parte da disciplina **Linguagem de Programação I – DEC0012**, do curso de Engenharia de Computação.

---

## 🎯 Objetivos do Projeto

* Substituir estruturas baseadas em vetores por **listas encadeadas**
* Eliminar o uso de variáveis globais
* Implementar **persistência de dados em arquivos binários**
* Gerar relatórios em múltiplos formatos
* Estruturar o sistema como um projeto C modular
* Compilar via **Makefile**
* Utilizar **GitHub** para versionamento

---

## 🏗️ Arquitetura do Sistema

O sistema é estruturado de forma modular, com separação entre:

* Lógica de negócio
* Manipulação de listas
* Persistência em arquivos
* Interface textual (menu)

Os ponteiros para as listas de:

* Aeronaves
* Rotas

São declarados **localmente na função `main()`**, não havendo variáveis globais no sistema.

---

## 🧠 Estruturas de Dados

* Lista encadeada de aeronaves
* Lista encadeada de rotas

Cada nó contém:

* Dados do registro
* Ponteiro para o próximo elemento

---
## 📁 Estrutura do Projeto

```
.
├── src/              # Arquivos fonte (.c)
├── include/          # Cabeçalhos (.h)
├── database/         # Arquivos binários de persistência (.bin)
├── csv/              # Relatórios exportados em CSV
├── html/             # Relatórios exportados em HTML
├── txt/              # Relatórios exportados em TXT
├── Makefile
├── main.c
└── README.md
```
---

## 💾 Persistência de Dados

Os dados são salvos e carregados da pasta `database/`:
- `database/aeronaves.bin`
- `database/rotas.bin`

O sistema realiza:

### 🔹 Ao iniciar:

* Leitura dos arquivos binários
* Alocação dinâmica dos registros nas listas encadeadas

### 🔹 Ao encerrar:

* Gravação completa das listas em:

  * `aeronaves.bin`
  * `rotas.bin`

---

## 📊 Funcionalidades

### ✈️ Gestão de Aeronaves

* Cadastro
* Alteração
* Remoção
* Listagem
* Exportação para `.csv`
* Exportação para `.html`

### 🛫 Gestão de Rotas

* Cadastro (somente se houver aeronave disponível)
* Impede alocação de aeronave em manutenção
* Alteração
* Remoção
* Listagem
* Exportação para `.csv`
* Exportação para `.html`

---

## 📄 Geração de Relatórios

Os relatórios podem ser:

* Exibidos na tela
* Exportados para arquivo `.csv` (compatível com Excel/LibreOffice)
* Exportados para `.html`

O nome do arquivo `.csv` é definido pelo usuário no momento da exportação.

Os arquivos exportados são salvos automaticamente nas pastas correspondentes:
- `.txt` → pasta `txt/`
- `.csv` → pasta `csv/`  
- `.html` → pasta `html/`

---

## ⚙️ Compilação e Execução

O projeto utiliza **Makefile** para automação da compilação.

### Compilar:

```bash
make
```

### Executar:

```bash
./main
```

### Limpar arquivos objeto:

```bash
make clear
```

---

## 🛡️ Regras de Negócio Implementadas

* Não é possível cadastrar uma rota sem aeronave disponível.
* Aeronaves em manutenção não podem ser alocadas em rotas.
* Dados são preservados entre execuções.
* Não há variáveis globais no sistema.

---

## 🧪 Requisitos Técnicos

* Compilador C (GCC recomendado)
* Sistema operacional Linux ou compatível
* Make


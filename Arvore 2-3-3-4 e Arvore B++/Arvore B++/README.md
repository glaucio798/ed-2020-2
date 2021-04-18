# Avore B++

implementação da avore b++

## Descrição de arquivos

### Bplus.hpp

A classe Bplus representa a ArvoreB+, ela armazena os pacoteB’s, que representam
os índices dos blocos do sequenceSet. Sua estrutura é armazenada em um arquivo binário
e para isso conta com um cabeçalho com os seguintes dados: Capacidade máxima do
pacote, capacidade mínima do pacote, posição do meio do pacote, número de nós, próxima
posição vazia e posição da raiz.

### configuracao.hpp

Para mantermos um padrão em todo projeto, utilizamos um arquivo de configuração,
chamado “configuracao.hpp”. Nele declaramos as seguintes informações:

- Estrutura elemento: A estrutura elemento será utilizada para definir as propriedades do bloco do SequenceSet.
  - campo Aluno, considerado aqui chave
  - campo Curso
  - campo Orientador
  - campo Vaga Reservada
  - campo Edital
  - campo Semestre de Ingresso
- Estrutura elementoB: A estrutura elemento será utilizada para definir as
  propriedades do bloco da Arvore B+.
  - campo Aluno, considerado aqui chave
  - campo Posição
- Capacidade do pacote
- Capacidade mínima do pacote
- Posição do meio
- Posição inválida

### pacote.hpp

Os pacotes são usados pelo SequenceSet, tem os campos elementos e posição do
próximo.

### pacoteB.hpp

Os pacoteB’s são usados como nós da árvore B+ nele temos os campos “folha”, que
indica se o pacote é folha, “numElementos”, que indica o número de elementos, “pai”, que
guarda a posição do nó pai, o “vetor filhos”, que indica qual a posição do pai, o “vetor de
filhos”, guardando as posições dos filhos, um vetor “FilhosSet” que, caso o pacoteB seja
folha, irá guardar as posições dos filhos no sequenceSet.

### sequenceset.hpp

SequenceSet utiliza os pacotes para guardar seus dados, estes, por sua vez, são
armazenados em um arquivo binário.

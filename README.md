# Árvore binária de pesquisa  
Unipe - P3 -  Estrutura de dados I  
Professor: Walace Bonfim  
Repositório: [GitHub](https://github.com/gui9394/Unipe_P3_EstruturaDados)  


## Descrição
### Requisitos:
1. Crie uma árvore binária de pesquisa do tipo "t_arvore", implementando-a de forma encadeada, com o conteúdo lido do arquivo de entrada de dados.
2. O "t_elemento" da árvore deverá ser uma estrutura que armazene o endereço do nó e o dado que será lido do arquivo de entrada.
3. Exiba o seguinte menu de opções:
```
Aluno: Nome completo do aluno
Disciplina: Estrutura de dados I
Professor: Walace Bonfim

	Editor de árvore

 1 - Inserir
 2 - Remover apenas um nó
 3 - Pesquisar
 4 - Esvaziar a árvore
 5 - Exibir a árvore
 0 - Sair

	Digite sua opção:
```
4. A árvore inicial deve ser gerada em memória a partir dos dados armazenado em um arquivo de texto (no formato csv que separa as entradas por vírgulas).
5. Leia a opção do usuário.
6. Execute a opção escolhida pelo usuário.
7. Após a execução de cada opção, o programa deve retornar ao menu para nova opção do usuário ou o encerramento do programa.

### Opções  
1. Inserir, deve inserir um elemento segundo as regras de árvore binária de pesquisa.
2. Remover, deve pegar o conteúdo do nó a ser removido. Caso não exista, dar mensagem correspondente.
3. Pesquisar, deve dizer se o dado armazenado no t_elemento está presente ou não na árvore.
4. Esvaziar, deve apagar todos os nós da árvore.
5. Exibir, deve exibir em todas as formas, pré/in/pós-ordem e graficamente, ambos os dados existentes no t_elemento.

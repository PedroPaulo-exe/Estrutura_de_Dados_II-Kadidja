# Estrutura de Dados II — Atividade de Árvores

**Data:** 28/09/2026  
**Aluno:** Pedro Paulo Rodrigues Cardoso  
**Disciplina:** Estrutura de Dados II  
**Professora:** Profa. Kadidja Valéria  
**Modalidade:** Individual, remota e assíncrona  

---

## Etapa 1 — Revisão bibliográfica

### 1. Conceitos Fundamentais
* **Nó:** Elemento estrutural básico que abriga uma chave de valor e referências de ponteiros para outros nós adjacentes (descendentes ou ascendentes).
* **Raiz:** O único ponto de entrada hierárquico superior da árvore, desprovido de nó pai.
* **Pai e Filho:** Conexão direta de subordinação hierárquica. O nó superior assume o papel de pai e o inferior, de filho. Nós que compartilham o mesmo pai são considerados irmãos.
* **Folha:** Nó terminal localizado nas extremidades da árvore, sem nenhuma ramificação inferior (grau zero).
* **Altura:** Comprimento da maior trajetória possível entre a raiz e uma folha terminal.
* **Percursos:** Estratégias sistemáticas de visitação de todos os nós da estrutura:
  * *Pré-ordem:* Raiz -> Subárvore Esquerda -> Subárvore Direita.
  * *Em ordem (In-ordem):* Subárvore Esquerda -> Raiz -> Subárvore Direita (essencial para exibir dados ordenados em ABBs).
  * *Pós-ordem:* Subárvore Esquerda -> Subárvore Direita -> Raiz.
  * *Em largura (por níveis):* Varredura horizontal nível a nível, da esquerda para a direita.

### 2. Tipos de Árvores

#### Árvore Geral
* **Organização:** Hierarquia flexível onde cada nó pode conter múltiplos descendentes sem restrição rígida de grau máximo de ramificação.
* **Propriedade:** Relação estrita de ascendência, onde cada nó possui exatamente um pai (com exceção da raiz).
* **Busca e Inserção:** Varredura por caminhos direcionados; inserções exigem a especificação explícita do nó pai receptor.
* **Ajustes:** Ausência de rebalanceamento automático nativo.
* **Aplicações:** Sistemas de arquivos de diretórios e estruturas de documentos hierárquicos (como o DOM).

#### Árvore Binária
* **Organização:** Estrutura restrita a no máximo dois filhos por nó (convencionalmente denominados filho esquerdo e filho direito).
* **Propriedade:** Grau máximo de saída por nó igual ou inferior a 2.
* **Busca e Inserção:** Buscas exaustivas no pior caso; inserções preenchem posições vagas de acordo com a política implementada.
* **Ajustes:** Varia conforme o subtipo específico (ex: heaps mantêm completude estrutural).
* **Aplicações:** Árvores de expressão matemática e algoritmos de divisão e conquista.

#### Árvore Binária de Busca (ABB)
* **Organização:** Ordenação baseada em comparações sucessivas de chaves.
* **Propriedade:** Valores menores situam-se na subárvore esquerda e valores maiores ou iguais na subárvore direita de qualquer nó.
* **Busca e Inserção:** Busca por divisão e conquista logarítmica (complexidade média $O(\log N)$); inserção posiciona o nó na folha correspondente.
* **Ajustes:** Não possui balanceamento automático, podendo degenerar para uma estrutura linear em caso de inserções ordenadas.
* **Aplicações:** Dicionários básicos em memória e tabelas de símbolos.

#### Árvore AVL
* **Organização:** Árvore binária de busca auto-balanceada com controle rigoroso de desnível entre ramos.
* **Propriedade:** A diferença de altura entre as subárvores esquerda e direita de qualquer nó não pode ultrapassar o valor 1.
* **Busca e Inserção:** Busca rápida garantida; inserções avaliam o fator de balanceamento dos nós percorridos.
* **Ajustes:** Executa rotações simples ou duplas quando o fator de balanceamento é violado.
* **Aplicações:** Ambientes com alta frequência de buscas e exigência de estabilidade na altura.

#### Árvore Rubro-Negra (Red-Black)
* **Organização:** Árvore de busca binária que utiliza atributos adicionais de coloração (vermelho ou preto) para manter o equilíbrio aproximado.
* **Propriedade:** Raiz e folhas NIL pretas; nós vermelhos não possuem filhos vermelhos; todos os caminhos possuem a mesma quantidade de nós pretos.
* **Busca e Inserção:** Segue o padrão de ABB; novos nós entram coloridos como vermelhos por padrão.
* **Ajustes:** Emprega operações de recoloração e rotações estruturais para sanar violações de regras.
* **Aplicações:** Implementações de estruturas associativas em bibliotecas padrão (como `TreeMap` em Java ou `std::map` em C++).

#### Árvore B
* **Organização:** Árvore multicaminho balanceada otimizada para operações de E/S em blocos de memória secundária.
* **Propriedade:** Nós armazenam múltiplas chaves e diversos ponteiros para filhos; todas as folhas situam-se exatamente no mesmo nível.
* **Busca e Inserção:** Busca interna por chave no bloco; inserções ocorrem nas folhas gerando divisões (*splits*) quando o limite é excedido.
* **Ajustes:** Propagação de divisões de nós para cima na hierarquia.
* **Aplicações:** Sistemas de Gerenciamento de Bancos de Dados (SGBDs) e indexação em disco.

#### Árvore B+
* **Organização:** Evolução da Árvore B onde dados e registros residem estritamente nas folhas, enquanto nós internos atuam como índices de roteamento.
* **Propriedade:** Folhas interligadas sequencialmente por ponteiros bidirecionais formam uma lista encadeada inferior.
* **Busca e Inserção:** Acesso obrigatório às folhas; inserções geram divisões de blocos mantendo a coerência da listagem sequencial.
* **Ajustes:** Divisões de nós e manutenção dos ponteiros de encadeamento nas folhas.
* **Aplicações:** Índices de SGBDs otimizados para buscas pontuais e consultas por intervalo.

#### Heap Binário
* **Organização:** Árvore binária quase completa representada de forma compacta em um vetor linear.
* **Propriedade:** Em Max-Heap, o pai supera ou iguala seus filhos; em Min-Heap, o pai é inferior ou igual.
* **Busca e Inserção:** Inserção no final do vetor com subida subsequente (*bubble-up*); busca arbitrária custosa.
* **Ajustes:** Reorganizações por subida (*heapify-up*) ou descida (*heapify-down*).
* **Aplicações:** Filas de prioridade e algoritmo Heapsort.

#### Trie (Árvore de Prefixos)
* **Organização:** Árvore de caracteres indexada onde caminhos correspondem a sequências de letras.
* **Propriedade:** Palavras com prefixos idênticos compartilham os mesmos nós iniciais na estrutura.
* **Busca e Inserção:** Busca proporcional ao tamanho da palavra ($O(M)$); inserção cria nós apenas para caracteres inexistentes.
* **Ajustes:** Exclusão de ramos órfãos em caso de remoções de strings.
* **Aplicações:** Mecanismos de autocompletar e corretores ortográficos preditivos.

---

## Etapa 2 — Quadro comparativo

| Estrutura | Organização dos Dados | Regra / Propriedade Principal | Ajustes e Operações Principais | Contexto de Aplicação | Fonte de Referência |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Árvore Geral** | Hierarquia aberta de nós sem limite de filhos. | Cada nó possui um único pai (exceto a raiz). | Vínculo direto de ponteiros de descendência. | Sistemas de diretórios e arquivos. | Notas de aula / Material base |
| **Árvore Binária** | Restrita a no máximo dois filhos por nó. | Grau de saída por nó menor ou igual a 2. | Percursos estruturados (pré, em e pós-ordem). | Árvores de expressão aritmética. | Notas de aula / Material base |
| **ABB** | Organização baseada em comparações de chaves. | Subárvore esquerda < Nó < Subárvore direita. | Busca binária recursiva; risco de degradação linear. | Tabelas de símbolos simples. | Material de apoio de ED II |
| **Árvore AVL** | Busca com restrição estrita de altura. | Diferença de altura entre subárvores de um nó $\le 1$. | Rotações simples e duplas para reequilíbrio. | Mapeamentos dinâmicos de alta busca. | Bibliografia oficial |
| **Rubro-Negra** | Busca com atributos cromáticos associados. | Alternância controlada e contagem igual de pretos. | Recolorações e rotações estruturais. | `TreeMap` e estruturas associativas. | Bibliografia oficial |
| **Árvore B** | Multicaminho voltada a blocos de disco. | Múltiplas chaves por nó; folhas no mesmo nível. | Operação de *split* (divisão) de blocos cheios. | SGBDs e indexação em armazenamento secundário. | Bibliografia oficial |
| **Árvore B+** | Dados restritos às folhas com encadeamento. | Guias nos nós internos e folhas ligadas em lista. | Divisão de folhas e manutenção de ponteiros. | Consultas por intervalo em bancos de dados. | Bibliografia oficial |
| **Heap Binário** | Representação linear em vetor (quase completa). | Pai priorizado em relação aos filhos (Max/Min). | Operações de subida e descida (*heapify*). | Filas de prioridade e ordenação. | Material de apoio de ED II |
| **Trie** | Indexação caractere a caractere por prefixos. | Compartilhamento de prefixos comuns entre chaves. | Inserção e varredura incremental de nós de letras. | Sistemas de autocompletar e dicionários. | Material de apoio de ED II |

---

## Etapa 3 — Identificação por analogias

### Situação 1
* **Contexto:** Uma estante de números é reorganizada por rotações quando um lado fica alto demais em relação ao outro.
* **Estrutura:** Árvore AVL.
* **Justificativa técnica:** A restrição rígida de balanceamento impede que a diferença de altura entre os ramos esquerdo e direito supere 1, acionando rotações locais para recuperar a eficiência logarítmica.
* **Limite da analogia:** Na prática computacional, não ocorre translocação física de objetos na memória, mas sim a reatribuição lógica de referências de ponteiros.

### Situação 2
* **Contexto:** Um catálogo guarda várias chaves por página; quando uma página fica cheia, ela é dividida.
* **Estrutura:** Árvore B.
* **Justificativa técnica:** Os nós comportam múltiplos valores simultaneamente; ao exceder a capacidade máxima, ocorre uma divisão (*split*) com promoção do elemento mediano para o nível superior.
* **Limite da analogia:** Páginas de um livro físico possuem tamanho estático e sequencial, ao passo que os blocos da árvore ajustam-se dinamicamente conforme a demanda.

### Situação 3
* **Contexto:** Uma fila mantém a tarefa de maior prioridade no topo para retirá-la primeiro.
* **Estrutura:** Heap (Max-Heap).
* **Justificativa técnica:** O topo da estrutura assegura a presença do elemento de maior prioridade, viabilizando extrações imediatas e manutenções rápidas na árvore.
* **Limite da analogia:** Filas cotidianas obedecem estritamente à ordem de chegada (FIFO), enquanto o Heap prioriza os dados com base em seu valor numérico de relevância.

### Situação 4
* **Contexto:** Um índice percorre letras sucessivas e compartilha o início das palavras de mesmo prefixo.
* **Estrutura:** Trie (Árvore de Prefixos).
* **Justificativa técnica:** Os caracteres são dispostos em grafos ramificados, permitindo que palavras com o mesmo início aproveitem as mesmas caixas iniciais de percurso.
* **Limite da analogia:** Índices impressos tradicionais listam vocábulos em blocos sequenciais por letra, sem o encadeamento estruturado nó a nó de caracteres.

### Situação 5
* **Contexto:** Uma estrutura usa cores, recolorações e rotações para manter controlada a altura dos caminhos de busca.
* **Estrutura:** Árvore Rubro-Negra (Red-Black Tree).
* **Justificativa técnica:** Associa bits de marcação cromática aos nós para estabelecer limites estritos de comprimento de caminho, garantindo complexidade controlada com menos rotações que a AVL.
* **Limite da analogia:** Cores no cotidiano servem para fins visuais ou decorativos, enquanto na árvore funcionam como códigos lógicos de decisão algorítmica.

### Situação 6
* **Contexto:** Um índice conduz às folhas que contêm os registros, ligadas entre si para facilitar consultas por intervalo.
* **Estrutura:** Árvore B+.
* **Justificativa técnica:** Utiliza nós superiores apenas como roteamento de caminhos, concentrando os registros nas folhas inferiores interligadas por ponteiros sequenciais bidirecionais.
* **Limite da analogia:** Índices remissivos de livros indicam páginas estáticas, mas não formam uma rede dinâmica contínua interligada de dados sequenciais.

### Situação 7
* **Contexto:** Numa coleção de números, cada nó direciona valores menores para a esquerda e maiores para a direita.
* **Estrutura:** Árvore Binária de Busca (ABB).
* **Justificativa técnica:** A regra invariante divide o espaço de busca por comparações binárias de chaves, direcionando o fluxo de forma eficiente.
* **Limite da analogia:** Agrupamentos físicos de objetos em caixas não se reorganizam ou balanceiam automaticamente de forma hierárquica diante de inserções desordenadas.

---

## Referências Consultadas
* Material didático e notas de aula de Estrutura de Dados II — Profa. Kadidja Valéria.
* CORMEN, Thomas H. et al. *Algoritmos: Teoria e Prática*. Editora Campus/Elsevier.
* ZIVIANI, Nivio. *Projeto de Algoritmos com Implementações em Pascal e C*. Cengage Learning.
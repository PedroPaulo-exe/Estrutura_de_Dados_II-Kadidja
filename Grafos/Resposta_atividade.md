# Estrutura de Dados II — Projeto ConectaUDF: Redes Sociais com Grafos

**Data:** 19/10/2026  
**Aluno:** Pedro Paulo Rodrigues Cardoso  
**Disciplina:** Estrutura de Dados II  
**Professora:** Profa. Kadidja Valéria  
**Modalidade:** Individual, remota e assíncrona  

---

## 1. O desafio
O objetivo desta atividade é analisar a rede social fictícia **ConectaUDF** modelando as relações de amizade por meio de uma estrutura de grafos, realizando cálculos manuais de métricas estruturais e implementando um script em Python para validar a topologia da rede.

---

## 2. Conceitos essenciais
* **Vértice (ou nó):** Representa individualmente cada usuário da rede.
* **Aresta:** Representa a relação mútua de amizade estabelecida entre dois usuários.
* **Grau:** Métrica que indica a quantidade exata de conexões diretas que um usuário possui.
* **Caminho:** Sequência de vértices adjacentes que conecta um ponto de origem a um destino.
* **Densidade:** Relação proporcional entre o número de arestas existentes e o total máximo de conexões possíveis na rede.

Como a relação de amizade descrita é recíproca, o modelo é representado por um **grafo não direcionado**.

---

## 3. Conheça os usuários
A rede inicial é composta por 6 usuários e 8 conexões catalogadas:

| Código | Usuário |
| :--- | :--- |
| A | Ana |
| B | Bruno |
| C | Carla |
| D | Diego |
| E | Elisa |
| F | Felipe |

**Relações de amizade:**
1. Ana — Bruno
2. Ana — Carla
3. Bruno — Carla
4. Bruno — Diego
5. Carla — Elisa
6. Diego — Elisa
7. Diego — Felipe
8. Elisa — Felipe

---

## 4. Passo a passo: desenhe o grafo
*(Representação visual construída de forma manual/esquemática)*
* Seis nós distribuídos no plano, interligados por arestas simples sem repetição, refletindo exatamente as 8 amizades listadas no escopo do projeto.

---

## 5. Passo a passo: calcule o grau
Contando o número de arestas incidentes em cada vértice:

| Usuário | Amigos diretos | Grau |
| :--- | :--- | :---: |
| Ana | Bruno, Carla | **2** |
| Bruno | Ana, Carla, Diego | **3** |
| Carla | Ana, Bruno, Elisa | **3** |
| Diego | Bruno, Elisa, Felipe | **3** |
| Elisa | Carla, Diego, Felipe | **3** |
| Felipe | Diego, Elisa | **2** |

**Pergunta 1:** Quem tem mais conexões diretas?  
**Resposta:** Bruno, Carla, Diego e Elisa, todos empatados com grau 3.

---

## 6. Passo a passo: calcule o número de amizades
Aplicando a relação da soma dos graus:
* **Soma dos graus:** $2 + 3 + 3 + 3 + 3 + 2 = 16$
* **Divisão por 2:** $16 \div 2 = 8$
* **Total de arestas (amizades):** 8

---

## 7. Passo a passo: calcule a densidade
Utilizando a fórmula para grafos simples não direcionados ($D = \frac{2 \times E}{V \times (V - 1)}$), onde $E = 8$ e $V = 6$:

$$D = \frac{2 \times 8}{6 \times (6 - 1)} = \frac{16}{30} \approx 0,5333$$

* **Resultado decimal:** 0,53  
* **Resultado percentual:** 53,33%  

**Interpretação:** A densidade de aproximadamente 53% mostra que a rede é relativamente coesa. Mais da metade das conexões possíveis entre os 6 usuários realmente existem, indicando um grupo bem integrado e sem isolamento estrutural severo.

---

## 8. Passo a passo: represente o grafo em Python
Implementação da lista de adjacência e cálculos automatizados:

```python
rede = {
    "Ana": ["Bruno", "Carla"],
    "Bruno": ["Ana", "Carla", "Diego"],
    "Carla": ["Ana", "Bruno", "Elisa"],
    "Diego": ["Bruno", "Elisa", "Felipe"],
    "Elisa": ["Carla", "Diego", "Felipe"],
    "Felipe": ["Diego", "Elisa"]
}

# Quantidade de usuários
n = len(rede)

# Cálculo do grau de cada usuário
for usuario, amigos in rede.items():
    print(usuario, "tem", len(amigos), "conexões")

# A soma dos graus conta cada amizade duas vezes
soma_graus = sum(len(amigos) for amigos in rede.values())
arestas = soma_graus // 2

print("Total de usuários:", n)
print("Total de amizades:", arestas)

# Densidade do grafo
densidade = (2 * arestas) / (n * (n - 1))
print(f"Densidade: {densidade:.2%}")
// Definição da classe ListNode, representando um nó na lista encadeada
class ListNode {
    int value; // Valor armazenado no nó
    ListNode next; // Referência para o próximo nó na lista

    // Construtor para criar um novo nó com um valor específico
    public ListNode(int value) {
        this.value = value;
        this.next = null; // Inicialmente, o próximo nó é nulo
    }
}

// Definição da classe LinkedList, representando a lista encadeada
public class ListaSimplesmenteEncadeada {
    private ListNode head; // Referência para o primeiro nó na lista (cabeça)
    private ListNode tail; // Referência para o último nó na lista (cauda)
    private int count; // Contador para armazenar o tamanho da lista

    // Construtor para inicializar uma lista encadeada vazia
    public ListaSimplesmenteEncadeada() {
        this.head = null;
        this.tail = null;
        this.count = 0;
    }

    // Método para obter o tamanho da lista
    public int size() {
        return count;
    }

    // Método para adicionar um elemento ao final da lista
    public void add(int element) {
        ListNode newNode = new ListNode(element); // Cria um novo nó com o valor especificado
        if (head == null) {
            // Se a lista estiver vazia, o novo nó se torna o primeiro e o último nó
            head = newNode;
        } else {
            // Caso contrário, o próximo nó do último nó é definido como o novo nó
            tail.next = newNode;
        }
        // Atualiza a cauda da lista para o novo nó e incrementa o contador de tamanho
        tail = newNode;
        count++;
    }

    // Método para obter o nó em uma posição específica na lista
    public ListNode get(int index) {
        // Verifica se o índice está dentro dos limites válidos da lista
        if (index < 0 || index >= count) {
            return null; // Retorna nulo se o índice estiver fora dos limites
        }
        ListNode current = head; // Começa a busca a partir do primeiro nó
        // Percorre a lista até alcançar o nó na posição especificada
        for (int i = 0; i < index; i++) {
            current = current.next; // Avança para o próximo nó na lista
        }
        return current; // Retorna o nó encontrado
    }

    // Método para adicionar um elemento em uma posição específica na lista
    public void add(int index, int element) {
        // Verifica se o índice está dentro dos limites válidos da lista
        if (index < 0 || index > count) {
            return; // Retorna sem fazer nada se o índice estiver fora dos limites
        }
        // Se o índice for igual ao tamanho da lista, adiciona o elemento ao final
        if (index == count) {
            add(element);
            return;
        }
        ListNode newNode = new ListNode(element); // Cria um novo nó com o valor especificado
        if (index == 0) {
            // Se o índice for zero, o novo nó se torna o primeiro nó na lista
            newNode.next = head;
            head = newNode;
        } else {
            // Caso contrário, encontra o nó anterior ao índice especificado
            ListNode prev = get(index - 1);
            // Insere o novo nó entre o nó anterior e o nó na posição especificada
            newNode.next = prev.next;
            prev.next = newNode;
        }
        // Incrementa o contador de tamanho da lista
        count++;
    }

    // Método para remover um elemento na posição específica da lista
    public void remove(int index) {
        // Verifica se o índice está dentro dos limites válidos da lista
        if (index < 0 || index >= count) {
            return; // Retorna sem fazer nada se o índice estiver fora dos limites
        }
        if (index == 0) {
            // Se o índice for zero, remove o primeiro nó da lista
            head = head.next;
            if (head == null) {
                // Se o primeiro nó for o único nó na lista, a cauda também deve ser atualizada
                tail = null;
            }
        } else {
            // Caso contrário, encontra o nó anterior ao índice especificado
            ListNode prev = get(index - 1);
            // Remove o nó na posição especificada, ajustando as referências dos nós adjacentes
            prev.next = prev.next.next;
            if (prev.next == null) {
                // Se o nó removido for o último nó na lista, a cauda deve ser atualizada
                tail = prev;
            }
        }
        // Decrementa o contador após a remoção do nó
        count--;
    }

    public static void main(String[] args) {
        // Criando uma instância da lista encadeada
        ListaSimplesmenteEncadeada lista = new ListaSimplesmenteEncadeada();

        // Adicionando elementos à lista
        lista.add(10);
        lista.add(20);
        lista.add(30);

        // Imprimindo o tamanho da lista
        System.out.println("Tamanho da lista: " + lista.size());

        // Obtendo um elemento em uma posição específica e imprimindo seu valor
        ListNode node = lista.get(1);
        if (node != null) {
            System.out.println("Valor do elemento na posição 1: " + node.value);
        } else {
            System.out.println("Posição inválida.");
        }

        // Adicionando um elemento em uma posição específica
        lista.add(1, 15);

        // Imprimindo o tamanho da lista após a adição
        System.out.println("Novo tamanho da lista: " + lista.size());

        // Removendo um elemento em uma posição específica
        lista.remove(2);

        // Imprimindo o tamanho da lista após a remoção
        System.out.println("Tamanho da lista após a remoção: " + lista.size());
    }
}
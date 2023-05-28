/*
Реализовать очередь продуктов в товарном чеке. Товарный чек
содержит список товаров, купленных покупателем в магазине. Один элемент
списка представляет собой пару: товар-сумма. Товар реализовать как структуру
Goods с полями кода и наименования, цены за единицу товара, количества
приобретаемых единиц. Реализовать методы добавления, изменения и удаления
записи о покупаемом виде товара, метод поиска информации об определенном
виде товара по его коду и названию, а также метод подсчета общей суммы, на
которую были осуществлены покупки.
*/

#include <iostream>
using namespace std;

struct Node
{
    Node* next;
    struct Goods
    {
    public:
        string name;
        string code; 
        int cost;
       
    };
    Goods goods;
};

typedef Node* PNode;

struct Queue
{
    PNode Head = NULL, Tail = NULL;
};

PNode new_node(int cost, string name, string code)
{
    PNode new_node;
    new_node = new Node;
    new_node->goods.cost = cost;
    new_node->goods.name = name;
    new_node->goods.code = code;
    return new_node;
}

void add_to_queue(Queue& Q, PNode& N)
{
    PNode new_node;
    new_node = new Node;
    new_node->goods = N->goods;
    new_node->next = NULL;
    if (Q.Tail)
    {
        Q.Tail->next = new_node;
    }
    Q.Tail = new_node;
    if (Q.Head == NULL)
    {
        Q.Head = Q.Tail;
    }
}

void show(Queue& Q)
{

    PNode q1;
    string stemp = "";                          //имя нового товара 
    int temp = 0;                               //количество нового товара
    int cost = 0;                               //общая стоимость 
    q1 = Q.Head;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    do
    {
        if (stemp != q1->goods.name)                //для товара встречающегося впервые
        {
            temp = 0;
            stemp = q1->goods.name;
            cout << q1->goods.name << endl;
            cout << q1->goods.code << endl;
            cout << q1->goods.cost << endl;
            cout << endl;
        }
        if (stemp == q1->goods.name)                //для повтряющегося товара 
        {
            temp++;
        }
        if (q1->next == NULL || q1->next->goods.name != q1->goods.name)             //для вывода стоимости и количества товара 
        {
            cost = cost + (temp * q1->goods.cost);
            cout << temp << endl;
            cout << temp * q1->goods.cost << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
        if (q1->next == NULL)                   //для вывода общей стоимости всех товаров 
        {
            cout << cost << endl;
        }
        q1 = q1->next;
    } while (q1 != NULL);
    cout << "\n\t СПАСИБО ЗА ПОКУПКУ!" << endl;
}

void add(Queue& Q, PNode& N, int n)
{
    for (int i = 0; i != n; i++)
    {
        add_to_queue(Q, N);
    }
}

int main()
{
    setlocale(LC_ALL, "");         
  
    Queue q1;

    cout << " Название, код, стоимость, количество, общая стоимость " << endl;
    PNode n1 = new_node(40, "Хлебушек", "130745332");
    PNode n2 = new_node(34, "Глазированный сырок", "256789340");
    PNode n3 = new_node(40, "Хлебушек", "130745332");
    PNode n4 = new_node(80, "Помидорка", "605983674");
    add(q1, n1, 2);
    add(q1, n2, 7);
    add(q1, n3, 4);
    add(q1, n4, 12);
    show(q1);
    return 0;
}


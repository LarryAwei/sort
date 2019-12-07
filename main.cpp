#include<iostream>
using namespace std;

struct Node
{
    char data;
    Node* L;
    Node* R;
};
Node* T; // 创建一个指针T 指向这个二叉树的首地址（即这个二叉树的根节点）

void creatNode(Node* &T)
{
    char ch;
    if ((ch = getchar()) == '#')  // 前序遍历输入
    {
        T = NULL;
    }
    else
    {
        T = new Node;
        T->data = ch;
        creatNode(T->L);
        creatNode(T->R);
    }
}



// ================前序
void preOrder(Node* &T)
{
    if (T == NULL)//如果二叉树为空直接返回结束程序
        return;
    else
    {
        cout << T->data << " ";
        preOrder(T->L);
        preOrder(T->R);
    }
}

// ================中序
void inOrder(Node* &T)
{
    if (T == NULL)
        return;
    else
    {
        inOrder(T->L);
        cout << T->data << " ";
        inOrder(T->R);
    }
}

// ================后序
void posOrder(Node* &T)
{
    if (T == NULL)
        return;
    else
    {
        posOrder(T->L);
        posOrder(T->R);
        cout << T->data << " ";
    }

}
int main() {
    cout << "输入一个二叉树(按照这个二叉树的前序遍历输入，若子节点为空就输入 #  ):" << endl;
    creatNode(T);
    cout << "前序遍历:";
    preOrder(T);
    cout << endl;
    cout << "中序遍历:";
    inOrder(T);
    cout << endl;
    cout << "后序遍历:";
    posOrder(T);
    cout << endl;
    delete T;
    return 0;
}
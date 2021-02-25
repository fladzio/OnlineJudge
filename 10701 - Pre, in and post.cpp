#include <iostream>
struct Node
{
    char data;
    Node *left = NULL;
    Node *right = NULL;
};

int c, n, index;
char pre[52], in[52];

Node *Tree(int left = 0, int right = n - 1)
{
    Node *tree = new Node;
    tree->data = pre[index++];

    if (left < right)
    {
        int mid;
        for (mid = left; mid <= right; ++mid) {
        if (in[mid] == tree->data)
            break;
    }

    if (left <= mid - 1)
        tree->left = Tree(left, mid - 1);

    if (mid + 1 <= right)
        tree->right = Tree(mid + 1, right);
    }

    return tree;
}
void Postorder(Node *tree)
{
    if (!tree) return;
    Postorder(tree->left);
    Postorder(tree->right);
    std::cout << tree->data;
    delete tree;
}
int main() {
    std::cin >> c;
    while (c--)
    {
        std::cin >> n >> pre >> in;
        index = 0;
        Node *tree = Tree();
        Postorder(tree);
        std::cout << "\n";
    }
    return 0;
}

#include <iostream>
using namespace std;

/**
 * 二叉树类的实现
 * 支持基本的二叉树操作：插入、遍历、查找、销毁等
 */
class BinaryTree
{
private:
    /**
     * 二叉树节点结构
     */
    struct Node
    {
        int data;    // 节点数据
        Node *left;  // 左子节点指针
        Node *right; // 右子节点指针

        /**
         * 节点构造函数
         * @param data_ 节点数据
         */
        Node(int data_ = 0) : data(data_), left(nullptr), right(nullptr) {
                              };
    };

    Node *root; // 根节点指针

    /**
     * 销毁二叉树的辅助函数（后序遍历）
     * @param node 当前节点
     */
    void destroyTree(Node *node)
    {
        if (node != nullptr)
        {
            destroyTree(node->left);  // 销毁左子树
            destroyTree(node->right); // 销毁右子树
            delete node;              // 释放当前节点
        }
    }

    /**
     * 插入节点的辅助函数
     * @param node 当前节点
     * @param data 要插入的数据
     * @return 插入后的根节点
     */
    Node *insertNode(Node *node, int data)
    {
        if (node == nullptr)
        {
            return new Node(data); // 创建新节点
        }

        if (data < node->data)
        {
            node->left = insertNode(node->left, data); // 插入左子树
        }
        else if (data > node->data)
        {
            node->right = insertNode(node->right, data); // 插入右子树
        }
        // 数据相等时不插入（避免重复）

        return node;
    }

    /**
     * 前序遍历的辅助函数
     * @param node 当前节点
     */
    void preOrderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";      // 访问根节点
            preOrderTraversal(node->left);  // 遍历左子树
            preOrderTraversal(node->right); // 遍历右子树
        }
    }

    /**
     * 中序遍历的辅助函数
     * @param node 当前节点
     */
    void inOrderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->left);  // 遍历左子树
            cout << node->data << " ";     // 访问根节点
            inOrderTraversal(node->right); // 遍历右子树
        }
    }

    /**
     * 后序遍历的辅助函数
     * @param node 当前节点
     */
    void postOrderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            postOrderTraversal(node->left);  // 遍历左子树
            postOrderTraversal(node->right); // 遍历右子树
            cout << node->data << " ";       // 访问根节点
        }
    }

    /**
     * 查找节点的辅助函数
     * @param node 当前节点
     * @param data 要查找的数据
     * @return 找到的节点，未找到返回nullptr
     */
    Node *searchNode(Node *node, int data)
    {
        if (node == nullptr || node->data == data)
        {
            return node; // 找到或到达叶子节点
        }

        if (data < node->data)
        {
            return searchNode(node->left, data); // 在左子树中查找
        }
        else
        {
            return searchNode(node->right, data); // 在右子树中查找
        }
    }

    /**
     * 查找最小值节点的辅助函数
     * @param node 当前节点
     * @return 最小值节点
     */
    Node *findMinNode(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left; // 一直向左遍历
        }
        return node;
    }

    /**
     * 删除节点的辅助函数
     * @param node 当前节点
     * @param data 要删除的数据
     * @return 删除后的根节点
     */
    Node *deleteNode(Node *node, int data)
    {
        if (node == nullptr)
        {
            return nullptr; // 未找到要删除的节点
        }

        if (data < node->data)
        {
            node->left = deleteNode(node->left, data); // 在左子树中删除
        }
        else if (data > node->data)
        {
            node->right = deleteNode(node->right, data); // 在右子树中删除
        }
        else
        {
            // 找到要删除的节点

            // 情况1：叶子节点
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            // 情况2：只有一个子节点
            else if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            // 情况3：有两个子节点
            else
            {
                Node *temp = findMinNode(node->right);             // 找到右子树中的最小值节点
                node->data = temp->data;                           // 用最小值替换当前节点
                node->right = deleteNode(node->right, temp->data); // 删除最小值节点
            }
        }

        return node;
    }

    /**
     * 计算树高度的辅助函数
     * @param node 当前节点
     * @return 树的高度
     */
    int getHeight(Node *node)
    {
        if (node == nullptr)
        {
            return 0; // 空树高度为0
        }

        int leftHeight = getHeight(node->left);   // 左子树高度
        int rightHeight = getHeight(node->right); // 右子树高度

        return max(leftHeight, rightHeight) + 1; // 当前树高度
    }

    /**
     * 计算节点数的辅助函数
     * @param node 当前节点
     * @return 节点总数
     */
    int getNodeCount(Node *node)
    {
        if (node == nullptr)
        {
            return 0; // 空树节点数为0
        }

        return 1 + getNodeCount(node->left) + getNodeCount(node->right); // 递归计算
    }

public:
    /**
     * 构造函数
     */
    BinaryTree() : root(nullptr)
    {
    }

    /**
     * 析构函数
     */
    ~BinaryTree()
    {
        destroyTree(root); // 销毁整个二叉树
    }

    /**
     * 插入节点
     * @param data 要插入的数据
     */
    void insert(int data)
    {
        root = insertNode(root, data);
    }

    /**
     * 前序遍历
     */
    void preOrder()
    {
        cout << "前序遍历: ";
        preOrderTraversal(root);
        cout << endl;
    }

    /**
     * 中序遍历
     */
    void inOrder()
    {
        cout << "中序遍历: ";
        inOrderTraversal(root);
        cout << endl;
    }

    /**
     * 后序遍历
     */
    void postOrder()
    {
        cout << "后序遍历: ";
        postOrderTraversal(root);
        cout << endl;
    }

    /**
     * 查找节点
     * @param data 要查找的数据
     * @return 是否找到
     */
    bool search(int data)
    {
        return searchNode(root, data) != nullptr;
    }

    /**
     * 删除节点
     * @param data 要删除的数据
     */
    void remove(int data)
    {
        root = deleteNode(root, data);
    }

    /**
     * 获取树的高度
     * @return 树的高度
     */
    int height()
    {
        return getHeight(root);
    }

    /**
     * 获取节点总数
     * @return 节点总数
     */
    int size()
    {
        return getNodeCount(root);
    }

    /**
     * 检查树是否为空
     * @return 是否为空
     */
    bool isEmpty()
    {
        return root == nullptr;
    }
};

/**
 * 主函数，演示二叉树的使用
 */
int main()
{
    // 创建二叉树对象
    BinaryTree tree;

    // 插入节点
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // 遍历测试
    tree.preOrder();  // 前序遍历
    tree.inOrder();   // 中序遍历
    tree.postOrder(); // 后序遍历

    // 查找测试
    cout << "查找 40: " << (tree.search(40) ? "找到" : "未找到") << endl;
    cout << "查找 90: " << (tree.search(90) ? "找到" : "未找到") << endl;

    // 树的属性测试
    cout << "树的高度: " << tree.height() << endl;
    cout << "节点总数: " << tree.size() << endl;
    cout << "树是否为空: " << (tree.isEmpty() ? "是" : "否") << endl;

    // 删除测试
    cout << "删除节点 30 后:" << endl;
    tree.remove(30);
    tree.inOrder();

    cout << "删除节点 50 后:" << endl;
    tree.remove(50);
    tree.inOrder();

    return 0;
}
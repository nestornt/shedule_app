#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    string key;
    string tel;
    Node *left;
    Node *right;
};

// RETORNA UN PUNTERO AL NODO ACTUAL
Node* createNode(string key, string tel){
    Node *node = new Node();
    node->key = key;
    node->tel = tel;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// (BFT)
Node* search(Node* root, string key)
{
    if(root == NULL)
        return root;

    queue< Node* > q;
    Node* out = NULL;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp->key == key) 
        {
           out = temp; cout << "\nContacto: " << temp->key << "  |  " << "Telefono: " << temp->tel << endl;
        }
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
    return out;
}

void insert(Node **root, string key, string tel)
{
    if(*root == NULL)
    {
        cout << "THE ROOT IS NULL" << endl;
        *root = createNode(key, tel);
        return;
    }


    Node *nodeToInsert = createNode(key, tel);
    queue<Node*> q;
    q.push(*root);

    while(! q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp->left == NULL)
        {
            temp->left = nodeToInsert;
            return;
        }
        else
            q.push(temp->left);

          if(temp->right == NULL)
        {
            temp->right = nodeToInsert;
            return;
        }
        else
            q.push(temp->right);

    }
}

int main()
{
    Node* root = createNode("Pepe", "987898789");
    root->right = createNode("Rosa", "666222333");
    root->left = createNode("Ana", "988666777");
    root->left->right = createNode("Juan", "666999000");
    root->right->left = createNode("Oscar", "678903212");

    string contact_name;
    cout << "\n\n[AGENDA]\n\n" << "Contactos actuales -> Pepe, Rosa, Ana, Juan, Oscar.\n\n";
    cout << "Inserta un nombre de contacto para acceder a su telefono.\n\n";
    cin >> contact_name;

    Node *node = search(root, contact_name);

    return 0;
}
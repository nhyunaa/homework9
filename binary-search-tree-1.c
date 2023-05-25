/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node { // Node ����ü ����
	int key; // ������ ���� key ����
	struct node *left; // ����ü ������ left����
	struct node *right; // ����ü ������ right ����
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command; // char�� ���� command ����
	int key; // ������ ���� key ����
	Node* head = NULL; // Node������ head���� �� NULL������ �ʱ�ȭ
	Node* ptr = NULL;	/* temp */ // Node������ ptr������ NULL������ �ʱ�ȭ

	do{
        printf("[----- [������] [2022041065] -----]\n");
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); // command �� �Է¹޴´�

		switch(command) {
		case 'z': case 'Z': // command�� z�ų� Z�ΰ��
			initializeBST(&head); // initializeBST �Լ� ȣ�� 
			break;
		case 'q': case 'Q': // command�� q�ų� Q�ΰ��
			freeBST(head); // freeBST �Լ� ȣ�� 
			break;
		case 'n': case 'N': // command�� n�ų� N�ΰ��
			printf("Your Key = ");
			scanf("%d", &key); // key�� �Է�
			insert(head, key); // insert �Լ� ȣ��
			break;
		case 'd': case 'D': // command�� d�ų� D�ΰ��
			printf("Your Key = ");
			scanf("%d", &key); // key�� �Է�
			deleteLeafNode(head, key); // deleteLeafNode�Լ� ȣ�� 
			break;
		case 'f': case 'F': // command�� f�ų� F�ΰ��
			printf("Your Key = ");
			scanf("%d", &key); // key �� �Է�
			ptr = searchIterative(head, key); // serchIterative �Լ��� ȣ������ ptr�� ����
			if(ptr != NULL) // ptr�� NULL���� �ƴϸ� 
				printf("\n node [%d] found at %p\n", ptr->key, ptr);//ptr�� key���� ptr ���
			else// ptr�� NULL���̸�
				printf("\n Cannot find the node [%d]\n", key); // key �� ���
			break;
		case 's': case 'S': // command�� s�ų� S�ΰ��
			printf("Your Key = ");
			scanf("%d", &key); // key �� �Է� 
			ptr = searchRecursive(head->left, key); // serchRecursive �Լ��� ȣ������ ptr�� ����
			if(ptr != NULL) // ptr���� NULL�� �ƴ϶��
				printf("\n node [%d] found at %p\n", ptr->key, ptr); //ptr�� key���� ptr ���
			else// ptr���� NULL�̶��
				printf("\n Cannot find the node [%d]\n", key); // key �� ���
			break;

		case 'i': case 'I': // command�� i�ų� I�ΰ��
			inorderTraversal(head->left); // inorderTraversal�Լ� ȣ�� 
			break;
		case 'p': case 'P': // command�� p�ų� P�ΰ��
			preorderTraversal(head->left); // preorderTraversal�Լ� ȣ��
			break;
		case 't': case 'T': // command�� t�ų� T�ΰ��
			postorderTraversal(head->left); // postorderTraversal�Լ� ȣ�� 
			break;
		default: // command�� �Է°��� ���� ���� �ܿ�
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); // command�� ���� q�� Q �� �ƴ϶�� �ݺ�

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL) 
		freeBST(*h);//Ʈ���� ���������

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node)); //�������� �޸𸮸� �Ҵ��Ͽ� ���ο� ��������
	(*h)->left = NULL;	/* root *///���ο� ������� �����ڽĳ�� NULL�� ����
	(*h)->right = *h; // ���ο� ������� ������ �ڽĳ�带 ����� ��ü�� ����
	(*h)->key = -9999; //������� Ű���� -9999�� ����
	return 1; // 1��ȯ
}


//������ȸ
void inorderTraversal(Node* ptr)
{
	if(ptr) {
		inorderTraversal(ptr->left); // ���� ����Ʈ�� ��ȸ
		printf(" [%d] ", ptr->key); // ���� ����� Ű�� ���
		inorderTraversal(ptr->right); // ������ ����Ʈ�� ��ȸ
	}
}
//������ȸ
void preorderTraversal(Node* ptr)
{
	if(ptr) {
		printf(" [%d] ", ptr->key); // �������� Ű�� ���
		preorderTraversal(ptr->left); //���� ����Ʈ�� ��ȸ
		preorderTraversal(ptr->right); // ������ ����Ʈ�� ��ȸ
	}
}
//������ȸ
void postorderTraversal(Node* ptr)
{
	if(ptr) {
		postorderTraversal(ptr->left); // ���� ����Ʈ�� ��ȸ
		postorderTraversal(ptr->right); // ������ ����Ʈ�� ��ȸ
		printf(" [%d] ", ptr->key); // ���� ����� Ű�� ���
	}
}


int insert(Node* head, int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // newNode�޸𸮸� �������� �Ҵ��Ų��
	newNode->key = key; // newNode�� Ű���� �����Ѵ�
	newNode->left = NULL; // newNode�� left���� NULL�� ����
	newNode->right = NULL; // newNode�� right���� NULL�� ����

	if (head->left == NULL) { // head�� left���� NULL�̶��
		head->left = newNode; // head�� left�� newNode�� ���� 
		return 1;
	}

	/* head->left is the root */
	Node* ptr = head->left; // ptr�� head�� left�� ����

	Node* parentNode = NULL; // parentNode�� NULL���� ����
	while(ptr != NULL) { // ptr���� NULL���� �ƴϸ� �ݺ�

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;
        // ���� ����� Ű�� �Էµ� Ű�� ������ ��� 1�� ��ȯ
		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr; // ptr����parentNode�� ����

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
        
		if(ptr->key < key) //�������� Ű�� �Էµ� Ű���� ������
			ptr = ptr->right; // ������ ����Ʈ���� �̵�
		else//ũ��
			ptr = ptr->left; // ���� ����Ʈ���� �̵�
	}

	/* linking the new node to the parent */
    // �� ���� �θ� ��带 �����մϴ�.
	if(parentNode->key > key) // �������� Ű�� �Էµ� Ű���� ũ��
		parentNode->left = newNode; // parentNode�� left���� newNode�� ���� 
	else//������
		parentNode->right = newNode;// parentNode�� right���� newNode�� ����
	return 1;
}

int deleteLeafNode(Node* head, int key)
{
	if (head == NULL) { // ��尡 NULL�� ��� 
		printf("\n Nothing to delete!!\n");
		return -1; // -1��ȯ
	}

	if (head->left == NULL) { // ����� ���� �ڽ��� NULL�� ���
		printf("\n Nothing to delete!!\n");
		return -1; // -1��ȯ
	}

	/* head->left is the root */
	Node* ptr = head->left; // head�� left���� ptr�� ����


	/* we have to move onto children nodes,
	 * keep tracking the parent using parentNode */
	Node* parentNode = head; // head�� parentNode�� ����

	while(ptr != NULL) { // ptr���� NULL���� �ƴ϶�� 

		if(ptr->key == key) { // ptr�� key���� key ���� �����Ѱ��
			if(ptr->left == NULL && ptr->right == NULL) {
                //ptr�� left���� NULL���̰� ptr�� right ���� NULL�ΰ��
				/* root node case */
				if(parentNode == head) // patentNode���� head�� ������ ���
					head->left = NULL; // head�� left���� NULL������ ����

				/* left node case or right case*/
				if(parentNode->left == ptr) // parentNode�� left���� ptr���� ������ ���
					parentNode->left = NULL; // parentNode�� left ���� NULL������ ����
				else// parentNode�� left���� ptr���� ������ ��� ����
					parentNode->right = NULL; // parentNode�� right ���� NULL������ ����

				free(ptr); // ptr�޸��Ҵ�����
			}
			else {//ptr�� left���� NULL���̰� ptr�� right ���� NULL�ΰ������
				printf("the node [%d] is not a leaf \n", ptr->key);  // ptr�� Ű�� ���
			}
			return 1; // 1��ȯ
		}

		/* keep the parent node */
		parentNode = ptr; // ptr���� parentNode�� ����

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key) // ptr�� key���� �Է¹��� key ������ ������
			ptr = ptr->right; // ptr�� right ���� ptr�� ����
		else//ũ��
			ptr = ptr->left;// ptr�� left ���� ptr�� ����


	}

	printf("Cannot find the node for key [%d]\n ", key); //key�� ���

	return 1;
}

Node* searchRecursive(Node* ptr, int key)
{
	if(ptr == NULL) // ptr�� NULL���̸�
		return NULL; // NULL��ȯ

	if(ptr->key < key) //ptr�� key���� �Է¹��� key ������ ������
		ptr = searchRecursive(ptr->right, key); // serchRecursive�Լ��� ��ȯ���� ptr�� ����
	else if(ptr->key > key)//ptr�� key���� �Է¹��� key ������ ũ��
		ptr = searchRecursive(ptr->left, key); // serchRecursive�Լ��� ��ȯ���� ptr�� ����

	/* if ptr->key == key */
	return ptr; //ptr��ȯ

}
Node* searchIterative(Node* head, int key)
{
	/* root node */
	Node* ptr = head->left; // head�� left���� ptr������

	while(ptr != NULL)
	{
		if(ptr->key == key) // ptr�� key���� �Է¹��� key ���� �����ϴٸ� 
			return ptr; // ptr��ȯ

		if(ptr->key < key) // ptr�� key���� �Է¹��� key������ �۴ٸ�
             ptr = ptr->right; // ptr�� right ���� ptr�� ����
		else
			ptr = ptr->left; // ptr�� left���� ptr�� ����
	}

	return NULL; // NULL��ȯ
}

void freeNode(Node* ptr)
{
	if(ptr) {
		freeNode(ptr->left); // ���� ����Ʈ�� ����
		freeNode(ptr->right); // ������ ����Ʈ�� ����
		free(ptr); // ���� ��� ����
	}
}

int freeBST(Node* head)
{

	if(head->left == head)// ����� ���� �ڽ��� ��� �ڽ��� ���
	{
		free(head); //head�޸��Ҵ�����
		return 1;//1��ȯ
	}

	Node* p = head->left; // head�� left�� p�� ����

	freeNode(p); // freeNode�Լ��� ȣ��

	free(head);//head�޸��Ҵ�����
	return 1;//1��ȯ
}





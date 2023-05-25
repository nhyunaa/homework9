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

typedef struct node { // Node 구조체 정의
	int key; // 정수형 변수 key 선언
	struct node *left; // 구조체 포인터 left선언
	struct node *right; // 구조체 포인터 right 선언
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
	char command; // char형 변수 command 선언
	int key; // 정수형 변수 key 선언
	Node* head = NULL; // Node포인터 head선언 후 NULL값으로 초기화
	Node* ptr = NULL;	/* temp */ // Node포인터 ptr선언후 NULL값으로 초기화

	do{
        printf("[----- [노현아] [2022041065] -----]\n");
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
		scanf(" %c", &command); // command 를 입력받는다

		switch(command) {
		case 'z': case 'Z': // command가 z거나 Z인경우
			initializeBST(&head); // initializeBST 함수 호출 
			break;
		case 'q': case 'Q': // command가 q거나 Q인경우
			freeBST(head); // freeBST 함수 호출 
			break;
		case 'n': case 'N': // command가 n거나 N인경우
			printf("Your Key = ");
			scanf("%d", &key); // key값 입력
			insert(head, key); // insert 함수 호출
			break;
		case 'd': case 'D': // command가 d거나 D인경우
			printf("Your Key = ");
			scanf("%d", &key); // key값 입력
			deleteLeafNode(head, key); // deleteLeafNode함수 호출 
			break;
		case 'f': case 'F': // command가 f거나 F인경우
			printf("Your Key = ");
			scanf("%d", &key); // key 값 입력
			ptr = searchIterative(head, key); // serchIterative 함수의 호출결과를 ptr에 대입
			if(ptr != NULL) // ptr이 NULL값이 아니면 
				printf("\n node [%d] found at %p\n", ptr->key, ptr);//ptr의 key값과 ptr 출력
			else// ptr이 NULL값이면
				printf("\n Cannot find the node [%d]\n", key); // key 값 출력
			break;
		case 's': case 'S': // command가 s거나 S인경우
			printf("Your Key = ");
			scanf("%d", &key); // key 값 입력 
			ptr = searchRecursive(head->left, key); // serchRecursive 함수의 호출결과를 ptr에 대입
			if(ptr != NULL) // ptr값이 NULL이 아니라면
				printf("\n node [%d] found at %p\n", ptr->key, ptr); //ptr의 key값과 ptr 출력
			else// ptr값이 NULL이라면
				printf("\n Cannot find the node [%d]\n", key); // key 값 출력
			break;

		case 'i': case 'I': // command가 i거나 I인경우
			inorderTraversal(head->left); // inorderTraversal함수 호출 
			break;
		case 'p': case 'P': // command가 p거나 P인경우
			preorderTraversal(head->left); // preorderTraversal함수 호출
			break;
		case 't': case 'T': // command가 t거나 T인경우
			postorderTraversal(head->left); // postorderTraversal함수 호출 
			break;
		default: // command의 입력값이 위인 경우들 외에
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); // command의 값이 q나 Q 가 아니라면 반복

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL) 
		freeBST(*h);//트리의 모든노드제거

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node)); //동적으로 메모리를 할당하여 새로운 헤드노드생성
	(*h)->left = NULL;	/* root *///새로운 헤드노드의 왼쪽자식노드 NULL로 설정
	(*h)->right = *h; // 새로운 헤드노드의 오른쪽 자식노드를 헤드노드 자체로 설정
	(*h)->key = -9999; //헤드노드의 키값을 -9999로 설정
	return 1; // 1반환
}


//중위순회
void inorderTraversal(Node* ptr)
{
	if(ptr) {
		inorderTraversal(ptr->left); // 왼쪽 서브트리 순회
		printf(" [%d] ", ptr->key); // 현재 노드의 키값 출력
		inorderTraversal(ptr->right); // 오른쪽 서브트리 순회
	}
}
//전위순회
void preorderTraversal(Node* ptr)
{
	if(ptr) {
		printf(" [%d] ", ptr->key); // 현재노드의 키값 출력
		preorderTraversal(ptr->left); //왼쪽 서브트리 순회
		preorderTraversal(ptr->right); // 오른쪽 서브트리 순회
	}
}
//후위순회
void postorderTraversal(Node* ptr)
{
	if(ptr) {
		postorderTraversal(ptr->left); // 왼쪽 서브트리 순회
		postorderTraversal(ptr->right); // 오른쪽 서브트리 순회
		printf(" [%d] ", ptr->key); // 현재 노드의 키값 출력
	}
}


int insert(Node* head, int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // newNode메모리를 동적으로 할당시킨다
	newNode->key = key; // newNode의 키값을 설정한다
	newNode->left = NULL; // newNode의 left값을 NULL로 대입
	newNode->right = NULL; // newNode의 right값을 NULL로 대입

	if (head->left == NULL) { // head의 left값이 NULL이라면
		head->left = newNode; // head의 left에 newNode를 연결 
		return 1;
	}

	/* head->left is the root */
	Node* ptr = head->left; // ptr에 head의 left를 대입

	Node* parentNode = NULL; // parentNode에 NULL값을 대입
	while(ptr != NULL) { // ptr값이 NULL값이 아니면 반복

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;
        // 현재 노드의 키가 입력된 키와 동일한 경우 1을 반환
		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr; // ptr값을parentNode에 대입

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
        
		if(ptr->key < key) //현재노드의 키가 입력된 키보다 작으면
			ptr = ptr->right; // 오른쪽 서브트리로 이동
		else//크면
			ptr = ptr->left; // 왼쪽 서브트리로 이동
	}

	/* linking the new node to the parent */
    // 새 노드와 부모 노드를 연결합니다.
	if(parentNode->key > key) // 현재노드의 키가 입력된 키보다 크면
		parentNode->left = newNode; // parentNode의 left값에 newNode를 대입 
	else//작으면
		parentNode->right = newNode;// parentNode의 right값에 newNode를 대입
	return 1;
}

int deleteLeafNode(Node* head, int key)
{
	if (head == NULL) { // 헤드가 NULL인 경우 
		printf("\n Nothing to delete!!\n");
		return -1; // -1반환
	}

	if (head->left == NULL) { // 헤드의 왼쪽 자식이 NULL인 경우
		printf("\n Nothing to delete!!\n");
		return -1; // -1반환
	}

	/* head->left is the root */
	Node* ptr = head->left; // head의 left값을 ptr에 대입


	/* we have to move onto children nodes,
	 * keep tracking the parent using parentNode */
	Node* parentNode = head; // head를 parentNode에 대입

	while(ptr != NULL) { // ptr값을 NULL값이 아니라면 

		if(ptr->key == key) { // ptr의 key값과 key 값이 동일한경우
			if(ptr->left == NULL && ptr->right == NULL) {
                //ptr의 left값이 NULL값이고 ptr의 right 값이 NULL인경우
				/* root node case */
				if(parentNode == head) // patentNode값이 head와 동일한 경우
					head->left = NULL; // head의 left값을 NULL값으로 대입

				/* left node case or right case*/
				if(parentNode->left == ptr) // parentNode의 left값과 ptr값이 동일한 경우
					parentNode->left = NULL; // parentNode의 left 값을 NULL값으로 대입
				else// parentNode의 left값과 ptr값이 동일한 경우 제외
					parentNode->right = NULL; // parentNode의 right 값을 NULL값으로 대입

				free(ptr); // ptr메모리할당해제
			}
			else {//ptr의 left값이 NULL값이고 ptr의 right 값이 NULL인경우제외
				printf("the node [%d] is not a leaf \n", ptr->key);  // ptr의 키값 출력
			}
			return 1; // 1반환
		}

		/* keep the parent node */
		parentNode = ptr; // ptr값을 parentNode에 대입

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key) // ptr의 key값이 입력받은 key 값보다 작으면
			ptr = ptr->right; // ptr의 right 값을 ptr에 대입
		else//크면
			ptr = ptr->left;// ptr의 left 값을 ptr에 대입


	}

	printf("Cannot find the node for key [%d]\n ", key); //key값 출력

	return 1;
}

Node* searchRecursive(Node* ptr, int key)
{
	if(ptr == NULL) // ptr이 NULL값이면
		return NULL; // NULL반환

	if(ptr->key < key) //ptr의 key값이 입력받은 key 값보다 작으면
		ptr = searchRecursive(ptr->right, key); // serchRecursive함수의 반환값을 ptr에 대입
	else if(ptr->key > key)//ptr의 key값이 입력받은 key 값보다 크면
		ptr = searchRecursive(ptr->left, key); // serchRecursive함수의 반환값을 ptr에 대입

	/* if ptr->key == key */
	return ptr; //ptr반환

}
Node* searchIterative(Node* head, int key)
{
	/* root node */
	Node* ptr = head->left; // head의 left값을 ptr에대입

	while(ptr != NULL)
	{
		if(ptr->key == key) // ptr의 key값과 입력받은 key 값이 동일하다면 
			return ptr; // ptr반환

		if(ptr->key < key) // ptr의 key값이 입력받은 key값보다 작다면
             ptr = ptr->right; // ptr의 right 값을 ptr에 대입
		else
			ptr = ptr->left; // ptr의 left값을 ptr에 대입
	}

	return NULL; // NULL반환
}

void freeNode(Node* ptr)
{
	if(ptr) {
		freeNode(ptr->left); // 왼쪽 서브트리 해제
		freeNode(ptr->right); // 오른쪽 서브트리 해제
		free(ptr); // 현재 노드 해제
	}
}

int freeBST(Node* head)
{

	if(head->left == head)// 헤드의 왼쪽 자식이 헤드 자신인 경우
	{
		free(head); //head메모리할당해제
		return 1;//1반환
	}

	Node* p = head->left; // head의 left를 p에 대입

	freeNode(p); // freeNode함수를 호출

	free(head);//head메모리할당해제
	return 1;//1반환
}





////////////////////////////
// Samples on linked list //
////////////////////////////

#include<stdio.h>
#include<stdlib.h>

// ประกาศโครงสร้างข้อมูลของ linked list node ในชื่อ NODE
typedef struct Node{
	char Info;
	struct Node *Next;
} TYPE_NODE;

// ประกาศโครงสร้างของ Node pointer ในชื่อ TYPE_NODE_PTR
typedef struct Node *TYPE_NODEPTR;

// ประกาศฟังก์ชั่นสำหรับสร้าง node ใหม่ ส่งคืน datatype NODE
TYPE_NODEPTR newNode(char item){
	// ประกาศ Pointer ของ node เปล่าๆ
	// (พอเป็น pointer เปล่าคือเปล่าจริง ไม่มีอะไรเลย ไม่มีแม้แต่พื้นที่)
	TYPE_NODEPTR node;
	// กันพื้นที่ของ Node ไว้ให้เท่ากับขนาดของ NODE หนึ่งตัว
	node = (TYPE_NODEPTR) malloc(sizeof(TYPE_NODE));
	node -> Info = item;
	node -> Next = NULL;
	return node;
}

// ฟังก์ชั่นสำหรับเคลียร์ค่าใน node ทิ้ง
void freeNode(TYPE_NODEPTR node){
	// free เป็นคำสั่งมาตรฐานที่จะเคลียร์ค่าที่ allocate ไว้ทิ้ง
	// กูเกิลว่า C free command ประกอบก็ได้
	// !! ต้องใช้ stdlib.h !!
	free(node);
}

// เมื่อมี Pointer `list` ที่ชี้ไปยัง node ตัวแรก*
// ให้สร้าง node ใหม่แล้วเอาไปแทรกไว้ก่อน node ตัวแรก
// โดยให้ค่าของ node ใหม่ที่ใส่ไป เท่ากับตัวแปร item ที่รับมาจากฟังก์ชั่น
// 
// * เป็น pointer ของ node pointer
// ในการเขียน datatype ของ node เราจะไม่สนใจ node จริงๆ ว่าอยู่ไหน
// และจะพิจารณาเพียง pointer ที่ชี้ไปยัง node ตัวแรกเท่านั้น
void insertAtFirst(TYPE_NODEPTR *list, char item){
	// สร้าง node ใหม่
	TYPE_NODEPTR new;
	// ให้ node ใหม่มีค่าที่เก็บใน node เท่ากับ item
	new = newNode(item);
	// ให้ช่อง Next ของ node ใหม่ชี้ไปที่ node ก้อนเดิม
	new -> Next = *list;
	// และแก้ค่า list ซึ่งส่งมาเป็น pointer ให้ชี้ไปที่ node ตัวใหม่ของเรา
	*list = new;
}

// ใส่ node ใหม่ไว้ "หลัง" โหนดที่ถูกชี้โดย point
void insertAfter(TYPE_NODEPTR point, char item){
}

int main(){
	TYPE_NODEPTR myNodePtr = newNode('c');
	printf("%c\n", myNodePtr -> Info);
	insertAtFirst(&myNodePtr, 'b');
	printf("%c\n", myNodePtr -> Info);
	insertAtFirst(&myNodePtr, 'a');
	printf("%c\n", myNodePtr -> Info);
	return 0;
}

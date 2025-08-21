#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* createNode(int value);
void display(struct Node* head);
void insertBeforeNumber(struct Node** head, int newValue, int targetValue);
void insertAfterNumber(struct Node* head, int newValue, int targetValue);
void deleteNode(struct Node** head, int targetValue);
void reverseList(struct Node** head);
void sortList(struct Node** head);
void deleteAlternateNodes(struct Node** head);
void insertSorted(struct Node** head, int value);
struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
return newNode;
}
void display(struct Node* head) {
if (head == NULL) {
printf("List is empty.\n");
return;
}
struct Node* current = head;
while (current != NULL) {
printf("%d -> ", current->data);
current = current->next;
}
printf("NULL\n");
}
void insertBeforeNumber(struct Node** head, int newValue, int targetValue) {
struct Node* newNode = createNode(newValue);
if (*head == NULL) {
printf("List is empty.\n");
free(newNode);
return;
}
if ((*head)->data == targetValue) {
newNode->next = *head;
*head = newNode;
return;
}
struct Node* prev = NULL;
struct Node* curr = *head;
while (curr != NULL && curr->data != targetValue) {
prev = curr;
curr = curr->next;
}
if (curr == NULL) {
printf("Value %d not found.\n", targetValue);
free(newNode);
return;
}
prev->next = newNode;
newNode->next = curr;
}
void insertAfterNumber(struct Node* head, int newValue, int targetValue) {
struct Node* curr = head;
while (curr != NULL && curr->data != targetValue) {
curr = curr->next;
}
if (curr == NULL) {
printf("Value %d not found.\n", targetValue);
return;
}
struct Node* newNode = createNode(newValue);
newNode->next = curr->next;
curr->next = newNode;
}
void deleteNode(struct Node** head, int targetValue) {
if (*head == NULL) {
printf("List is empty.\n");
return;
}
struct Node* temp = *head;
if ((*head)->data == targetValue) {
*head = (*head)->next;
free(temp);
return;
}
struct Node* prev = NULL;
while (temp != NULL && temp->data != targetValue) {
prev = temp;
temp = temp->next;
}
if (temp == NULL) {
printf("Value %d not found.\n", targetValue);
return;
}
prev->next = temp->next;
free(temp);
}
void reverseList(struct Node** head) {
struct Node* prev = NULL;
struct Node* curr = *head;
struct Node* next = NULL;
while (curr != NULL) {
next = curr->next;
curr->next = prev;
prev = curr;
curr = next;
}
*head = prev;
}
void sortList(struct Node** head) {
if (*head == NULL) return;
struct Node* i = *head;
struct Node* j;
int tempData;
while (i != NULL) {
j = i->next;
while (j != NULL) {
if (i->data > j->data) {
tempData = i->data;
i->data = j->data;
j->data = tempData;
}
j = j->next;
}
i = i->next;
}
}
void deleteAlternateNodes(struct Node** head) {
if (*head == NULL) return;
struct Node* curr = *head;
struct Node* temp;
while (curr != NULL && curr->next != NULL) {
temp = curr->next;
curr->next = temp->next;
free(temp);
curr = curr->next;
}
}
void insertSorted(struct Node** head, int value) {
struct Node* newNode = createNode(value);
if (*head == NULL || (*head)->data >= value) {
newNode->next = *head;
*head = newNode;
return;
}
struct Node* curr = *head;
while (curr->next != NULL && curr->next->data < value) {
curr = curr->next;
}
newNode->next = curr->next;
curr->next = newNode;
}
int main() {
struct Node* head = NULL;
struct Node* temp = NULL;
int n, val, target, choice;
printf("Vidhan Sachdeva\n");
printf("Reg No : 240968030\n");
printf("Roll No.: 7\n");
printf("Enter number of nodes: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
printf("Enter value for node %d: ", i + 1);
scanf("%d", &val);
temp = createNode(val);
if (head == NULL) {
head = temp;
} else {
struct Node* curr = head;
while (curr->next != NULL)
curr = curr->next;
curr->next = temp;
}
}
printf("Initial Linked List: ");
display(head);
while (1) {
printf("\n--- Menu ---\n");
printf("1. Insert before a specified element\n");
printf("2. Insert after a specified element\n");
printf("3. Delete a specified element\n");
printf("4. Display list\n");
printf("5. Reverse list\n");
printf("6. Sort list (Ascending)\n");
printf("7. Delete alternate nodes\n");
printf("8. Insert into sorted list\n");
printf("9. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to insert: ");
scanf("%d", &val);
printf("Enter value before which to insert: ");
scanf("%d", &target);
insertBeforeNumber(&head, val, target);
break;
case 2:
printf("Enter value to insert: ");
scanf("%d", &val);
printf("Enter value after which to insert: ");
scanf("%d", &target);
insertAfterNumber(head, val, target);
break;
case 3:
printf("Enter value to delete: ");
scanf("%d", &target);
deleteNode(&head, target);
break;
case 4:
display(head);
break;
case 5:
reverseList(&head);
printf("List reversed.\n");
break;
case 6:
sortList(&head);
printf("List sorted.\n");
break;
case 7:
deleteAlternateNodes(&head);
printf("Alternate nodes deleted.\n");
break;
case 8:
printf("Enter value to insert into sorted list: ");
scanf("%d", &val);
insertSorted(&head, val);
break;
case 9:
printf("Exiting...\n");
exit(0);
default:
printf("Invalid choice.\n");
}
}
return 0;
}
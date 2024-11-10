# Vectors Cheat Sheet

## Creating new linkedlist(containing 1 to 10)
```c++
int i = 1;
ListNode* head = new ListNode(i); // Dynamically allocate memory for head
ListNode* current = head;         // Create a pointer to traverse the list
//or
ListNode head(i);           // Create head as a `ListNode` object on the stack
ListNode* current = &head;  // Create a pointer to traverse the list


while (i <= 10) {
  current->next = new ListNode(i);
  current = current->next;
  i++;
}
```

## Traversing through linkedlist(calculating sum)
```c++
int sum = 0;
ListNode* temp = head;
while(temp!=nullptr){
  int val = temp->val; 
  sum += val;
  temp = temp->next;
}
```


## Reversing a linkedlist
```c++
        if (head == NULL || head->next == NULL)return head;
        
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr != NULL){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
```

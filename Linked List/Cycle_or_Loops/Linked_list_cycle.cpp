

// bool checkCycle(Node* head){  // Tortoise & Hare algorithm
//     Node* slow = head;
//     Node* fast = head;

//     while(fast != NULL){
//         fast = fast->next;
//         if(fast->next != NULL){
//             fast = fast->next;
//             slow = slow->next;
//         }
//         if(fast == slow){
//         return true;
//         }
//     }
//     return false;
// }

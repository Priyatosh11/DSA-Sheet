//Approach using slow fast pointer
//T.C. = O(N);
//S.C. = O(N);

void splitCircularList(Node *head)
{
    // Write your code here.
    Node* slow=head;
    Node* fast=slow->next;
    while (head!=fast && fast->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
   Node *head1_ref = head;
   Node *head2_ref = slow->next;
    slow->next = head1_ref;
    Node *current = head2_ref;
    while (current -> next != head){
        current = current->next;
    }
    
    current->next = head2_ref;

}

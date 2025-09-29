#include "e1B.h"

unsigned char check(mossa* head)
{
    unsigned char count = 0;
    unsigned char correct = 0;
    
    
    while (head) {
        count++;
        if (is_valid_move(head))
            correct++;
        head = head->next;
    }
    return (count == correct)? 1 : 0;
}

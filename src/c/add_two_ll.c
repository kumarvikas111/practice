/* Question: 
  ou are given two non-empty linked lists representing two non-negative integers. 
  The digits are stored in reverse order and each of their nodes contain a single digit.
  Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
i/p: 1->8 + 0
o/p: 1->8
81 + 0 = 81

*/


/**
  * This code is soluton of leet code.Need to optimise the code.
  * run time is 20ms.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define REV_CODE 0

static struct ListNode* rev_ll(struct ListNode* ll){
    
    if( NULL == ll){
        return NULL;
    }
    struct ListNode * prev = NULL;
    struct ListNode * curr = ll;
    struct ListNode * next = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
    
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    int base = 10;
    int flag = 0;
    
    if ( l2 == NULL && l1 == NULL){
        return NULL;
    }else if (l2 == NULL && l1 != NULL){
        return rev_ll(l1);
    }else if (l2 != NULL && l1 == NULL){
        return rev_ll(l2);
    }    
 
    struct ListNode* rl1 = NULL;
    struct ListNode* rl2 = NULL;

#if REV_CODE
    rl1 = rev_ll(l1);
    rl2 = rev_ll(l2);
#else
    rl1 = l1;
    rl2 = l2;
#endif

    if (rl2 != NULL && rl1 != NULL){
        flag = 3;
    }else if (rl2 == NULL && rl1 != NULL){
        flag = 2;
    }else if (rl2 != NULL && rl1 == NULL){
        flag = 1;
    }else{
        flag = 0;
        return NULL;
    }
     printf(" Switch Case: %d \n",flag);
    struct  ListNode * result = NULL;
    struct ListNode * saveResultHead = NULL;
    int sum = 0;
    int carry = 0;

    do{
        struct  ListNode * res = (struct  ListNode *) malloc(sizeof(struct ListNode));
        
        if(NULL == res){ 
            printf("error in memory allocation."); 
            return NULL;
        }
        res->next = result;
        
        switch (flag){
            case 1:
                sum = carry + rl2->val;
                if (sum >= base){
                    res->val = (sum%base);                  
                }else {
                    res->val = sum;
                }
                carry = sum/base;
                rl2 = rl2->next;
                break;
            case 2:
                sum = carry + rl1->val;
                if (sum >= base){
                    res->val = (sum%base);                    
                }else {
                    res->val = sum;
                }
                carry = sum/base;
                rl1 = rl1->next;
                break;
            case 3:
                sum = carry + rl1->val + rl2->val;
                if (sum >= base){
                    res->val = (sum%base);                  
                }else {
                    res->val = sum;
                }
                carry = sum/base;
                rl2 = rl2->next;
                rl1 = rl1->next;
                break;
            case 4:
                sum = carry ;
                if (sum >= base){
                    printf("carry %d is graeater than base %d",carry, base);
                }else {
                    res->val = sum;
                    carry = 0;
                }
                break;
            default:
                printf("error");
                flag = 0; 
                break;
        }
         
        if (rl2 != NULL && rl1 != NULL){
            flag = 3;
        }else if (rl2 == NULL && rl1 != NULL){
            flag = 2;
        }else if (rl2 != NULL && rl1 == NULL){
            flag = 1;
        }else{
            if(carry <= 0){
               flag = 0; 
            }else{
               flag = 4;
            }
        }     
        result = res;
        if(saveResultHead == NULL){
            saveResultHead = result;           
        }
        //result = result->next;
        printf(" %4d Switch Case: %d \n",__LINE__,flag);
    }while(flag);

#if REV_CODE
    return (result);
#else
    return rev_ll(result);
#endif
    
}

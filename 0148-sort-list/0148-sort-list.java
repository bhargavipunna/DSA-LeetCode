/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode mid = getmid(head);
        ListNode l = sortList(head);
        ListNode r = sortList(mid);

        return merge(l,r);
    }
    ListNode getmid(ListNode head){
        ListNode prev = null;
        while(head!=null && head.next!=null){
            prev = (prev == null)? head : prev.next;
            head = head.next.next;
        }
        ListNode mid = prev.next;
        prev.next = null;
        return mid;
    }
    ListNode merge(ListNode l,ListNode r){
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while(l!=null && r!=null){
            if(l.val<r.val){
                tail.next = l;
                l = l.next;
            }
            else{
                tail.next = r;
                r = r.next;
            }
            tail = tail.next;
        }
        tail.next = (l!=null)?l:r;
        return dummy.next;
    }
}
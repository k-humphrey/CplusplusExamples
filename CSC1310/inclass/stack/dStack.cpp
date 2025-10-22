class dStack{
    private:
            struct ListNode{
                int value;
                ListNode* next;
            };
            ListNode* top;
    public:
            //add to the top of the stack
            void append(int num){
                ListNode *newNode; // make a pointer to the newnode

                //allocate a new node and store number here
                newNode = new ListNode;
                newNode->value = num;
                newNode->next = top;

                top = newNode;
            }
            //pop has an edge case see if empty, have to use delete
            //peek has an edge case if empty

};
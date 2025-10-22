class sStack{
    private:
            int* stackArray;
            int size;
            int top;

    public:
            sStack(int s){
                stackArray = new int[s];
                size = 0;
                top = 0;
            }
            ~sStack(){
                delete [] stackArray;
            }
            //add to the top if not full
            bool push(int value){
                if(top + 1 == size){
                    //stack is full
                    return false;
                }
                else{
                    //stack is not full
                    top++;
                    stackArray[top] = value;
                    return true;
                }
            }
            //remove the top and set parameter to the removed value
            bool pop(int& remove){
                if(top == -1){
                    //top is empty
                    return false;
                }
                else{
                    //top is not empty, remove one
                    remove = stackArray[top];
                    top--;
                    return true;
                }
            }
            
            //return top, maybe change to be a bool
            int peek(){
                return stackArray[top];
            }
};
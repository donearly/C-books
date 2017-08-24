void PostOrder_Nonrecursive(BiTree T)  // 后序遍历的非递归     双栈法    
{      
    stack<BiTree> s1 , s2;      
    BiTree curr ;           // 指向当前要检查的节点    
    s1.push(T);    
    while(!s1.empty())  // 栈空时结束      
    {    
        curr = s1.top();    
        s1.pop();    
        s2.push(curr);    
        if(curr->lchild)    
            s1.push(curr->lchild);    
        if(curr->rchild)    
            s1.push(curr->rchild);    
    }    
    while(!s2.empty())    
    {    
        printf("%c ", s2.top()->data);    
        s2.pop();    
    }    
}    

void InOrderTraverse1(BiTree T)   // 中序遍历的非递归    
{    
    if(!T)    
        return ;    
    BiTree curr = T;    // 指向当前要检查的节点    
    stack<BiTree> s;  
    while(curr != NULL || !s.empty())  
    {  
        while(curr != NULL)  
        {  
            s.push(curr);  
            curr = curr->lchild;  
        }//while  
        if(!s.empty())  
        {  
            curr = s.top();  
            s.pop();  
            cout<<curr->data<<"  ";  
            curr = curr->rchild;  
        }  
    }  
}  

void PreOrder_Nonrecursive1(BiTree T)     //先序遍历的非递归   
{  
    if(!T)    
        return ;  
    stack<BiTree> s;  
    BiTree curr = T;  
    while(curr != NULL || !s.empty())  
    {  
        while(curr != NULL)  
        {  
            cout<<curr->data<<"  ";  
            s.push(curr);  
            curr = curr->lchild;  
        }  
        if(!s.empty())  
        {  
            curr = s.top();  
            s.pop();  
            curr = curr->rchild;  
        }  
    }  
}  



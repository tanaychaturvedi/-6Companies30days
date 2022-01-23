void linkdelete(struct Node  *head, int M, int N)
    {
        
        if(!head) return;
        
        Node *curr = nullptr;
        int cnt = 0;
        
        do{
            curr = (curr == nullptr) ? head : curr->next;
            cnt++;
        }while(curr and cnt<M);
        
        if(!curr || !curr->next) {return;}
        
        // cout<<(curr->data)<<"\n";
        
        Node *next = curr;
        cnt = 0;
        while(next and cnt < N)
        {
            next = next->next;
            cnt++;
        }
        
        curr->next = !next or !next->next ? nullptr : next->next;
        
        linkdelete(curr->next,M,N);
        
        
    }
void insert(int n){
    
    Trie *temp = root;
    for(int i=31;i>=0;i--){
        
        int x = ((1<<i)&n)?1:0;
        if(temp->child[x]==NULL)
            temp->child[x] = new Trie();
        temp = temp->child[x];
        temp->count++;
    }//i
}//insert

int query(int n,int high){
        
    Trie *temp = root;
    int sum=0;
    
    for(int i=31;i>=0;i--){
        
        int x = ((1<<i)&n)?1:0;
        int y = ((1<<i)&high)?1:0;
        
        if(y==1){
            
            if(x==0 || x==1){
                if(temp->child[x]!=NULL){  //conditon for smaller
                    sum+=temp->child[x]->count; //add all smaller numbers
                }
                if(temp->child[1-x]!=NULL) 
                    temp = temp->child[1-x]; //conditon for equal
                else
                    break;
            }
        }//if
        else{
            
            if(x==0 || x==1){ // conditon for equal
               if(temp->child[x]!=NULL) // conditon for equal
                    temp = temp->child[x];
                else 
                    break; //It becomes greater than high so retrun 0
            }
            
        }//else
    }//i
 
        return sum;
    
}


int countPairs(vector<int>& a, int low, int high) {
    
      int i,j,n=a.size(); 
      int res=0;
       
      insert(a[n-1]);
     for(i=n-2;i>=0;i--){
         
         int tmp1= query(a[i],high+1);
         int tmp2 = query(a[i],low);
         //cout<<tmp1<<" "<<tmp2<<"\n";
         
         res+=tmp1-tmp2;
         insert(a[i]);
     }//i
    
    return res;
}
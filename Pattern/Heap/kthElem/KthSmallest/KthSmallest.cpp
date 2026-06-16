int kthSmallest(int n,int k,vector<int> Arr)
{

    priority_queue<int>pq;
for(int i=0;i<k;i++){
pq.push(Arr[i]);
}

   for(int i=k;i<n;i++){
       if(Arr[i]<pq.top()){
           pq.pop();
           pq.push(Arr[i]);
       }
   } 
   return pq.top();
}

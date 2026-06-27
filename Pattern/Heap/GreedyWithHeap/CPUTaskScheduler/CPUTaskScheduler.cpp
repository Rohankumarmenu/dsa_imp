

struct Task{
    int frequency;
    int executionTime;

    Task(int freq,int executionTime) {
        frequency=freq;
        executionTime=executionTime;
    }
};

struct TaskComp{

    bool operator()(const Task &a,const Task &b){
      return a.frequency<b.frequency;
    }
};




class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
    //    queue<pair<int,int>>q;
        priority_queue<Task,vector<Task>,TaskComp>pq;
        unordered_map<char,int>umap;

        for(auto i:tasks){
            umap[i]++;
        }

        for(auto& i:umap){
            // pq.push({umap.second,umap.first});
            int freq=i.second;
            pq.push(Task(freq,0));
        }

        queue<Task>q;
        int time=0;

        while(!q.empty()||!pq.empty()){
            time++;
            if(!pq.empty()){
              Task task=pq.top();

              pq.pop();
              task.frequency--;

              if(task.frequency>0){
                task.executionTime=time+n;
                q.push(task);
              }
            }
        //   pq.pop();
        //   int newFq=pq.first--;
        //   int exeTime=time+n;

        // q.push(Task(newFq,exeTime));

        if(!q.empty()&& time==q.front().executionTime){
             pq.push((q.front()));
             q.pop();
        }

        }
return time;
    }
};
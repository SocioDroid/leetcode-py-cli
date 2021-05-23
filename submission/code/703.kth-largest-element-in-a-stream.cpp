class KthLargest {
public:
    vector<int> heap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        for(int i: nums)
            cout<<add(i)<<endl;
    }
    
    int add(int val) {
        if(heap.size() < k){
            heap.push_back(val);
            heapify_bottom(heap.size() - 1);

        }
        else if(heap[0] < val)
        {
            heap[0] = val;
            heapify(0);
            
        }
        return heap[0];
    }
    
    void heapify(int i){
        if(i > heap.size())
            return;
            
        int max_index = i;
        int lc = (2*i) + 1;
        int rc = (2*i) + 2;
        
        if(lc < heap.size() && heap[lc] < heap[max_index])
            max_index = lc;
        
        
        if(rc < heap.size() && heap[rc] < heap[max_index])
            max_index = rc;
        
        
        if(max_index != i){
            swap(heap[i], heap[max_index]);
            heapify(max_index);
        }
        return;
    }
    void heapify_bottom(int i){
        int parent = (i-1)/2;
        
        
        if(parent > -1 && heap[parent] > heap[i]){
            swap(heap[parent], heap[i]);
            heapify_bottom(parent);
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
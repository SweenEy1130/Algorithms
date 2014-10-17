void mergesort(int m[]){
   int [] left, right, result
   if length(m) ≤ 1
       return m
   else
       var middle = length(m) / 2
       for each x in m up to middle - 1
           add x to left
       for each x in m at and after middle
           add x to right
       left = mergesort(left)
       right = mergesort(right)
       result = merge(left, right)
       return result
}

void merge(vector<int> left, vector<int> right){
    vector<int> result;
    while (left.size() > 0 && right.size() > 0)
        if (left[0] ≤ right[0]){
          result.push_back(left[0]);
          left.erase(left.begin());
        }else{
          result.push_back(right[0]);
          right.erase(right.begin());
        }
   if (left.size() > 0)
       append rest(left) to result
   if (right.size() > 0)
       append rest(right) to result
   return result
}
**选择排序**

- 注意需要选择多少轮?`(n-1)`轮
- 每轮从哪个位置开始选择?第`i`轮从第`i+1`开始,到`n-1`结束
- 记录每一轮的最小元素的下标,不要忘记交换位置
```cpp
void selectSort(vector<int> &nums){
    int n=nums.size();  //假设n=10
    int round=n-1; //需要选择9轮，n个元素需要(n-1)轮选择，第n轮选择只有最后一个元素
    int minIndex=-1;    
    for (size_t i = 0; i < round; i++) {//i=0,1,2,3,4,5,6,7,8
        minIndex=i;
        for (size_t j = i+1; j < n; j++) { //第i轮选择下标范围[i+1,n-1]
            if(nums[minIndex]>nums[j]) //记录较小值的index
                minIndex=j; //更新minIndex
        }
        swap(nums[i],nums[minIndex]);//选择最小的交换
    }
}
```
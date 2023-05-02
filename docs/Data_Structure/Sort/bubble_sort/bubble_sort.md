**冒泡排序**

- `n`个元素需要比较`n-1`轮
- 轮次`round=n-1`
- 第`i`轮比较需要比较`round-i`次
```cpp
void bubleSort(vector<int> &nums){
    int n=nums.size();  //数组长度
    int round=n-1;  //总共需要比较的轮次，2个数1轮，3个数2轮，n个数(n-1)轮
    for (size_t i = 0; i < round; i++) { //比较round轮，i=[0,1,2,round-1]
        for (size_t j = 0; j < round-i; j++) {    //第i轮比较(round-i)次
            if(nums[j]>nums[j+1])
                swap(nums[j],nums[j+1]);
        }
    }
}
```